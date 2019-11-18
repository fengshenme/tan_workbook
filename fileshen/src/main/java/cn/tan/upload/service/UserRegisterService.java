package cn.tan.upload.service;

import java.util.ArrayList;
import java.util.Date;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.User;
import cn.tan.upload.mapper.UserMapper;

/**
 * 
 * @author 10159
 *
 */
@Service
public class UserRegisterService {
	
	private static final Logger logger = LoggerFactory.getLogger(UserRegisterService.class);
	@Autowired
	private UserMapper userMapper = null;
	
	private Integer threshold = 30;
	ArrayList<User> userList = new ArrayList<> ();

	/**
	 * 保存用户信息,注册  synchronized
	 * @param user
	 */
	public boolean saveUser(User user) {
		BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();
		user.setUserid(IdUtil.createSnowflake(1, 1).nextIdStr());
		Date date = new Date();
		user.setCreation_time(date);
		user.setUpdate_time(date);
		// 密码加密
		String newpassword = encoder.encode(user.getPassword());
		user.setPassword(newpassword);
		// 保存用户
		try {
			if(threshold<=0) {
				userList.add(user);
            	threshold--;
    		} else {
    			userMapper.save(user);
			}
			return true ;
		} catch (Exception e) {
			userMapper.deleteById(user.getUserid());
			logger.info(e.getMessage());
			return false;
		}
	}
	
	/**
	 * 定时
	 */
	@Scheduled(cron= "0/1 * * * * ?")
	private void saveall() {
		if(!userList.isEmpty()) {
			userMapper.saveAll(userList);
			userList.clear();
		}
		threshold = 30;
	}
	
}
