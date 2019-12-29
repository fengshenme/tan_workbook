package tan.wei.feng.mapper;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import tan.wei.feng.entity.Remark;

/**
 * 评论映射
 * @author 锋什么
 *
 */
public interface RemarkMapper extends JpaRepository<Remark, Long>{
	
	/**
	 * 评论分页,无限加载
	 * @param articleid
	 * @param page
	 * @param pagesize
	 * @return
	 */
	@Query(value = "SELECT * FROM tb_remark r where r.article_id = ?1 ORDER BY r.id DESC LIMIT ?2,?3 ",nativeQuery = true)
	List<Remark>findByPageRemark(Long articleid, Integer page,Integer pagesize);
	
}
