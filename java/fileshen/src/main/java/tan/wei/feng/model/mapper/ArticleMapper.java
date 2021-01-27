 package tan.wei.feng.model.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import tan.wei.feng.model.entity.Article;
import tan.wei.feng.model.mapper.base.MyMapper;

/**
 * 文章持久
 * @author 1015956962@163.com
 *
 */
@Mapper
public interface ArticleMapper extends MyMapper<Article>{
	
	/**
	 * 无限加载
	 * @param pageindex
	 * @param pagesize
	 * @return
	 */
	@Select(value = "SELECT * FROM tb_article LIMIT #{pageindex},#{pagesize}")
	List<Article> findByPageNews(Integer pageindex, Integer pagesize);
	
}
