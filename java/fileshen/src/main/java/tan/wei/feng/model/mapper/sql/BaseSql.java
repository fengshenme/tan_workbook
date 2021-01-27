/**
 * 
 */
package tan.wei.feng.model.mapper.sql;

import javax.persistence.Table;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import tan.wei.feng.model.ParamConfig;

/**
 * @author 10159
 *
 */
public class BaseSql {
	
	private static final  Logger logger = LoggerFactory.getLogger(BaseSql.class);
	
	/**
	 *  查询所有字段的头部
	 * @param entityName
	 * @return
	 */
	public static String tableName(String entityName) {
		String tablename = "";
		try {
			Class<?> forName = Class.forName( ParamConfig.POJOPACK + entityName.trim() );
			// 获取表名
			tablename = forName.getAnnotation(Table.class).name(); 
		} catch (ClassNotFoundException e) {
			logger.info(e.getMessage());
		}
		return  tablename ;
	}
	
}
