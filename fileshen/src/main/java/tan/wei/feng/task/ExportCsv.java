package tan.wei.feng.task;

import java.io.IOException;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import tan.wei.feng.entity.Article;
import tan.wei.feng.entity.WeiBoSearch;
import tan.wei.feng.entity.WeiboFollow;
import tan.wei.feng.service.WeiBoSearchService;
import tan.wei.feng.service.read.ArticleFindService;
import tan.wei.feng.utils.ReadWriterFileUtils;

/**
 * weibo导出csv文件,导出编码为GB18030
 * @author 锋什么
 *
 */
@Component
public class ExportCsv {
	@Autowired
	private WeiBoSearchService weiBoSearchService = null ;
	
	@Autowired
	private ArticleFindService articleFindService = null;
	
	/**
	 * 写入内容
	 * @throws IOException
	 */
//	@Scheduled(cron= "30 39 * * * ?")
	public void saveCsv() throws IOException {
		List<WeiBoSearch> weibolist= weiBoSearchService.findAll();
		String csvheader = "userid`content`addtime`nickname`weibourl`labels`employphone";
	    String savefile = "H:/test.csv";
	    //写入头部
	    ReadWriterFileUtils.writer(csvheader,savefile);
	    // 写入内容
	    for (WeiBoSearch weiBo : weibolist) {
	    	ReadWriterFileUtils.writer(weiBo.toCsv(),savefile);
		}
	}
	
	/**
	 * 文件以gb19030编码写入
	 * @throws IOException
	 */
	//@Scheduled(cron = "30 47 * * * ?")
	public void saveFollowCsv() throws IOException {
		List<WeiboFollow> findFollowAll = weiBoSearchService.findFollowAll();
		String csvheader = "id`userid`friendid`userurl`friendurl`friendinfo`sex`nickname`followfans`addtime";
		String savefile = "H:/followfriends00.csv";
	    //写入头部ㄅ
	    ReadWriterFileUtils.writer(csvheader,savefile);
	    // 写入内容
	    for (WeiboFollow weiboFoll : findFollowAll) {
	    	ReadWriterFileUtils.writer(weiboFoll.toCsv(),savefile);
		}
	}
	
//	@Scheduled(cron = "30 50 * * * ?")
	public void exportBlogsCsv() throws IOException {
		List<Article> articles = articleFindService.findAll();
		String csvheader = "columnid`content";
		String savefile = "H:/blogs.csv";
	    //写入头部ㄅŒ
	    ReadWriterFileUtils.writer(csvheader,savefile);
	    for (Article article : articles) {
	    	ReadWriterFileUtils.writer(article.getColumnid().toString()
	    			.concat("`").concat(article.getTitle())
	    			.concat(article.getContent()), savefile);
		}
	}
	
}














