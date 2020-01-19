package tan.wei.feng.model.service.create;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.alibaba.fastjson.JSONObject;

import tan.wei.feng.model.entity.Remark;
import tan.wei.feng.model.mapper.RemarkMapper;
import tan.wei.feng.utils.IdUtil;

/**
 * 文章保存
 * @author 1015956962@163.com
 *
 */
@Service
public class ArticleSaveService {
	
	@Autowired
	private RemarkMapper remarkMapper = null ;
	
	/**
	 * 保存评论
	 * @param userid
	 * @param articleId
	 * @param jsob
	 */
	public void saveRemark(String userid, Long articleId, JSONObject jsob) {
		Remark remark = new Remark();
		remark.setId(IdUtil.getInstance().idGenerate());
		remark.setArticleId(articleId);
		remark.setContent(jsob.getString("content"));
		remark.setUserName(jsob.getString("userName"));
		remark.setUserId(Long.parseLong(userid));
		remarkMapper.insert("Remark",remark);
	}
	
}
