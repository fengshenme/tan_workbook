package tan.wei.feng.utils;

import javax.servlet.http.HttpServletRequest;

/**
 * 常用获取客户端ip的工具
 * 统计ip访问数
 * @author 锋什么
 *
 */
public class IpUtils {
	
	private IpUtils() {
	    throw new IllegalStateException("初始化失败");
	 }

    private static final String[] HEADERS_TO_TRY= { 
            "X-Forwarded-For","Proxy-Client-IP","WL-Proxy-Client-IP",
            "HTTP_X_FORWARDED_FOR","HTTP_X_FORWARDED","HTTP_X_CLUSTER_CLIENT_IP",
            "HTTP_CLIENT_IP","HTTP_FORWARDED_FOR",
            "HTTP_FORWARDED","HTTP_VIA",
            "REMOTE_ADDR","X-Real-IP" };
    
    /**
     * 
     * 获取请求主机IP地址,如果通过代理进来，则透过防火墙获取真实IP地址;
     * 获取用户真实IP地址，不使用request.getRemoteAddr();的原因是有可能用户使用了代理软件方式避免真实IP地址, 
     * 可是，如果通过了多级反向代理的话，X-Forwarded-For的值并不止一个，而是一串IP值，则获取其第一个ip
     * @param request
     * @return
     */
    public static String getClientIpAddr(HttpServletRequest request) { 
        String ip = request.getRemoteAddr();  
        boolean isip = ip != null && !"".equals(ip) && !"unknown".equalsIgnoreCase(ip) ;
        if(!isip) {
        	for (String heada : HEADERS_TO_TRY) {
            	ip = request.getHeader(heada);
            	if (isip) {  
                     return ip ; 
                }
    		}
        }
        return ip;  
    }
    
}
