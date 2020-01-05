package tan.wei.feng.service.create;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.User;
import tan.wei.feng.mapper.UserMapper;
import tan.wei.feng.utils.JwtUtil;
import tan.wei.feng.utils.SmsUtil;

/**
 * 用户服务
 * @author 锋什么
 *
 */
@Service
public class UserService {
	
	private static final Logger logger = LoggerFactory.getLogger(UserService.class);
	
	@Autowired
	private UserMapper userMapper = null;
	@Autowired
	private RedisTemplate<String,String> redisTemplate = null;
	@Autowired
	private SmsUtil smsUtil = null;
	
	private static final Random rand = new Random();
	
	/**
	 * 短信验证码
	 * @param mobile
	 */
	public boolean sendSms(String mobile) {
		// 1.生成6位短信验证码
		Integer code = 100000 + rand.nextInt(900000);
		// 2.将验证码放入redis,5分钟过期
		redisTemplate.opsForValue().set("smscode_"+mobile, code.toString(),5,TimeUnit.MINUTES);
		// 3.将验证码和手机号用smsutil发送
		Map<String, String> map = new HashMap<>();
		map.put("mobile", mobile);
		map.put("code", code.toString());
		logger.info(mobile+code);
		//调用短信工具类
		return smsUtil.sendSms(map);
		
	}
	
	/**
	 * 根据手机号和密码登录
	 * @param mobile
	 * @param password
	 * @return
	 */
	public Map<String, String> findByMobileAndPassword(String mobile, String password) {
		User user = userMapper.findByMobile(mobile); 
		Map<String, String> map=new HashMap<>();
		BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();
		if(user!=null&&encoder.matches(password, user.getPassword())) {
			// 生成token 
			String token = new JwtUtil().createJWT(user.getUserid().toString(),user.getMobile(), "user");
			map.put("token",token);
			//昵称
			map.put("name",user.getNickname());
			// 返回token，昵称，头像等信息
			return map;
		}else {
			map.put("message","密码或者账号错误");
			return map;
		}
	}
	
	// 根据id查询
	public User findById(String id) {
		return userMapper.findById(Long.parseLong(id)).get() ;
	}
	
	public List<User> findAll(){
		return userMapper.findAll();
	}
	
}
