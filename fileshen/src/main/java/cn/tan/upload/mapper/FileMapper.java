package tan.wei.feng.mapper;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.UserFile;

@Repository
public interface FileMapper extends JpaRepository<UserFile,Long>{
	
	/**
	 * 通过用户id查询文件id列表
	 * @param id
	 * @return
	 */
	@Query(value = "SELECT id FROM userfile where userid = ?1 and filetype= ?2 ",
			nativeQuery = true)
	List<Long> selectByIdaa(Long userid,String filetype);
	
	/**
	 * 分页定制
	 * @param userid
	 * @param filetype
	 * @param pageable
	 * @return
	 */
	Page<UserFile> findByUseridAndFiletype(Long userid , String filetype, Pageable pageable);
	
	/**
	 * 计数
	 * @return
	 */
	Long countByFiletypeAndUserid(String filetype,String userid);
	
}
