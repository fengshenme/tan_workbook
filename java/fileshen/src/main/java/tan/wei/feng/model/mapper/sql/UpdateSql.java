/**
 * 
 */
package tan.wei.feng.model.mapper.sql;

import java.util.List;

import org.apache.ibatis.annotations.Param;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * @author 10159
 *
 */
public class UpdateSql {
	
	private static final  Logger logger = LoggerFactory.getLogger(UpdateSql.class);
	
	
	
	/**
	 * 更新语句，更新一个或多个字段
	 */
	public String updateByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="filed") List<String> values) {
		String[] filed = entityName.split(",");
		String name = BaseSql.tableName(filed[0]);
		StringBuilder stri = new StringBuilder();
		stri.append("UPDATE "+name + " u SET " + "u." + filed[2] + "='" +values.get(1) + "'");
		for (int i = 2; i < values.size(); i++) {
			stri.append(",u." + filed[i+1] + "='" + values.get(i) + "'" );
		}
		stri.append(" WHERE u."+ filed[1] + "='"+ values.get(0) + "'");
		logger.info("{}",values.get(1));
		return stri.toString();	
	}
	
}
