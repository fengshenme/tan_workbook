package tan.wei.feng.filter;

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
		String token = "";
		//得到token
		if(authHeader !=null && authHeader.startsWith(ParamConfig.BEARER)) {
			token = authHeader.substring(7);
		}
		if (token != null && !"".equals(token.trim())) {
			try {
				// 对令牌进行验证
	    		Claims claims = JwtUtil.getJwt().parseJsonWebToken(token);
	    		//如果是管理员 
				if(ParamConfig.ADMIN_ROLE.equals(claims.get(ParamConfig.ROLES))){
					request.setAttribute(ParamConfig.ADMIN_CLAIMS, claims);
				}
				//如果是用户
				if(ParamConfig.USER_ROLE.equals(claims.get(ParamConfig.ROLES))){
					request.setAttribute(ParamConfig.USER_CLAIMS, claims);
				}
			}catch(SignatureException se){
				request.setAttribute("error", se.getMessage());
				logger.info("71line:".concat(se.getMessage()));
			}catch (JwtException e) {
				request.setAttribute("error", e.getMessage());
				logger.info("74line:".concat(e.getMessage()));
			}
		}
		return true;
	}

	
}
