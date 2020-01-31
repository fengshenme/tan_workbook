package tan.wei.feng.model.service.read;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.alibaba.fastjson.JSON;

import tan.wei.feng.model.entity.Article;
import tan.wei.feng.model.entity.PageResult;
import tan.wei.feng.model.entity.Remark;
import tan.wei.feng.model.mapper.ArticleMapper;
import tan.wei.feng.model.mapper.RemarkMapper;
import tan.wei.feng.utils.CacheUtils;

/**
 * 文章查询服务
 * @author 1015956962
 */
@Service
public class ArticleFindService {
	
	@Autowired
	private ArticleMapper articleMapper = null ;
	
	@Autowired
	private  RemarkMapper remarkMapper = null ;
	
	@Autowired
	private CacheUtils acheUtils = null ;

	private static final Logger logger = LoggerFactory.getLogger(ArticleFindService.class);
    
	/**
	 * 查找全部，最多查找1000
	 * @return
	 */
	public  List<Article>  findAll() {
		return articleMapper.selectAll("Article",0,1000);
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
	 * 当分页数据多的时候通过大分页再小分页，进行分页查询
	 * @param page
	 * @param pagesize
	 * @return
	 */
	public PageResult<Remark> findByPageRemark(Long articleid,Integer page){
		List<Remark> selectByP = null;
		Integer pageindex = (page%10) * 20;
		long starttime1 = System.currentTimeMillis();
		String keyTotal = "findByPageRemark_total" ;
		String total = acheUtils.redisStringGet(keyTotal);
		// 默认从数据库读取200条数据，返回前端的数量为20一页 向上取整,加一，得出区间 (page*20)/200,采用10倍缩放
		int interval = page / 10 ;
		String key = "findByPageRemark,"+articleid + "," + interval ;
		String jsonString =  acheUtils.redisStringGet(key);
		Integer paindex = interval*200 ;
		List<String> arrayList = Arrays.asList(paindex.toString(),"200",articleid.toString());
		if(jsonString != null && !"".equals(jsonString)) {
			selectByP  =  JSON.parseArray(jsonString, Remark.class);
			logger.info("-----cache-----{}" ,pageindex);
		} else {
			if(total == null || "".equals(total)) {
				selectByP = remarkMapper.selectByPageTotal("Remark,article_id", arrayList);
				total = selectByP.get(0).getTotal().toString();
				acheUtils.redisStringSet(keyTotal, total , 5,TimeUnit.MINUTES);
			} else {
				selectByP = remarkMapper.selectByPage("Remark,article_id", arrayList);
			}
			jsonString = JSON.toJSONString(selectByP);
			acheUtils.redisStringSet(key, jsonString , 5,TimeUnit.MINUTES);
			logger.info("-----mysql-----{},{},{}" ,interval,key,jsonString.length()*3);
		}
		PageResult<Remark> pageResult = new PageResult<>();
		pageResult.setTotal(Integer.parseInt(total));
		pageResult.setRows(selectByP.subList(pageindex, pageindex +20));
		logger.info("--{}--",System.currentTimeMillis() - starttime1);
		return pageResult ;
		
	}
	
	
}









