package tan.wei.feng.utils;

import java.util.Date;

import org.springframework.beans.factory.annotation.Value;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.JwtBuilder;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;

/**
 * token生成和解析
 * @author 
 *
 */
public class JwtUtil {
	
	private static final String ROLES = "roles";
	
	@Value("${jwt.config.key}")
    private String key ;
    //默认配置为一个小时
	@Value("${jwt.config.ttl}")
    private long ttl ;

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public long getTtl() {
        return ttl;
    }

    public void setTtl(long ttl) {
        this.ttl = ttl;
    }

    /**
     * 生成JWT
     *
     * @param id
     * @param subject
     * @return token
     */
    public String createJWT(String id, String subject, String roles) {
        /**
		 * setIssuedAt用于设置签发时间
		 * signWith用于设置签名秘钥
		 * setExpiration设置过期时间
		 * 自定义claims添加角色
		 */
        JwtBuilder builder = Jwts.builder().setId(id)
                .setSubject(subject)
                .setIssuedAt(new Date())
                .signWith(SignatureAlgorithm.HS256, key).claim(ROLES, roles)
            	.setExpiration( new Date(System.currentTimeMillis() + ttl));
        return builder.compact();
    }

    /**
     * 解析JWT
     * @param token
     * @return
     */
    public Claims parseJWT(String token){
        return  Jwts.parser()
                .setSigningKey(key)
                .parseClaimsJws(token)
                .getBody();
    }
    
      
    
}
