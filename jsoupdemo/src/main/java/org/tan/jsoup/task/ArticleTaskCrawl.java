package org.tan.jsoup.task;

import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;
import org.tan.jsoup.pojo.Article;
import org.tan.jsoup.service.ArticleService;

/**
* 文章爬取类
* @author 1
*/
@Component
public class ArticleTaskCrawl {

	@Autowired
	private ArticleService articleService;
	
	@Autowired
	private Article article;
	
	// 统一定时
	public static final String TaskA = "30 28 * * * ?";
	public static final String TaskB = "30 30 * * * ?";
	public static final String TaskC = "30 32 * * * ?";
	public static final String TaskD = "30 34 * * * ?";
	public static final String TaskE = "30 36 * * * ?";
	public static final String TaskF = "30 38 * * * ?";
	
	/**
	* 爬取推荐数据
	 * @throws IOException 
	*/
	@Scheduled(cron= TaskA)
	public void recommendTask() throws IOException{
		System.out.println("爬取推荐文章");
		article.setColumnid("推荐");
		String url = "https://www.csdn.net";
		articleService.introduce(article,url);
	}
	
	 
	/**
	* 爬取db数据
	 * @throws IOException 
	*/
	@Scheduled(cron= TaskB)
	public void dbTask() throws IOException{
		System.out.println("爬取DB文章");
		article.setColumnid("DB");
		String url = "https://www.csdn.net/nav/db";
		articleService.introduce(article,url);
	}
	
	/**
	* 爬取架构数据
	 * @throws IOException 
	*/
	@Scheduled(cron=TaskC)
	public void archTask() throws IOException{
		System.out.println("爬取架构文章");
		article.setColumnid("架构");
		String url = "https://www.csdn.net/nav/arch";
		articleService.introduce( article,url);
	}
	
	/**
	* 爬取web数据
	 * @throws IOException 
	*/
	@Scheduled(cron=TaskD)
	public void webTask() throws IOException{
		System.out.println("爬取前端文章");
		article.setColumnid("web");
		String url = "https://www.csdn.net/nav/web";
		articleService.introduce(article,url);
	}
	
	/**
	 * 爬取python数据
	 * @throws IOException
	 */
	@Scheduled(cron=TaskE)
	public void pythonTask() throws IOException{
		System.out.println("爬取python文章");
		article.setColumnid("python");
		String url = "https://www.csdn.net/nav/python";
		articleService.introduce( article,url);
	}
	
	/**
	* 爬取java数据
	 * @throws IOException 
	*/
	@Scheduled(cron=TaskF)
	public void javaTask() throws IOException{
		System.out.println("爬取java文章");
		article.setColumnid("java");
		String url = "https://www.csdn.net/nav/java";
		articleService.introduce(article,url);
	}
	
	
	
	
}
