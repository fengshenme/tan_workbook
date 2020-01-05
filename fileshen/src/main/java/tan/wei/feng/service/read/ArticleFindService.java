package tan.wei.feng.service.read;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.Article;
import tan.wei.feng.entity.Remark;
import tan.wei.feng.mapper.ArticleMapper;
import tan.wei.feng.mapper.RemarkMapper;

/**
 * 文章查询服务
 * @author 锋什么
 */
@Service
public class ArticleFindService {
	
	@Autowired
	private ArticleMapper articleMapper = null;
	
	@Autowired
	private RemarkMapper remarkMapper = null;
	
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
	 * 文章分页查询
	 * @param page
	 * @param pagesize
	 * @return
	 */
	public List<Article> findByPageNews(Integer page,Integer pagesize){
		
		return articleMapper.findByPageNews(page * pagesize, pagesize);
	}
	
	/**
	 * 评论分页查询
	 * @param page
	 * @param pagesize
	 * @return
	 */
	public List<Remark> findByPageRemark(Long articleid,Integer page){
		int pagesize = 20;
		return remarkMapper.findByPageRemark(articleid,page*pagesize, pagesize);
	}
	
	
}









