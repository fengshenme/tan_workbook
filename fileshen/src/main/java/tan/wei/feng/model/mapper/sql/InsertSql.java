package tan.wei.feng.model.mapper.sql;

import java.lang.reflect.Field;
import java.util.List;

import javax.persistence.Table;

import org.apache.ibatis.annotations.Param;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import tan.wei.feng.model.ParamConfig;

/**
 * 插入sql语句
 * @author 1015956962@163.com
 *
 */
public class InsertSql  {

	private static final  Logger logger = LoggerFactory.getLogger(InsertSql.class);
	
	/**
	 * 插入语句
	 * @param isAll
	 * @param str
	 * @return
	 */
	private  String getsql(boolean isAll,String str) {
		long startTime = System.currentTimeMillis();
		StringBuilder sql = new StringBuilder();
		try {
			Class<?> forName = Class.forName( ParamConfig.POJOPACK + str.trim() );
			// 获取表名
			String tablename = forName.getAnnotation(Table.class).name(); 
			// 字段数组
			Field[] field = forName.getDeclaredFields();
			sql.append("<script>");
			sql.append("INSERT INTO ");
			 // 获取表名
	        sql.append(tablename);
	        
	        StringBuilder sfv = new StringBuilder();
	        sql.append("<trim prefix='(' suffix=')' suffixOverrides=','>");
	        for (Field fie : field) {
	        	String na = fie.getName().trim();
				if(!"serialVersionUID".equalsIgnoreCase(na) && !"total".equalsIgnoreCase(na)) {
					// 将驼峰字段转为下划线区分
					sql.append(na.replaceAll("[A-Z]", "_$0").toLowerCase()).append(',');
					// 插入字段值部分
					sfv.append("#{record.").append(na).append("} ,");
				}
			}
	        sql.append("</trim> VALUES ");
	        if(isAll) {
	        	sql.append("<foreach collection='recordList' item='record' index='index' separator=','>");
	        }
	        sql.append("<trim prefix='(' suffix=')' suffixOverrides=','>");
	        // 添加字段值
	        sql.append(sfv.toString());
	        sql.append("</trim>");
	        if(isAll) {
	        	sql.append("</foreach>");
	        }
	        sql.append("</script>");
		} catch (ClassNotFoundException e) {
			logger.info(e.getMessage());
		}
		long endTime = System.currentTimeMillis();
		logger.info("{}",endTime - startTime);
		return sql.toString() ;
	}
	
	/**
	 * 插入
	 * @param map
	 * @return
	 */
	public String insert(@Param(value="entityName") String entityName,@Param(value="record") Object record) {
	 	boolean isAll = false;
	 	return getsql(isAll,entityName);
	}
	
	/**
	 * 保存全部,批量插入
	 * @param <T>
	 * @param map
	 * @return
	 */
 	public 	<T> String insertAll(@Param(value="entityName") String entityName,@Param(value="recordList") List<? extends T> recordList)  {
		boolean isAll = true;
        return getsql(isAll,entityName);
	}
	
}
