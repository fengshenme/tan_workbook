package tan.wei.feng.task;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Random;
import java.util.regex.Pattern;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import tan.wei.feng.entity.Article;
import tan.wei.feng.service.read.ArticleFindService;
import tan.wei.feng.utils.IKUtil;

/*** 
 * 入库类(分词后保存为txt)
 * @author 1 
 * */ 
@Component
public class ArticleTxtPipeline  {
	
	private static final Logger logger = LoggerFactory.getLogger(ArticleTxtPipeline.class);
	
	@Value("${ai.dataPath}") 
	private String dataPath; 
	
	@Autowired
	private ArticleFindService articleService = null;
	
	//@Scheduled(cron="30 58 19 * * ?")
	public void findall() {
		Random rn = new Random(1);
		for (Article article : articleService.findAll()) {
			//用正则去掉异常字符
			String title = Pattern.compile("[^\\u4e00-\\u9fa5\\w\\d]").matcher(article.getTitle()).replaceAll("");
			String content = article.getContent();
			try {
				String path = dataPath.concat("/").concat(article.getColumnid()); //所创建文件目录
				File f = new File(path); 
				if(!f.exists()){
					f.mkdirs(); //创建目录
				}
				
				//将标题+正文分词后保存到相应的文件夹
				Path paths = Paths.get(path.concat("/")+title+rn.nextInt(3)+".txt");
				try(BufferedWriter writer = Files.newBufferedWriter(paths, StandardCharsets.UTF_8)){
					writer.write(IKUtil.split(title+" "+content," "));
					writer.flush();
			    	writer.close(); 
				}
			} catch (FileNotFoundException e) { 
				e.printStackTrace(); 
			} catch (IOException e) {
				e.printStackTrace(); 
			}
		logger.info("{}", rn.nextInt(3));
		}
	}
}
	
	
