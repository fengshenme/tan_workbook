package tan.wei.feng.filter;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.handler.HandlerInterceptorAdapter;

import io.jsonwebtoken.Claims;
import tan.wei.feng.utils.JwtUtil;

/**
 * 拦截过滤
 * @author 10159
 *
 */
@Component
public class JwtFilter extends HandlerInterceptorAdapter {
	
	@Autowired
	private JwtUtil jwtUtil = null;
	
	private static final String ROLES = "roles";
	private static final String USERLE = "user";
	private static final String ADMINLE = "admin";
	private static final String BEARER = "Bearer ";
	
	
	@Override
	public boolean preHandle(HttpServletRequest request,HttpServletResponse response, Object handler)  {
		
		/**
		 * 无论如何都放行,具体能不能操作还是在具体的操作中去判断
		 * 拦截器只是负责把头请求头中包含token的令牌进行一个解析验证
		 */
		final String authHeader = request.getHeader("Authorization");
		// 如果不为空并且包含有Authorization头信息,就对其解析 通过网页访问
		if (authHeader != null && authHeader.startsWith(BEARER)) {
			//得到token
			final String token = authHeader.substring(7);
			verifyaa(request,token);
		}
		// 通过链接直接访问资源
		if(authHeader == null && request.getCookies()!=null) {
			for (Cookie itco : request.getCookies()) {
				if (itco.getName().equalsIgnoreCase("User-Token")) {
					// 通过itco.getValue()得到token对令牌进行验证
					final String token = itco.getValue();
					verifyaa(request,token);
				}
			}
		}
		return true;
	}
	
	private void verifyaa(HttpServletRequest request,String token ) {
		if (token != null && "".equals(token.trim())) {
			// 对令牌进行验证
    		Claims claims = jwtUtil.parseJWT(token);
			//如果是管理员
			if(ADMINLE.equals(claims.get(ROLES))){
				request.setAttribute("admin_claims", claims);
			}
			//如果是用户
			if(USERLE.equals(claims.get(ROLES))){
				request.setAttribute("user_claims", claims);
			}
		}
	}
	
}
