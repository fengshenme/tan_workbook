package org.tan.jsoup.service;

import java.io.IOException;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Pattern;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.tan.jsoup.dao.ArticleDao;
import org.tan.jsoup.pojo.Article;
import org.tan.jsoup.utils.IdWorker;


/**
 * 文章服务层
 * 
 * @author 101
 *
 */
@Service
public class ArticleService {

	@Autowired
	private ArticleDao articleDao;
	
	@Autowired
	private IdWorker idWorker;
	
	@Value("${ai.dataPath}") 
	private String dataPath;
	
	// 浏览器标志
	private String browsertag = "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:68.0) Gecko/20100101 Firefox/68.0";
		
	
	/**
	 * 爬取网页文章简介
	 * @throws IOException
	 */
	public void introduce(Article article,String httpurl) throws IOException {
		
		Document doc = Jsoup.connect(httpurl)
				.userAgent(browsertag)
				.cookies(cookies())
				.get();
		
		Elements docc = doc.select("div.list_con");
		
		for (Element tt : docc) {
			String title = tt.select("div.title").select("a[href]").text();
			String content = tt.select("div.summary.oneline").text();
			String url = tt.select("div.title").select("a[href]").attr("href");
			String read_num = tt.select("div.interactive.floatR").select("dd.read_num").select("span.num").text();
			String common_num = tt.select("div.interactive.floatR").select("dd.common_num").select("span.num").text();
			
			//获取页面需要的内容
			System.out.println("标题："+title );
			System.out.println("地址" + url);
			System.out.println("内容长度："+content.length() );
			System.out.println("阅读数："+  transition(read_num));
			System.out.println("评论数："+ transition(common_num) );
			article.setId( idWorker.nextId()+"" );
			article.setCreatetime(new Date());
			article.setTitle(title);
			article.setContent(content);
			article.setComment(transition(common_num));
			article.setVisits(transition(read_num));
			article.setUrl(url);
			
			int ta = url.indexOf("net/");
			int ts = url.indexOf("/art");
			String userid = url.substring(ta,ts).replace("net/", "");
			System.out.println("用户昵称id:" + userid);
			article.setUserid(userid);
			articleDao.save(article);
			
		}
		
	}
	
	/**
	 * 爬取网页文章正文
	 * @throws IOException
	 */
	public void articleBody(Document doc,Article article) throws IOException {
		// Jsoup.parse(unsafe).text()// 提取HTML中所有文本
		Elements docc = doc.body().select("div.container.clearfix")
				.select("li.clearfix").select("div.list_con");
		 
		for (Element tt : docc) {
			String title = tt.select("div.title").select("a[href]").text();
			String imgurl = tt.select("dl.list_userbar").select("dd.name").attr("img[src]");
			String url = tt.select("a[href]").attr("href");
			//获取页面需要的内容
			System.out.println("标题："+title );
			System.out.println("博客地址"+url);
			System.out.println("图片地址"+imgurl);
			
			try {
				// 停10秒在下钻,避免封ip,以及
				Thread.sleep(10000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			Document docca = Jsoup.connect(url).get();
			String content = docca.body()
					.select("div.blog-content-box")
					.select("div.article_content.clearfix")
					.select("div#content_views").text();
			
			String contenta = Pattern.compile("[^\\u4e00-\\u9fa5\\w\\d]").matcher(content).replaceAll("");
			System.out.println("内容："+contenta);
			article.setId( idWorker.nextId()+"" );
			article.setCreatetime(new Date());
			article.setTitle(title);
			article.setContent(contenta);
			article.setUrl(url);
			int ta = url.indexOf("net/");
			int ts = url.indexOf("/art");
			String userid = url.substring(ta,ts).replace("net/", "");
			article.setUserid(userid);
			articleDao.save(article);
		}
	}
	
	public int  transition(String ab) {
		if(!(ab.equals(null)) && ab!=""&& !(ab.isEmpty())) {
			return Integer.parseInt(ab);
		}else {
			return 0;	
		}
	}
	
	public Map<String, String> cookies() {
		Map<String,String> map = new HashMap<>();
		map.put("BAIDUID",	"60C399FC4291A8E9EC81E854598F8F15:FG=1");
		map.put("BDORZ",	"FFFB88E999055A3F8A630C64834BD6D0");
		map.put("BDRCVFR[gltLrB7qNCt]",	"mk3SLVN4HKm");
		map.put("BIDUPSID",	"60C399FC4291A8E9EC81E854598F8F15");
		map.put("delPer",	"0");
		map.put("H_PS_PSSID",	"1447_21090_29522_29518_29568_29221");
		map.put("PSINO",	"6");
		map.put("PSTM",	"1561610996");
		return map;
	}

}
