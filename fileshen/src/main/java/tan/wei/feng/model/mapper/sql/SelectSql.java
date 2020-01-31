/**
 * 
 */
package tan.wei.feng.model.mapper.sql;

import java.util.List;

import org.apache.ibatis.annotations.Param;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

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
	 *  根据字段主键id查询
	 * @param entityName
	 * @param id
	 * @return
	 */
	public String selectByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="id") Long id ) {
		
		return SELECTFROM + BaseSql.tableName(entityName) + " as t1 WHERE t1.id ='" + id + "'";
	}
	/**
	 *  分页查询全部
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @return
	 */
	public String selectAll(@Param(value="entityName") String entityName ,@Param(value="index") Integer index,@Param(value="pageSize") Integer pageSize) {
		return SELECTFROM + BaseSql.tableName(entityName) + LIMIT + index +"," +pageSize;
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
		String name = BaseSql.tableName(filed[0]);
		StringBuilder stri = new StringBuilder();
		logger.info("{}",values.get(1));
		stri.append( " WHERE " + filed[1] + "='" + values.get(2) + "'");
		for (int i = 2; i < values.size()-1; i++) {
			stri.append(" AND " + filed[i] + "='" + values.get(i+1) + "'" );
		}
		
		logger.info("{}",entityName);
		String nam = name + stri.toString() ;
		return "select *,(SELECT COUNT(id) FROM " + nam + ") AS total from " + nam + LIMIT + values.get(0) +"," +values.get(1);
	}
	
	/**
	 * 分页条件查询,不返回总记录数,但提升查询速度<br>
	 * filed数组中索引0为实体类名,1及以后为字段名
	 * values列表中0为起始索引,1为分页大小(查询多少),2及以后为字段条件的值
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @param value
	 * @return
	 */
	public String selectByPage(@Param(value="entityName") String entityName, @Param(value="values") List<String> values) {
		
		String[] filed = entityName.split(",");
		String name = BaseSql.tableName(filed[0]);
		StringBuilder str1 = new StringBuilder();
		for (int i = 1; i < values.size()-1; i++) {
			str1.append(" AND " + filed[i] + "='" + values.get(i+1) + "'" );
		}
		logger.info("{}",entityName);
		return SELECTFROM + name + " AS t WHERE t.id >= (SELECT id FROM "  + name  + str1.toString().replaceFirst(" AND ", " where ")
				+ LIMIT + values.get(0) +", 1)" + str1.toString() + LIMIT  + values.get(1);
	}
	
	/**
	 * 根据字段条件查询,
	 * @param entityName
	 * @param value
	 * @return
	 */
	public String selectByFiled(@Param(value="entityName") String entityName,@Param(value="column") String value) {
		String[] filed = entityName.split(",");
		return SELECTFROM + BaseSql.tableName(filed[0]) + " AS t1 WHERE t1." + filed[1] + "='" + value + "'" ;
	}
	
}
