package tan.wei.feng.model.mapper;

import java.math.BigInteger;
import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import tan.wei.feng.model.entity.UserFile;
import tan.wei.feng.model.mapper.base.MyMapper;

/**
 * 文件数据仓库
 * @author 1015956962@163.com
 *
 */
@Mapper
public interface FileMapper extends MyMapper<UserFile>{
	
	
	/**
	 * 通过用户id查询文件id列表
	 * @param userid
	 * @param filetype
	 * @return
	 */
	@Select(value = "SELECT u.id FROM tb_userfile u "
			+ "where u.userid = #{userid} and u.filetype= #{filetype} ")
	List<Long> selectByIdaa(Long userid,Integer filetype);
	
	/**
	 * 分页定制
	 * @param userid
	 * @param filetype
	 * @param pageable
	 * @return
	 */
	@Select(value = {"SELECT id,(SELECT count(*) FROM tb_userfile WHERE userid = #{userid} and filetype=#{filetype}) as total "
			+ "FROM tb_userfile WHERE userid = #{userid} and filetype=#{filetype} LIMIT #{index},#{pageSize}"})
	List<UserFile> findByUseridAndFiletype(Long userid , Integer filetype, Integer index, Integer pageSize);
	
	
	/**
	 * 计数
	 * @param filetype
	 * @param userid
	 * @return
	 */
	@Select(value = {"SELECT count(*) FROM tb_userfile WHERE userid = #{userid} and filetype = #{filetype}"})
	Object countByFiletypeAndUserid(Integer filetype,Long userid);
	
	/**
	 * 根据用途查询
	 * @param filetype
	 * @return
	 */
	@Select(value = "SELECT u.id FROM tb_userfile u where u.filetype= #{filetype} ")
	List<BigInteger> findByFiletype(Integer filetype);
	
}
