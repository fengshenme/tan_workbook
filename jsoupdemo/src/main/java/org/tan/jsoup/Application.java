package org.tan.jsoup;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.tan.jsoup.pojo.Article;
import org.tan.jsoup.utils.IdWorker;


/**
 * 启动类
 * @author 
 *
 */
@SpringBootApplication
@EnableScheduling
public class Application {
	
	
	public static void main(String[] args) {
		SpringApplication.run(Application.class, args);
	}
	@Bean
	public IdWorker idWorkker(){
		return new IdWorker(1, 1);
	}
	
	@Bean
	public Article article() {
		return new Article();
	}
}