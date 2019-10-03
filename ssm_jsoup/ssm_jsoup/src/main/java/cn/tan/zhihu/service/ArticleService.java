package cn.tan.zhihu.service;

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

import cn.tan.zhihu.mapper.TbArticleMapper;
import cn.tan.zhihu.pojo.Article;
import cn.tan.zhihu.util.IdWorker;
import tk.mybatis.mapper.entity.Example;


@Service
public class ArticleService {
	
	@Autowired
	private TbArticleMapper articleMapper;
	
	@Autowired
	private IdWorker idWorker;
	
	@Value("${ai.dataPath}") 
	private String dataPath;
	
	
	/**
	 * 爬取网页文章简介
	 * @throws IOException
	 */
	public void introduce(Article article,String httpurl) throws IOException {
		
		Document doc = Jsoup.connect(httpurl).headers(cookies())
				.timeout(3000)
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
			article.setId(idWorker.nextId() );
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
			System.out.println("添加时间" + article.getCreatetime());
			article.setUserid(userid);
			articleMapper.insert(article);
			
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
			article.setId( idWorker.nextId() );
			article.setCreatetime(new Date());
			article.setTitle(title);
			article.setContent(contenta);
			article.setUrl(url);
			int ta = url.indexOf("net/");
			int ts = url.indexOf("/art");
			String userid = url.substring(ta,ts).replace("net/", "");
			article.setUserid(userid);
			articleMapper.insert(article);
		}
	}
	
	public int  transition(String ab) {
		if(!(ab.equals(null)) && !(ab.equals(""))) {
			return Integer.parseInt(ab);
		}else {
			return 0;	
		}
	}
	
	public Map<String, String> cookies() {
		Map<String,String> map = new HashMap<String, String>();
		map.put("Host", "www.csdn.net");
		map.put("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:69.0) Gecko/20100101 Firefox/69.0");
		map.put("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
		map.put("Accept-Language", "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2");
		map.put("Accept-Encoding", "gzip, deflate, br");
		map.put("Referer", "https://www.csdn.net/");
		map.put("Connection", "keep-alive");
		map.put("Cookie", "uuid_tt_dd=10_18854032990-1569880400260-753570; dc_session_id=10_1569880400260.340484; c-login-auto=28; Hm_lvt_6bcd52f51e9b3dce32bec4a3997715ac=1570026542,1570026662,1570045103,1570045237; Hm_ct_6bcd52f51e9b3dce32bec4a3997715ac=6525*1*10_18854032990-1569880400260-753570; dc_tos=pyrn52; acw_tc=2760821915700264697558559e5e107b64e17356a4aa21e10ae39edc873b71; TY_SESSION_ID=e805c719-422f-49b4-ba1b-c049f22edeef; Hm_lpvt_6bcd52f51e9b3dce32bec4a3997715ac=1570051047");
		map.put("Upgrade-Insecure-Requests", "1");
		map.put("Cache-Control", "max-age=0");
		return map;
	}
	
	
	public String findcount(String id){
		Example example = new Example(Article.class);
        example.createCriteria().andEqualTo("id", id);
		return articleMapper.selectOneByExample(example).getTitle();
		
	}
	
	public int count() {
		return articleMapper.selectcount();
	}
}
