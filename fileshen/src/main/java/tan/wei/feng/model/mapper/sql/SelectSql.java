/**
 * 
 */
package tan.wei.feng.model.mapper.sql;

import java.util.List;

import javax.persistence.Table;

import org.apache.ibatis.annotations.Param;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import tan.wei.feng.model.ParamConfig;

/**
 * 查询语句
 * @author 1015956962
 *
 */
public class SelectSql {

	private static final  Logger logger = LoggerFactory.getLogger(SelectSql.class);
	
	private static final  String SELECTFROM = "SELECT * FROM " ;
	private static final  String LIMIT = " LIMIT " ;
	/**
	 *  查询所有字段的头部
	 * @param entityName
	 * @return
	 */
	private static String tableName(String entityName) {
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
	/**
	 *  根据字段主键id查询
	 * @param entityName
	 * @param id
	 * @return
	 */
	public String selectByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="id") Long id ) {
		
		return SELECTFROM + tableName(entityName) + " as t1 WHERE t1.id ='" + id + "'";
	}
	/**
	 *  分页查询全部
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @return
	 */
	public String selectAll(@Param(value="entityName") String entityName ,@Param(value="index") Integer index,@Param(value="pageSize") Integer pageSize) {
		return SELECTFROM + tableName(entityName) + LIMIT + index +"," +pageSize;
	}
	/**
	 * 分页条件查询,返回总记录数
	 * filed数组中索引0为实体类名,1及以后为字段名
	 * values列表中0为分页索引,1为分页大小,2及以后为字段条件的值
	 * <p>
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @param value 字段值
	 * @return
	 */
	public String selectByPageTotal(@Param(value="entityName") String entityName,@Param(value="values") List<String> values) {
		String[] filed = entityName.split(",");
		String name = tableName(filed[0]);
		StringBuilder stri = new StringBuilder();
		logger.info("{}",values.get(1));
		stri.append( " WHERE " + filed[1] + "='" + values.get(2) + "'");
		for (int i = 2; i < values.size()-1; i++) {
			stri.append(" AND " + filed[i] + "='" + values.get(i+1) + "'" );
		}
		
		logger.info("{}",entityName);
		return SELECTFROM + name + " as t1 JOIN (SELECT COUNT(*) AS total FROM " + name + stri.toString() + ") AS total" 
				+ stri.toString() + LIMIT + values.get(0) +"," +values.get(1);
	}
	
	/**
	 * 分页条件查询,不返回总记录数,但提升查询速度<br>
	 * filed数组中索引0为实体类名,1及以后为字段名
	 * values列表中0为分页索引,1为分页大小,2及以后为字段条件的值
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @param value
	 * @return
	 */
	public String selectByPage(@Param(value="entityName") String entityName, @Param(value="values") List<String> values) {
		String[] filed = entityName.split(",");
		String name = tableName(filed[0]);
		StringBuilder stri = new StringBuilder();
		stri.append( " WHERE t1.id >= t2.id AND " + filed[1] + "='" + values.get(2) + "'");
		for (int i = 2; i < values.size()-1; i++) {
			stri.append(" AND " + filed[i] + "='" + values.get(i+1) + "'" );
		}
		logger.info("{}",entityName);
		return SELECTFROM + name + " AS t1 JOIN (SELECT * FROM "  + name  + stri.toString().replace("t1.id >= t2.id AND ", "") 
				+ LIMIT + values.get(0) +", 1) AS t2" + stri.toString() + LIMIT  + values.get(1);
	}
	
	/**
	 * 根据字段条件查询,
	 * @param entityName
	 * @param value
	 * @return
	 */
	public String selectByFiled(@Param(value="entityName") String entityName,@Param(value="column") String value) {
		String[] filed = entityName.split(",");
		return SELECTFROM + tableName(filed[0]) + " AS t1 WHERE t1." + filed[1] + "='" + value + "'" ;
	}
	
}
