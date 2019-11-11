package cn.tan.upload.task;

import java.io.File;
import java.io.IOException;
import java.util.Date;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import cn.tan.upload.entity.WeiBoSearch;
import cn.tan.upload.service.WeiBoSearchService;

/**
 * 处理搜索结果页面
 * @author 10159
 *
 */
@Component
public class ImportFile {
	
	private static final Logger logger = LoggerFactory.getLogger(ImportFile.class);
	
	private final WeiBoSearch weiBoSearch ;
	private final WeiBoSearchService weiBoSearchService ;
	
	
	@Autowired
	public ImportFile(WeiBoSearch weiBoSearch, WeiBoSearchService weiBoSearchService) {
		super();
		this.weiBoSearch = weiBoSearch;
		this.weiBoSearchService = weiBoSearchService;
	}
	
	/**
	* 处理搜索结果页面
	 * @throws IOException 
	*/
	@Scheduled(cron= "30 12 1-5 1/10 * ?")
	public void recommendTask() throws IOException{
	    File file = new File("H:/文件/weibo");
	    File[] tempList = file.listFiles();
	    
	    for (File input : tempList) {
	    	if(input.isFile() ) {
	    		Document doc = Jsoup.parse(input, "UTF-8");
	    		Elements content = doc.getElementById("pl_feed_main").select("div.content");
	    		
	    		for (Element element : content) {
	    			String url = element.select("a.name").attr("href");
	    			String nickname = element.select("a.name").attr("nick-name");
	    			String contenta = element.select("p.txt").text();
	    			String userid = url.substring(18, 28);
	    			String employphone =element.select("div.content").select("p.from").text();
	    			weiBoSearch.setNickname(nickname);
	    			weiBoSearch.setContent(contenta);
	    			weiBoSearch.setWeibourl(url.substring(0, 28));
	    			weiBoSearch.setUserid(userid);
	    			weiBoSearch.setEmployphone(employphone);
	    			weiBoSearch.setAddtime(new Date());
	    			logger.info(weiBoSearch.toString());
	    			weiBoSearchService.save(weiBoSearch);
	    		}
	    	}  
		}
	}
	
	@Scheduled(cron= "30 12 1-5 1/10 * ?")
	public static void friends() throws IOException {
	    File file = new File("H:/文件/weibo/userid");
	    File[] tempList = file.listFiles();
	    for (File input : tempList) {
	    	if(input.isFile()) {
	    		Document doc = Jsoup.parse(input, "UTF-8");
	    		Elements elemens = doc.select("div.WB_innerwrap").select("ul.lev_list");
	    		//String follownum = elemens.select("em.num.S_txt1").first().text();
	    		System.out.println(elemens.text());
	    		Elements selects = doc.select("ul.follow_list").select("li.follow_item.S_line2");
	    		for (Element elem : selects) {
					String userurl = elem.selectFirst("dl.clearfix").select("dt.mod_pic").select("a").attr("href");
					String userinfo = elem.selectFirst("dl.clearfix").select("dd.mod_info.S_line1").text();
					String sex = elem.selectFirst("dl.clearfix").select("dd.mod_info.S_line1").select("div.info_name.W_fb.W_f14").select("i.W_icon").attr("class");
					String nickname = elem.selectFirst("dl.clearfix").select("dd.mod_info.S_line1").select("div.info_name.W_fb.W_f14").select("a").text();
					String followfans = elem.selectFirst("dl.clearfix").select("dd.mod_info.S_line1").select("div.info_connect").text();
					System.out.println(userurl);
					System.out.println(userinfo);
					System.out.println(sex);
					System.out.println(nickname);
					System.out.println(followfans);
	    		}
    		}
	    }
	}
	
}
