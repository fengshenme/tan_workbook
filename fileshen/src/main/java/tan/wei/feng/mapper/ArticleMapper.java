package tan.wei.feng.mapper;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import tan.wei.feng.entity.Article;

/**
 * 文章持久
 * @author 10159
 *
 */
@Repository
public interface ArticleMapper extends JpaRepository<Article, Long>{
	
	
	
}
