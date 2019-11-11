package cn.tan.upload.mapper;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import cn.tan.upload.entity.UserFile;

@Repository
public interface FileMapper extends JpaRepository<UserFile,String>,JpaSpecificationExecutor<UserFile>{
	
	/**
	 * 通过用户id查询文件id列表
	 * @param id
	 * @return
	 */
	@Query(value = "SELECT id FROM userfile where userid = ?1 and filetype= ?2 ",
			nativeQuery = true)
	List<String> selectByIdaa(String id,String filetype);
	
	/**
	 * 分页定制2
	 * @param id
	 * @param filetype
	 * @param pageable
	 * @return
	 */
	Page<UserFile> findByUseridAndFiletype(String id , String filetype, Pageable pageable);
	
	/**
	 * 计数
	 * @return
	 */
	Long countByFiletypeAndUserid(String filetype,String userid);
	
}
