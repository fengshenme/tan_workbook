package tan.wei.feng.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurationSupport;

import tan.wei.feng.filter.JwtFilter;


/**
 * 拦截
 * @author 10159
 *
 */
@Configuration
public class InterceptorConfig extends WebMvcConfigurationSupport {
	
	@Autowired
	private JwtFilter jwtFilter;
	
	@Override
	public void addInterceptors(InterceptorRegistry registry) {
		// 注册拦截器要声明拦截器对象和要拦截的请求
		registry.addInterceptor(jwtFilter)
				.addPathPatterns("/**")
				.excludePathPatterns("/**/login");
	}
}