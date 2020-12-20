package org.web.demo.service;

import java.util.List;

import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.web.demo.pojo.Article;
import org.web.demo.mapper.ArticleMapper;
import org.slf4j.Logger;

/**
 * 文章查询服务
 * 
 * @author 1015956962
 */
@Service
public class ArticleFindService {

	@Autowired
	private ArticleMapper articleMapper = null;

	private static final Logger logger = LoggerFactory.getLogger(ArticleFindService.class);

	/**
	 * 查找全部，最多查找1000
	 * 
	 * @return
	 */
	public List<Article> findAll() {
		logger.info("查询文章");
		return articleMapper.selectAll("tb_article", 0, 1000);
	}

	/**
	 * 文章
	 * 
	 * @return
	 */
	public Article findById(Long id) {

		logger.info("{}", id);
		return articleMapper.selectByPrimaryKey("tb_article", id);
	}

}
