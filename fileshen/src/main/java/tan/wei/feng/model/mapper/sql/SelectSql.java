/**
 * 
 */
package tan.wei.feng.model.mapper.sql;

import javax.persistence.Table;

import org.apache.ibatis.annotations.Param;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import tan.wei.feng.model.ParamConfig;

/**
 * 查询语句
 * @author 1015956962@163.com
 *
 */
public class SelectSql {

	private static final  Logger logger = LoggerFactory.getLogger(SelectSql.class);
	/**
	 *  查询所有字段的头部
	 * @param entityName
	 * @return
	 */
	private static String selectHead(String entityName) {
		String tablename = "";
		try {
			Class<?> forName = Class.forName( ParamConfig.POJOPACK + entityName.trim() );
			// 获取表名
			tablename = forName.getAnnotation(Table.class).name(); 
		} catch (ClassNotFoundException e) {
			logger.info(e.getMessage());
		}
		return "SELECT * FROM " + tablename ;
	}
	/**
	 *  根据字段主键id查询
	 * @param entityName
	 * @param id
	 * @return
	 */
	public String selectByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="id") Long id ) {
		return selectHead(entityName) + " WHERE id =" + id ;
	}
	/**
	 *  分页查询全部
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @return
	 */
	public String selectAll(@Param(value="entityName") String entityName ,@Param(value="index") Integer index,@Param(value="pageSize") Integer pageSize) {
		return selectHead(entityName) + " LIMIT " + index +"," +pageSize;
	}
	
	/**
	 * 根据字段查询,
	 * @param entityName
	 * @param value
	 * @return
	 */
	public String selectByFiled(@Param(value="entityName") String entityName,@Param(value="column") String value) {
		String[] filed = entityName.split(",");
		return selectHead(filed[0]) + " WHERE " + filed[1] + "=" + value ;
	}
	
}
