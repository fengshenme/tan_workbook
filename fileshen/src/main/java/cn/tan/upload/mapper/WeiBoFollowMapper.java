package cn.tan.upload.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import cn.tan.upload.entity.WeiboFollow;

@Repository
public interface WeiBoFollowMapper extends JpaRepository<WeiboFollow,String>{
	
}
