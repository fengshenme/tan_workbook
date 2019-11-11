package cn.tan.upload.filter;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.handler.HandlerInterceptorAdapter;

import cn.tan.upload.utils.JwtUtil;

/**
 * 拦截过滤
 * @author 10159
 *
 */
@Component
public class JwtFilter extends HandlerInterceptorAdapter {
	@Autowired
	private JwtUtil jwtUtil;
	
	@Override
	public boolean preHandle(HttpServletRequest request,HttpServletResponse response, Object handler) throws Exception {
		
		/**
		 * 无论如何都放行,具体能不能操作还是在具体的操作中去判断
		 * 拦截器只是负责把头请求头中包含token的令牌进行一个解析验证
		 */
		final String authHeader = request.getHeader("authorization");
		// 如果不为空并且包含有Authorization头信息,就对其解析 通过网页访问
		if (authHeader != null && authHeader.startsWith("Bearer ")) {
			//得到token
			final String token = authHeader.substring(7);
			jwtUtil.verifyJWT(request,response, token);
			
		}
		// 通过链接直接访问资源
		if(request.getCookies() != null) {
			for (Cookie itco : request.getCookies()) {
				if (itco.getName().equalsIgnoreCase("User-Token")) {
					// 通过itco.getValue()得到token对令牌进行验证
					final String token = itco.getValue();
					jwtUtil.verifyJWT(request,response, token);
				}
			}
		}
		return true;
	}
	
}
