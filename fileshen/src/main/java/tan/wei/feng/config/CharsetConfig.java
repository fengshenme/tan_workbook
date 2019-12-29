package tan.wei.feng.config;

import java.nio.charset.StandardCharsets;
import java.util.List;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.converter.HttpMessageConverter;
import org.springframework.http.converter.StringHttpMessageConverter;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

///**
// * 解决中文乱码
// * @author 10159
// *
// */
//@Configuration
//public class CharsetConfig implements WebMvcConfigurer {
//	
//    @Bean
//    public HttpMessageConverter<String> responseBodyConverter() {
//        return  new StringHttpMessageConverter(StandardCharsets.UTF_8);
//    }
//    
//    @Override
//    public void extendMessageConverters(List<HttpMessageConverter<?>> converters) {
//        converters.add(responseBodyConverter());
//    }
//    
//    
//}