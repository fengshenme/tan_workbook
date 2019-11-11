package cn.tan.upload.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;
import org.springframework.stereotype.Repository;

import cn.tan.upload.entity.WeiBoSearch;


@Repository
public interface WeiBoSearchMapper extends JpaRepository<WeiBoSearch,String>,JpaSpecificationExecutor<WeiBoSearch>{
	
}
