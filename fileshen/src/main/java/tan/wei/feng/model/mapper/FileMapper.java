package tan.wei.feng.model.mapper;

import java.math.BigInteger;
import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;

import tan.wei.feng.entity.UserFile;
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
	@Select(value = {"SELECT * FROM tb_article WHERE userid = #{userid} ;","SELECT count(*) FROM tb_article WHERE userid = #{userid}"})
	Page<UserFile> findByUseridAndFiletype(Long userid , Integer filetype, Pageable pageable);
	
	
	/**
	 * 计数
	 * @param filetype
	 * @param userid
	 * @return
	 */
	@Select(value = {"<script>",
			"select * from tb_userfile where filetype = #{filetype}",
			"select * from tb_userfile ","</script>"})
	Object countByFiletypeAndUserid(Integer filetype,Long userid);
	
	/**
	 * 根据用途查询
	 * @param filetype
	 * @return
	 */
	@Select(value = "SELECT u.id FROM tb_userfile u where u.filetype= #{filetype} ")
	List<BigInteger> findByFiletype(Integer filetype);
	
}
