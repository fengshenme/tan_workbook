/**
 * 
 */
package tan.wei.feng.model.service.update;

import java.util.Arrays;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import tan.wei.feng.model.mapper.UserMapper;

/**
 * @author 10159
 *
 */
@Service
public class UserUpdateService {
	
	@Autowired
	private UserMapper userMapper = null ;
	@Autowired
	private BCryptPasswordEncoder encoder = null;
	
	/**
	 * 修改用户账号密码
	 * @param userid
	 * @param password
	 * @return
	 */
	public boolean userPasswordUpdate(Long userid , String password) {
		List<String> arrayList = Arrays.asList(userid.toString(),encoder.encode(password));
		return userMapper.updateByPrimaryKey("User,id,password", arrayList);
	}
	
	/**
	 * 修改手机号
	 * @param userid
	 * @param mobile
	 * @return
	 */
	public boolean userMobileUpdate(Long userid , String mobile) {
		List<String> arrayList = Arrays.asList(userid.toString(),mobile);
		return userMapper.updateByPrimaryKey("User,id,mobile", arrayList);
	}
	
}
