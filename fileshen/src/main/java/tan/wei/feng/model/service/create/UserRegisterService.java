package tan.wei.feng.model.service.create;

import java.util.ArrayList;
import java.util.Date;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import com.alibaba.fastjson.JSONObject;

import tan.wei.feng.model.entity.User;
import tan.wei.feng.model.mapper.UserMapper;
import tan.wei.feng.utils.IdUtil;

/**
 * 用户注册
 * @author 1015956962
 *
 */
@Service
public class UserRegisterService {
	
	private static final Logger logger = LoggerFactory.getLogger(UserRegisterService.class);
	@Autowired
	private UserMapper userMapper = null;
	@Autowired
	private BCryptPasswordEncoder encoder = null;
	
	private Integer threshold = 30;
	private static final ArrayList<User> USER_SAVE_LIST = new ArrayList<> ();

	/**
	 * 保存用户信息,注册  synchronized
	 * @param user
	 */
	public boolean saveUser(JSONObject jsob) {
		User user = new User();
		user.setId(IdUtil.getInstance().idGenerate());
		user.setUpdateTime(new Date());
		user.setNickname(jsob.getString("nickname"));
		user.setMobile(jsob.getString("mobile"));
		// 密码加密
		user.setPassword(encoder.encode(jsob.getString("password")));
		// 保存用户
		try {
			if(threshold<=0) {
				USER_SAVE_LIST.add(user);
            	threshold--;
    		} else {
    			userMapper.insert("User",user);
			}
			return true ;
		} catch (Exception e) {
			userMapper.deleteByPrimaryKey("User",user.getId());
			logger.info(e.getMessage());
			return false;
		}
	}
	
	/**
	 * 定时
	 */
	@Scheduled(cron= "0/1 * * * * ?")
	private void saveall() {
		if(!USER_SAVE_LIST.isEmpty()) {
			userMapper.insertAll("User",USER_SAVE_LIST);
			USER_SAVE_LIST.clear();
		}
		threshold = 30;
	}
	
}
