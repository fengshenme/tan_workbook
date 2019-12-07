package tan.wei.feng.service.read;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.Article;
import tan.wei.feng.mapper.ArticleMapper;

/**
 * 文章查询服务
 */
@Service
public class ArticleFindService {
	
	@Autowired
	private ArticleMapper articleMapper = null;
	
	/**
	 * 查找全部
	 * @return
	 */
	public  List<Article>  findAll() {
		
		return articleMapper.findAll();
		
	} 
	
	
}
