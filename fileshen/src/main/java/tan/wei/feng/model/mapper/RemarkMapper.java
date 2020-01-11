package tan.wei.feng.model.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import tan.wei.feng.entity.Remark;
import tan.wei.feng.model.mapper.base.MyMapper;

/**
 * 评论映射
 * @author 1015956962@163.com
 *
 */
@Mapper
public interface RemarkMapper extends MyMapper<Remark>{
	
	/**
	 * 评论分页,无限加载
	 * @param articleId
	 * @param pageIndex
	 * @param pageSize
	 * @return
	 */
	@Select(value = "SELECT * FROM tb_remark r where r.article_id = #{articleId} "
			+ "ORDER BY r.id DESC LIMIT #{pageIndex},#{pageSize} ")
	List<Remark> findByPageRemark(Long articleId, Integer pageIndex,Integer pageSize);
	
	/**
	 * 批量插入
	 * @param remarkLists
	 */
	@Insert(value = {"<script>",
			"INSERT INTO tb_remark  ( id,article_id,user_id,user_name,content )  VALUES ",
			"<foreach collection='remarkLists' item='item' index='index' separator=','>",
			 "(#{item.id},#{item.articleId}, #{item.userId}, #{item.userName}, #{item.content})",
			 "</foreach>",
			"</script>"})
	void insertallaa(@Param(value="remarkLists") List<Remark> remarkLists);
	
}
