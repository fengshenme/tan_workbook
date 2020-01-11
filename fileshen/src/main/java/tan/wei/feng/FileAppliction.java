package tan.wei.feng;

import javax.servlet.MultipartConfigElement;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.MultipartConfigFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.util.unit.DataSize;


/**
 * 文件启动,开启定时
 * @author 10159
 *
 */
@MapperScan(value = {"tan.wei.feng.model.mapper"})
@SpringBootApplication
@EnableScheduling 
public class FileAppliction {
	
	public static void main(String[] args) {
        SpringApplication.run(FileAppliction.class, args);
    }
	
	/**
     * 文件上传配置
     * 
     * @return
     */
    @Bean
    public MultipartConfigElement multipartConfigElement() {
        MultipartConfigFactory factory = new MultipartConfigFactory();
        //  单个数据大小最大200MB // KB,MB
        factory.setMaxFileSize(DataSize.ofMegabytes(200)); 
        /// 总上传数据大小最大500mb
        factory.setMaxRequestSize(DataSize.ofMegabytes(500));
        return factory.createMultipartConfig();
    }
    
    
}



