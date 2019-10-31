package cn.tan.upload.service;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.TimeUnit;

import org.apache.commons.math3.random.RandomDataGenerator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Example;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import cn.hutool.core.lang.Snowflake;
import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.User;
import cn.tan.upload.mapper.UserMapper;
import cn.tan.upload.utils.SmsUtil;

@Service
public class UserService {
	
	@Autowired
	private UserMapper userMapper;
	
	@Autowired
	private RedisTemplate<String,String> redisTemplate;
	
	@Autowired
	private SmsUtil smsUtil;
	
	@Autowired
	private BCryptPasswordEncoder encoder;
	
	@Autowired
	private User user;
	
	//参数1为终端ID,参数2为数据中心ID
	Snowflake snowflake = IdUtil.createSnowflake(1, 1);
	/**
	 * 保存用户信息,注册
	 * @param user
	 */
	public synchronized boolean saveUser(User user) {
		user.setUserid(snowflake.nextIdStr());
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
		//Integer code = randomDataGenerator.nextInt(min, max);
		Integer code = 123456; //测试用
		// 2.将验证码放入redis,5分钟过期
		redisTemplate.opsForValue().set("smscode_"+mobile, code.toString(),5,TimeUnit.MINUTES);
		// 3.将验证码和手机号用smsutil发送
		Map<String, String> map = new HashMap<String, String>();
		map.put("mobile", mobile);
		map.put("code", code.toString());
		System.out.println(map.toString());
		//调用短信工具类
		//smsUtil.sendSms(map);
	}
	
	/**
	 * 根据手机号和密码登录
	 * @param mobile
	 * @param password
	 * @return
	 */
	public User findByMobileAndPassword(String mobile, String password) {
	    user.setMobile(mobile);
	    Example<User> example = Example.of(user);
		
		 user = userMapper.findOne(example).get(); 
		
		if(user!=null&&encoder.matches(password, user.getPassword())) {
			return user;
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
