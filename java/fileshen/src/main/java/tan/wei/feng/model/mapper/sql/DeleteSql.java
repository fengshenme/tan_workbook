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
 * 删除sql语句
 * @author 1015956962@163.com
 *
 */
public class DeleteSql {
	
	private static final  Logger logger = LoggerFactory.getLogger(DeleteSql.class);
	
	public String deleteByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="id") Long id) {
		String tablename = "";
		try {
			Class<?> forName = Class.forName( ParamConfig.POJOPACK + entityName.trim() );
			// 获取表名
			tablename = forName.getAnnotation(Table.class).name(); 
		} catch (ClassNotFoundException e) {
			logger.info(e.getMessage());
		}
		return "DELETE FROM " + tablename + "WHERE id=" + id;
	}
	
}
