package tan.wei.feng.model.service.read;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.Article;
import tan.wei.feng.entity.Remark;
import tan.wei.feng.model.mapper.ArticleMapper;
import tan.wei.feng.model.mapper.RemarkMapper;

/**
 * 文章查询服务
 * @author 1015956962@163.com
 */
@Service
public class ArticleFindService {
	
	
	private final ArticleMapper articleMapper ;
	
	private final RemarkMapper remarkMapper ;
	
	/**
	 * @param articleMapper
	 * @param remarkMapper
	 */
	@Autowired
	public ArticleFindService(ArticleMapper articleMapper, RemarkMapper remarkMapper) {
		this.articleMapper = articleMapper;
		this.remarkMapper = remarkMapper;
	}
	
	/**
	 * 查找全部
	 * @return
	 */
	public  List<Article>  findAll() {
		return articleMapper.selectAll("Article",0,10);
	}
	
	/**
	 * 文章
	 * @return
	 */
	public Article findById(Long id) {
		return articleMapper.selectByPrimaryKey("Article",id);
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









