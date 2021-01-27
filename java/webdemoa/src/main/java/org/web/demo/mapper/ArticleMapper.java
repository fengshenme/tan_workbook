package org.web.demo.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import org.web.demo.pojo.Article;

/**
 * 文章持久
 * 
 * @author 1015956962@163.com
 *
 */
@Mapper
public interface ArticleMapper extends BaseMapper<Article> {

	/**
	 * 无限加载
	 * 
	 * @param pageindex
	 * @param pagesize
	 * @return
	 */
	@Select(value = "SELECT * FROM tb_article LIMIT #{pageindex},#{pagesize}")
	List<Article> findByPageNews(@Param("pageindex") Integer pageindex, @Param("pagesize") Integer pagesize);

}
