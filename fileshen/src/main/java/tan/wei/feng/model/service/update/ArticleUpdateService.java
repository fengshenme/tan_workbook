/**
 * 
 */
package tan.wei.feng.model.service.update;

import java.util.Arrays;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import tan.wei.feng.model.mapper.RemarkMapper;

/**
 * @author 1015956962
 *
 */
@Service
public class ArticleUpdateService {
	
	@Autowired
	private  RemarkMapper remarkMapper = null ;
	
	/**
	 * 更新评论
	 * @param articleId
	 * @param content
	 * @param userName
	 * @return
	 */
	public boolean updateByRemark(Long articleId,String content,String userName) {
		
		List<String> arrayList = Arrays.asList(articleId.toString(),content,userName);
		return remarkMapper.updateByPrimaryKey("Remark,id,content,user_name", arrayList);
	}
	
	
	
}
