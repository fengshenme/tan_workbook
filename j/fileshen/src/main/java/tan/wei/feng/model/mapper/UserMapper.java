package tan.wei.feng.model.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import tan.wei.feng.model.entity.User;
import tan.wei.feng.model.mapper.base.MyMapper;

/**
 * 用户数据仓库
 * @author 1015956962@163.com
 *
 */
@Mapper
public interface UserMapper extends MyMapper<User>{

	
	/**
	 * 根据手机号密码登录
	 * @param mobile
	 * @return
	 */
	@Select(value = "SELECT * FROM tb_user where mobile=#{mobile}")
	User findByMobile(String mobile);

}
