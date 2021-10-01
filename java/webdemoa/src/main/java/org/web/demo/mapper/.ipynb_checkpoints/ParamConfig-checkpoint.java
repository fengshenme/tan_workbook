package org.web.demo.mapper;

/**
 * 一些常用配置
 * 
 * @author 1015956962@163.com
 *
 */
public class ParamConfig {

	/**
	 * 实用工具类不应该有公共构造函数
	 */
	private ParamConfig() {
		throw new IllegalStateException("不能初始化,这是个静态");
	}

	/**
	 * 设置权限,用户要求
	 */
	public static final String USER_CLAIMS = "user_claims";

	/**
	 * 管理员角色
	 */
	public static final String ADMIN_CLAIMS = "admin_claims";

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
	public static final String BEARER = "Bearer ";

	/**
	 * 实体类所在的包名,为自定义sql服务
	 */
	public static final String POJOPACK = "org.web.demo.pojo.";

}
