package tan.wei.feng.mapper;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.Article;

/**
 * 文章持久
 * @author 锋什么
 *
 */
@Repository
public interface ArticleMapper extends JpaRepository<Article, Long>{
	
	/**
	 * 无限加载
	 * @param page
	 * @param pagesize
	 * @return
	 */
	@Query(value = "SELECT * FROM tb_article LIMIT ?1,?2",nativeQuery = true)
	List<Article> findByPageNews(Integer pageindex, Integer pagesize);
	
	/**
	 * 分页查询
	 * @param lastname
	 * @param pageable
	 * @return
	 */
	@Query(value = "SELECT * FROM tb_article WHERE userid = ?1",
	    countQuery = "SELECT count(*) FROM tb_article WHERE userid = ?1",
	    nativeQuery = true)
	Page<Article> findByUserid(String userid, Pageable pageable);
	
	
}
