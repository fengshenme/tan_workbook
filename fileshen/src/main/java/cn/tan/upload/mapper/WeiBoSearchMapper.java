package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.WeiBoSearch;


@Repository
public interface WeiBoSearchMapper extends JpaRepository<WeiBoSearch,String>,JpaSpecificationExecutor<WeiBoSearch>{
	
}
