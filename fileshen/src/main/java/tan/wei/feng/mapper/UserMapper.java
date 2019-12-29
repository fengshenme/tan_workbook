package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.User;

/**
 * 用户数据仓库
 * @author 锋什么
 *
 */
@Repository
public interface UserMapper extends JpaRepository<User,Long>{

	
	/**
	 * 根据手机号密码登录
	 * @param mobile
	 * @return
	 */
	User findByMobile(String mobile);
	
}
