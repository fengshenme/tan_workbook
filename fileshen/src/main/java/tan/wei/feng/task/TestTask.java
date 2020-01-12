package tan.wei.feng.task;

import java.util.ArrayList;
import java.util.List;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import tan.wei.feng.entity.Article;
import tan.wei.feng.entity.Remark;
import tan.wei.feng.model.mapper.ArticleMapper;
import tan.wei.feng.model.mapper.RemarkMapper;
import tan.wei.feng.utils.IdUtil;

/**
 * 实验类
 * @author 1015956962@163.com
 *
 */
@Component
public class TestTask {
	
	@Autowired
	private ArticleMapper articleMapper = null ;
	@Autowired
	private RemarkMapper remarkMapper = null ;
	
	private static final  Logger logger = LoggerFactory.getLogger(TestTask.class);
	private static final ArrayList<Remark> REMARKLIST = new ArrayList<> ();
	
	@PostConstruct
	public void findTest() {
		List<Article> selectAll = articleMapper.selectAll("Article",20,20);
		Article art = articleMapper.selectByPrimaryKey("Article", Long.parseLong("1577626242040931"));
		Article filed = articleMapper.selectByFiled("Article,id","1577626242040931");
		logger.info(selectAll.toString());
		logger.info(art.toString());
		logger.info(filed.toString());
	}
	
	/**
	 * 批量插入评论
	 */
	public void remarkInesrt() {
		int t = 0 ;
		long aa = 0 ;
		int ac = 100 ;
		for (int cc = 0; cc < ac; cc++) {
			REMARKLIST.clear();
			for (int i = 0; i < ac; i++) {
				Remark remark = new Remark();
				remark.setId(IdUtil.getIdUtil().idGenerate());
				remark.setArticleId(Long.parseLong("1577626242115931"));
				remark.setContent("Java核心技术·卷 I（原书第10版）内容介绍Java领域最有影响力和价值的著作之一，"
						+ "由拥有20多年教学与研究经验的资深Java技术专家撰写(获Jolt大奖)，与《Java编程思想》齐名，"
						+ "10余年全球畅销不衰，广受好评。第10版根据Java SE 8全面更新，同时修正了第9版中的不足"
						+ "，系统全面讲解了Java语言的核 心概念、语法、重要特性和开发方法，包含大量案例，实践性强。"
						+ "一直以来，《...");
				remark.setUserName("github_36519260");
				remark.setUserId(++aa);
				REMARKLIST.add(remark);
//				remarkMapper.insert(remark);
				
			}
			try {
				remarkMapper.insertAll(REMARKLIST);
				
			} catch (Exception e) {
				logger.info(e.getMessage());
				t++;
			}
		}
		logger.info("保存失败数:{}",t);
	}
	
	
	
	
}
