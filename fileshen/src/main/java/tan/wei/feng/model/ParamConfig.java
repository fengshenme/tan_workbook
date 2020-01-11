package tan.wei.feng.model;

/**
 * 一些常用配置
 * @author 1015956962@163.com
 *
 */
public class ParamConfig {
	
	/**
	 * 实用工具类不应该有公共构造函数
	 */
	private ParamConfig() {
	    throw new IllegalStateException("ParamConfig类加载失败");
	  }
	
	/**
	 * 设置权限,用户要求
	 */
	public static final String USERCLA = "user_claims";
	
	/**
	 * 角色
	 */
	public static final String ROLES = ("roles");
	
	/**
	 * 权限管理中管理员
	 */
	public static final String ADMIN_ROLE = "admin";
	
	/**
	 * 权限管理中用户
	 */
	public static final String USER_ROLE = "user";
	
	/**
	 * 标记为不记名令牌
	 */
	public static final String BEARER = "Bearer " ;
	
	/**
	 * 实体类所在的包名,为自定义sql服务
	 */
	public static final String POJOPACK = "tan.wei.feng.model.entity." ;
	
	
	
	
	
	
	
	
	
	
}
