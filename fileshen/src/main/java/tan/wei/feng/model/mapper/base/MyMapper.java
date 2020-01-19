package tan.wei.feng.model.mapper.base;

import java.util.List;

import org.apache.ibatis.annotations.DeleteProvider;
import org.apache.ibatis.annotations.InsertProvider;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.SelectProvider;

import tan.wei.feng.model.mapper.sql.DeleteSql;
import tan.wei.feng.model.mapper.sql.InsertSql;
import tan.wei.feng.model.mapper.sql.SelectSql;

/**
 * 公共的mapper,一些经常用到的方法
 * @author 1015956962@163.com
 *
 * @param <T>
 */
@Mapper
public interface MyMapper<T> {
	
	/**
	 * 输入要查询的实体类名区分大小写<br>
	 * 查询全部
	 * @param entityName 实体类名
	 * @param index 起始索引
	 * @param pageSize 分页大小
	 * @return
	 */
	@SelectProvider(type = SelectSql.class, method = "selectAll")
	List<T> selectAll(@Param(value="entityName") String entityName ,@Param(value="index") Integer index,@Param(value="pageSize") Integer pageSize);
	
	/**
	 * 根据主键id查询
	 * @param entityName 实体类名
	 * @param id 主键id
	 * @return 
	 */
	@SelectProvider(type = SelectSql.class, method = "selectByPrimaryKey")
	T selectByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="id") Long id);
	
	/**
	 * 根据字段查询,entityName字符串通过','拆分成数组
	 * <br>数组索引0是实体类名,1则是字段
	 * @param entityName
	 * @param value
	 * @return
	 */
	@SelectProvider(type = SelectSql.class, method = "selectByFiled")
	T selectByFiled(@Param(value="entityName") String entityName,@Param(value="values") String value);
	
	/**
	 * 分页查询,返回总记录数total
	 * <p>
	 * 传入实体类名,记得区分大小写,转入条件字段比如:<br>
	 * entityName.split(",")后数组中索引0为实体类名,1及以后为字段名<br>
	 * values列表中0为分页索引,1为分页大小,2及以后为字段条件的值
	 * @param entityName
	 * @param index
	 * @param pageSize
	 * @return5r
	 */
	@SelectProvider(type = SelectSql.class, method = "selectByPageTotal")
	List<T> selectByPageTotal(@Param(value="entityName") String entityName , @Param(value="values") List<String> values);
	
	/**
	 * @param entityName 实体类名,以及条件字段
	 * 分页条件查询,不返回总记录数,但提升查询速度<br>
	 * entityName.split后数组中索引0为实体类名,1及以后为字段名<br>
	 * values列表中0为分页索引,1为分页大小,2及以后为字段条件的值
	 * @param index 数据索引
	 * @param pageSize
	 * @param value
	 * @return
	 */
	@SelectProvider(type = SelectSql.class, method = "selectByPage")
	List<T> selectByPage(@Param(value="entityName") String entityName , @Param(value="values") List<String> values);
	
	
	
	/**
	 * 保存,插入
	 * @param record
	 * @return
	 */
	@InsertProvider(type = InsertSql.class, method = "insert")
	 int insert(@Param(value="entityName") String entityName,@Param(value="record") T record);
	
	/**
	 * 批量插入,批量保存
	 * @param recordList
	 * @return
	 */
	@InsertProvider(type = InsertSql.class, method = "insertAll")
	 int insertAll(@Param(value="entityName") String entityName,@Param(value="recordList") List<? extends T> recordList);
	
	/**
	 * 根据id删除
	 * @param entityName
	 * @param id
	 * @return
	 */
	@DeleteProvider(type = DeleteSql.class, method = "deleteByPrimaryKey")
	int deleteByPrimaryKey(@Param(value="entityName") String entityName,@Param(value="id") Long id);
	
	
}
