package cn.tan.zhihu.mapper;

import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

import cn.tan.zhihu.pojo.Article;
import tk.mybatis.mapper.common.Mapper;

@Repository
public interface TbArticleMapper extends Mapper<Article>{
	
	@Select("SELECT count(id) FROM tb_article ")
    int selectcount();
	
	@Select("select * from tb_article where id=#{id}")
    Article getEmpById(Integer id);
	
	
}