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

import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.WeiboFollow;
import cn.tan.upload.service.WeiBoSearchService;

/**
 * 
 * @author 10159
 *
 */
@Component
public class ImportFollowTask {
	
	
	private static final Logger logger = LoggerFactory.getLogger(ImportFollowTask.class);
	
	private final WeiBoSearchService weiBoSearchService ;
	private final WeiboFollow weiboFollow ;
	
	@Autowired
	public ImportFollowTask(WeiBoSearchService weiBoSearchService, WeiboFollow weiboFollow) {
		this.weiBoSearchService = weiBoSearchService;
		this.weiboFollow = weiboFollow;
	}
	
	/**
	 * 导入关注者信息
	 * @throws IOException
	 */
	//@Scheduled(cron= "30 50 * * * ?")
	public void friends() throws IOException {
	    File file = new File("H:\\文件\\weibo\\friend00\\userid");
	    File[] tempList = file.listFiles();
	    for (File input : tempList) {
	    	if(input.isFile()) {
	    		Document doc = Jsoup.parse(input, "UTF-8");
	    		Elements elemens = doc.select("div.WB_innerwrap").select("ul.lev_list");
	    		String userurl = elemens.select("ul.lev2_list").select("li.lev2").select("a").attr("href");
	    		try {
		    		String userid = (userurl ==null || userurl.equals("")) ? userurl : userurl.substring(18, userurl.lastIndexOf("/"));
		    		Elements selects = doc.select("ul.follow_list").select("li.follow_item.S_line2");
		    		for (Element elem : selects) {
		    			Elements sel = elem.select("dl.clearfix");
		    			String friendurl = sel.select("dt.mod_pic").select("a").attr("href");
						String friendid = (friendurl ==null || friendurl.equals("")) ? friendurl : friendurl.substring(friendurl.lastIndexOf("/")+1, friendurl.indexOf("?"));
						Elements sele  = sel.select("dd.mod_info.S_line1");
						String friendinfo = sele.text();
						String sex = sele.select("div.info_name.W_fb.W_f14").select("i.W_icon").attr("class");
						String nickname = sele.select("div.info_name.W_fb.W_f14").select("a").text();
						String followfans = sele.select("div.info_connect").text();
						weiboFollow.setId(IdUtil.getSnowflake(1, 1).nextId());
						weiboFollow.setUserid(userid);
						weiboFollow.setFriendid(friendid);
						weiboFollow.setUserurl(userurl);
						weiboFollow.setFriendurl(friendurl);
						weiboFollow.setFriendinfo(friendinfo);
						weiboFollow.setSex(sex);
						weiboFollow.setNickname(nickname);
						weiboFollow.setFollowfans(followfans);
						weiboFollow.setAddtime(new Date());
						weiBoSearchService.saveFollow(weiboFollow);
		    		}
	    		}catch (Exception e) {
	    			logger.info("------------异常:".concat(e.getMessage()));
				} 
    		}
	    }
	}
	
}
