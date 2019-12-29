package tan.wei.feng.service.create;

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

import tan.wei.feng.entity.User;
import tan.wei.feng.mapper.UserMapper;
import tan.wei.feng.utils.JwtUtil;

/**
 * 用户服务
 * @author 锋什么
 *
 */
@Service
public class UserService {
	
	private static final Logger logger = LoggerFactory.getLogger(UserService.class);
	
	
	private final UserMapper userMapper ;
	private final RedisTemplate<String,String> redisTemplate;
	private final JwtUtil jwtUtil;
	private final BCryptPasswordEncoder encoder;
	
	@Autowired
	public UserService(UserMapper userMapper, RedisTemplate<String, String> redisTemplate,
			BCryptPasswordEncoder encoder,JwtUtil jwtUtil) {
		this.userMapper = userMapper;
		this.redisTemplate = redisTemplate;
		this.encoder = encoder;
		this.jwtUtil = jwtUtil;
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
		Map<String, String> map = new HashMap<String, String>();
		map.put("mobile", mobile);
		map.put("code", code.toString());
		logger.info(map.toString());
		//调用短信工具类
		//SmsUtil smsUtil = new SmsUtil();
		//smsUtil.sendSms(map);
		
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
		if(user!=null&&encoder.matches(password, user.getPassword())) {
			// 生成token 
			String token = jwtUtil.createJWT(user.getUserid().toString(),user.getMobile(), "user");
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
