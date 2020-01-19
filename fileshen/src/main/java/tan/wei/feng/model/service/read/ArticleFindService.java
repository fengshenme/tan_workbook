package tan.wei.feng.model.service.read;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import tan.wei.feng.model.entity.Article;
import tan.wei.feng.model.entity.PageResult;
import tan.wei.feng.model.entity.Remark;
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
	
    private final RedisTemplate<String, String> redisTemplate;
	
	/**
	 * @param articleMapper
	 * @param remarkMapper
	 */
	@Autowired
	public ArticleFindService(ArticleMapper articleMapper, RemarkMapper remarkMapper,RedisTemplate<String, String> redisTemplate) {
		this.redisTemplate = redisTemplate ;
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
	public PageResult<Remark> findByPageRemark(Long articleid,Integer page){
		Integer pagesize = 20;
		List<Remark> selectByPageTotal = null;
		String total = redisTemplate.opsForValue().get("findByPageRemark_total");
		ArrayList<String> arrayList = new ArrayList<>();
		
		Integer pageIndex = page*pagesize ;
		arrayList.add(pageIndex.toString());
		arrayList.add(pagesize.toString());
		arrayList.add(articleid.toString());
		
		if(total == null || "".equals(total)) {
			selectByPageTotal = remarkMapper.selectByPageTotal("Remark,article_id", arrayList);
			total = selectByPageTotal.get(0).getTotal().toString();
			redisTemplate.opsForValue().set("findByPageRemark_total", total , 5,TimeUnit.MINUTES);
		} else {
			selectByPageTotal = remarkMapper.selectByPage("Remark,article_id", arrayList);
		}
		PageResult<Remark> pageResult = new PageResult<>();
		pageResult.setTotal(Integer.parseInt(total));
		pageResult.setRows(selectByPageTotal);
		return pageResult ;
	}
	
	
}









