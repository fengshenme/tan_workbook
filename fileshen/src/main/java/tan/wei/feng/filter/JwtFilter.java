package tan.wei.feng.filter;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.handler.HandlerInterceptorAdapter;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.JwtException;
import io.jsonwebtoken.SignatureException;
import tan.wei.feng.model.ParamConfig;
import tan.wei.feng.utils.JwtUtil;

/**
 * 拦截过滤
 * @author 锋什么
 *
 */
@Component
public class JwtFilter extends HandlerInterceptorAdapter {
	
	private static final Logger logger =  LoggerFactory.getLogger(JwtFilter.class);
	
	@Override
	public boolean preHandle(HttpServletRequest request,HttpServletResponse response, Object handler)  {
		String remoteAddr = request.getRemoteAddr();
		logger.info("请求来自于哪个 ip:{}",remoteAddr);
		
		/**
		 * 无论如何都放行,具体能不能操作还是在具体的操作中去判断
		 * 拦截器只是负责把头请求头中包含token的令牌进行一个解析验证
		 */
		final String authHeader = request.getHeader("Authorization");
		if (authHeader != null && authHeader.startsWith(ParamConfig.BEARER)) {
			//得到token
			final String token = authHeader.substring(7);
			verifyaa(request,token);
		}
		// 通过链接直接访问资源
		if(authHeader == null && request.getCookies()!=null) {
			for (Cookie itco : request.getCookies()) {
				if (itco.getName().equalsIgnoreCase("UserToken")) {
					// 通过itco.getValue()得到token对令牌进行验证
					final String token = itco.getValue();
					verifyaa(request,token);
					logger.info("走的cookie验证");
				}
			}
		}
		return true;
	}
	
	private void verifyaa(HttpServletRequest request,String token ) {
		if (token != null && !"".equals(token.trim())) {
			try {
				// 对令牌进行验证
	    		Claims claims = JwtUtil.parseJsonWebToken(token);
	    		//如果是管理员 
				if(ParamConfig.ADMIN_ROLE.equals(claims.get(ParamConfig.ROLES))){
					request.setAttribute("admin_claims", claims);
				}
				//如果是用户
				if(ParamConfig.USERCLA.equals(claims.get(ParamConfig.ROLES))){
					request.setAttribute("user_claims", claims);
				}
			}catch(SignatureException se){
				logger.info("71line:".concat(se.getMessage()));
			}catch (JwtException e) {
				request.setAttribute("error", e.getMessage());
				logger.info("74line:".concat(e.getMessage()));
			}
		}
	}
	
}
