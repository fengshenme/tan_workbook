package cn.tan.zhihu;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.scheduling.annotation.EnableScheduling;

import cn.tan.zhihu.pojo.Article;
import cn.tan.zhihu.util.IdWorker;
import tk.mybatis.spring.annotation.MapperScan;

@MapperScan("cn.tan.zhihu.mapper")
@SpringBootApplication
@EnableScheduling
public class NewsAppliction {
	
	public static void main(String[] args) {
        SpringApplication.run(NewsAppliction.class, args);
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
