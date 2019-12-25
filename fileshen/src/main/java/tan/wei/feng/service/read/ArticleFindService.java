package tan.wei.feng.service.read;

import java.util.List;
import java.util.Optional;

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
	
	/**
	 * 文章
	 * @return
	 */
	public Optional<Article> findById(Long id) {
		return articleMapper.findById(id);
	}
	
	/**
	 * 分页查询
	 * @param page
	 * @param pagesize
	 * @return
	 */
	public List<Article> findByPageNews(int page,int pagesize){
		return articleMapper.findByPageNews(page, pagesize);
	}
	
}
