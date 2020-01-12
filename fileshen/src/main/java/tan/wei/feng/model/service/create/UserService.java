package tan.wei.feng.model.service.create;

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
import tan.wei.feng.model.mapper.UserMapper;
import tan.wei.feng.utils.JwtUtil;
import tan.wei.feng.utils.SmsUtil;

/**
 * 用户服务
 * @author 1015956962@163.com
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
	
	private static final Random RAND = new Random();
	
	/**
	 * 短信验证码
	 * @param mobile
	 */
	public boolean sendSms(String mobile) {
		// 1.生成6位短信验证码
		Integer code = 100000 + RAND.nextInt(900000);
		// 2.将验证码放入redis,5分钟过期
		redisTemplate.opsForValue().set("smscode_" + mobile, code.toString(),5,TimeUnit.MINUTES);
		// 3.将验证码和手机号用smsutil发送
		logger.info(code.toString());
		//调用短信工具类
		return smsUtil.sendSms(mobile,code);
	}
	
	/**
	 * 根据手机号和密码登录
	 * @param mobile
	 * @param password
	 * @return
	 */
	public Map<String, String> findByMobileAndPassword(String mobile, String password) {
		User user = userMapper.findByMobile(mobile); 
		Map<String, String> map=new HashMap<>(3);
		BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();
		if(user!=null&&encoder.matches(password, user.getPassword())) {
			// 生成token 
			String token = JwtUtil.getJwt().createJsonWebToken(user.getId().toString(),user.getMobile(), "user");
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
	
	/**
	 *  根据id查询
	 * @param id
	 * @return
	 */
	public User findById(String id) {
		return userMapper.selectByPrimaryKey("User",Long.parseLong(id)) ;
	}
	
	public List<User> findAll(){
		return userMapper.selectAll("User",0,10);
	}
	
}
