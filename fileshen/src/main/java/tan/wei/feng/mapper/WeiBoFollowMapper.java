package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.WeiboFollow;

/**
 * 微博数据仓库
 * @author 锋什么
 *
 */
@Repository
public interface WeiBoFollowMapper extends JpaRepository<WeiboFollow,Long>{
	
}
