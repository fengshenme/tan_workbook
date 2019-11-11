package cn.tan.upload;

import javax.servlet.MultipartConfigElement;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.MultipartConfigFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.util.unit.DataSize;

import cn.tan.upload.entity.User;
import cn.tan.upload.entity.UserFile;
import cn.tan.upload.entity.WeiBoSearch;
import cn.tan.upload.utils.JwtUtil;
import cn.tan.upload.utils.SmsUtil;


/**
 * 文件启动类
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
     * 发短信用
     * @return
     */
    @Bean
	public SmsUtil smsUtile(){
		return new SmsUtil();
	}
    
    /**
     * 加密解密用
     * @return
     */
    @Bean
	public BCryptPasswordEncoder bcryptPasswordEncoder(){
		return new BCryptPasswordEncoder();
	}
    
    /**
     * 过滤
     * @return
     */
    @Bean
	public JwtUtil jwtUtil(){
		return new JwtUtil();
	}
    
    @Bean
    public UserFile userFile(){
    	return new UserFile();
    }
    
    @Bean
    public User user(){
    	return new User();
    }
    
    @Bean
    public WeiBoSearch weiBoSearch(){
    	return new WeiBoSearch();
    }
}
