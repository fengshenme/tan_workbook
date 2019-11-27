package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.WeiboFollow;

@Repository
public interface WeiBoFollowMapper extends JpaRepository<WeiboFollow,Long>{
	
}
