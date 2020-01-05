package tan.wei.feng;

import javax.servlet.MultipartConfigElement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.MultipartConfigFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.util.unit.DataSize;

import tan.wei.feng.utils.SmsUtil;


/**
 * 文件启动,开启定时
 * @author 10159
 *
 */
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
        //  单个数据大小30mb
        factory.setMaxFileSize(DataSize.ofMegabytes(200)); // KB,MB
        /// 总上传数据大小
        factory.setMaxRequestSize(DataSize.ofMegabytes(500));
        return factory.createMultipartConfig();
    }
    
    /**
     * 短信工具
     * @return
     */
    @Bean
    public SmsUtil smsUtil() {
    	return new SmsUtil();
    }
}



