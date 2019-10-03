package test;

import java.io.IOException;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import org.jsoup.Jsoup;
import org.jsoup.UnsupportedMimeTypeException;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.junit.Test;
import org.springframework.beans.factory.annotation.Autowired;

import cn.hutool.core.lang.Snowflake;
import cn.hutool.core.util.IdUtil;
import cn.tan.zhihu.mapper.TbArticleMapper;
import cn.tan.zhihu.pojo.Article;
import cn.tan.zhihu.util.DownloadUtil;

/**
 * 实验与测试层
 * @author 10159
 *
 */
public class JsoupTest {
	
	 String browsertag = "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:68.0) Gecko/20100101 Firefox/68.0";
	
	 @Autowired
	private TbArticleMapper articleMapper;
	 @Autowired
	 private Article article;
	
	 
	 
	/**
	 * 爬取网页文章简介
	 * @throws IOException
	 */
	@Test
	public void introduce() throws IOException {
		//参数1为终端ID,参数2为数据中心ID
		Snowflake snowflake = IdUtil.createSnowflake(1, 1);
		Document doc = Jsoup.connect("https://www.csdn.net/nav/web").get();
		Elements docc = doc.select("div.list_con");
		
		for (Element tt : docc) {
			String title = tt.select("div.title").select("a[href]").text();
			String content = tt.select("div.summary.oneline").text();
			String html = tt.select("div.title").select("a[href]").attr("href");
			System.out.println(html);
			//获取页面需要的内容
			System.out.println("标题："+title );
			System.out.println("内容："+content );
			String id = snowflake.nextId() + "";
			if(id.equals("")) {
				String ac = id + snowflake.nextId() + "";
				System.out.println(ac);
			}
			System.out.println(id);
			
//			String id = "5775777888393";
//			article.setId(id);
//			article.setTitle(title);
//			article.setContent(content);
//			articleMapper.insert(article);
		}
		
	}
	
	@Test
	public void testIntroduce() throws IOException {
		//参数1为终端ID
		//参数2为数据中心ID
		Snowflake snowflake = IdUtil.createSnowflake(1, 1);
		Document doc = Jsoup.connect("https://www.csdn.net/nav/arch").headers(cookies())
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
			article.setId(snowflake.nextId());
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
	 * 爬取网页文章简介
	 * @throws IOException
	 */
	@Test
	public void introduceImgDown() throws IOException {
		Document doc = Jsoup.connect("https://www.csdn.net/nav/arch")
				.userAgent(browsertag)
				.cookies(cookies())
				.get();
		Elements docc = doc.select("div.list_con");
		
		for (Element tt : docc) {
			String title = tt.select("div.title").select("a[href]").text();
			String content = tt.select("div.summary.oneline").text();
			String html = tt.select("div.title").select("a[href]").attr("href");
			System.out.println(html);
			//获取页面需要的内容
			System.out.println("标题："+title );
			System.out.println("内容："+content );
			
			Elements ss = tt.getElementsByTag("img");
			for (Element et : ss) {
				
				String imgurl = et.attr("abs:src");
				System.out.println("图片地址" + imgurl);
				try {
					try {
						// 停5秒在下钻,避免封ip,以及
						Thread.sleep(10000);
					} catch (InterruptedException a) {
						a.printStackTrace();
					}
					Jsoup.connect(imgurl)
						.userAgent(browsertag).cookies(cookies())
						.get();
				} catch (UnsupportedMimeTypeException e) {
					String imgsurl = e.getUrl();
		        	System.out.println("--------下载图片出错:-----"+imgsurl);
		        	String fileName = imgsurl.substring(imgsurl.lastIndexOf("/")+1);
					System.out.println("图片名字"+fileName);
					String savePath = "D:\\data\\userimg";
					DownloadUtil.download(imgsurl, fileName, savePath);
				}
				
			}
		}
	}
	
	
	
	
	/**
	 * 爬取网页文章正文
	 * @throws IOException
	 */
	@Test
	public void articleBody() throws IOException {
		Document doc = Jsoup.connect("https://www.csdn.net/nav/java")
				.userAgent(browsertag).cookies(cookies())
				.get();
		// Jsoup.parse(unsafe).text()// 提取HTML中所有文本
		/**
		 * .select("div.fixed_content")
		 *		.select("ul.feedlist_mod")
		 */
		Elements docc = doc.body().select("div.container.clearfix")
				.select("li.clearfix").select("div.list_con").select("div.title");
		 
		for (Element tt : docc) {
			String title = tt.select("a[href]").text();
			String html = tt.select("a[href]").attr("href");
			//获取页面需要的内容
			System.out.println("标题："+title );
			System.out.println(html);
			try {
				// 停5秒在下钻,避免封ip,以及
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			Document docca = Jsoup.connect(html).get();
			String content = docca.body()
					.select("div.blog-content-box")
					.select("div.article_content.clearfix")
					.select("div.markdown_views").text();
			
			System.out.println("内容："+content);
		}
	}
	
	@Test
	public void maptest() {
			Map<String, String> maps = cookies();
			System.out.println(maps.size());
			System.out.println(maps.entrySet());
			System.out.println(maps.keySet());
			System.out.println(maps.values());
			for ( Object ob: maps.entrySet()) {
				System.out.println(ob);
			}
		
	}
	
	public int  transition(String ab) {
		if(!(ab.equals(null)) && ab!="") {
			return Integer.parseInt(ab);
		}else {
			return 0;	
		}
	}
	
	public Map<String, String> cookies() {
		Map<String,String> map = new HashMap<String, String>();
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

