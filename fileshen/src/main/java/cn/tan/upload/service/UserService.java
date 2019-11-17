package cn.tan.upload.service;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

import org.apache.commons.math3.random.RandomDataGenerator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.User;
import cn.tan.upload.mapper.UserMapper;
import cn.tan.upload.utils.JwtUtil;
import cn.tan.upload.utils.SmsUtil;

@Service
public class UserService {
	
	private static final Logger logger = LoggerFactory.getLogger(UserService.class);
	
	private final UserMapper userMapper ;
	private final RedisTemplate<String,String> redisTemplate;
	private final SmsUtil smsUtil;
	private final JwtUtil jwtUtil;
	private final BCryptPasswordEncoder encoder;
	
	@Autowired
	public UserService(UserMapper userMapper, RedisTemplate<String, String> redisTemplate, SmsUtil smsUtil,
			BCryptPasswordEncoder encoder,JwtUtil jwtUtil) {
		this.userMapper = userMapper;
		this.redisTemplate = redisTemplate;
		this.smsUtil = smsUtil;
		this.encoder = encoder;
		this.jwtUtil = jwtUtil;
	}

	
	
	/**
	 * 保存用户信息,注册
	 * @param user
	 */
	public synchronized boolean saveUser(User user) {
		user.setUserid(IdUtil.createSnowflake(1, 1).nextIdStr());
		Date date = new Date();
		user.setCreation_time(date);
		user.setUpdate_time(date);
		// 密码加密
		String newpassword = encoder.encode(user.getPassword());
		user.setPassword(newpassword);
		// 保存用户
		try {
			userMapper.save(user);
			return true ;
		} catch (Exception e) {
			userMapper.deleteById(user.getUserid());
			return false;
		}
		
	}
	
	/**
	 * 短信验证码
	 * @param mobile
	 */
	public void sendSms(String mobile) {
		// 1.生成6位短信验证码
		RandomDataGenerator randomDataGenerator = new RandomDataGenerator();
		//最大数
		int max = 999999;
		// 最小数
		int min = 100000;
		//随机生成
		Integer code = randomDataGenerator.nextInt(min, max);
		// 2.将验证码放入redis,5分钟过期
		redisTemplate.opsForValue().set("smscode_"+mobile, code.toString(),5,TimeUnit.MINUTES);
		// 3.将验证码和手机号用smsutil发送
		Map<String, String> map = new HashMap<>();
		map.put("mobile", mobile);
		map.put("code", code.toString());
		logger.debug(map.toString());
		//调用短信工具类
		smsUtil.sendSms(map);
	}
	
	/**
	 * 根据手机号和密码登录
	 * @param mobile
	 * @param password
	 * @return
	 */
	public Map<String, String> findByMobileAndPassword(String mobile, String password) {
		User user = userMapper.findByMobile(mobile); 
		if(user!=null&&encoder.matches(password, user.getPassword())) {
			// 生成token 
			String token = jwtUtil.createJWT(user.getUserid(),user.getMobile(), "user");
			HashMap<String, String> map=new HashMap<>();
			map.put("token",token);
			//昵称
			map.put("name",user.getNickname());
			// 将用户id放入redis,60分钟过期
			redisTemplate.opsForValue().set("userid_"+user.getUserid(), user.getMobile(),60,TimeUnit.MINUTES);
			// 返回token，昵称，头像等信息
			return map;
		}else {
			return null;
		}
	}
	
	// 根据id查询
	public User findById(String id) {
		return userMapper.findById(id).get() ;
	}
	
	public List<User> findAll(){
		return userMapper.findAll();
	}
	
}
