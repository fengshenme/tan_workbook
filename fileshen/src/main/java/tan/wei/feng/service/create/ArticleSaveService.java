package tan.wei.feng.service.create;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.alibaba.fastjson.JSONObject;

import tan.wei.feng.entity.Remark;
import tan.wei.feng.mapper.RemarkMapper;
import tan.wei.feng.utils.SimpleUtil;

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
		remark.setId(SimpleUtil.idCreate());
		remark.setArticleId(articleId);
		remark.setContent(jsob.getString("content"));
		remark.setUserName(jsob.getString("userName"));
		remark.setArticleId(articleId);
		remark.setUserId(Long.parseLong(userid));
		remarkMapper.save(remark);
	}
	
}
