package tan.wei.feng.model.controller;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.alibaba.fastjson.JSONObject;

import io.jsonwebtoken.Claims;
import tan.wei.feng.entity.Article;
import tan.wei.feng.entity.Remark;
import tan.wei.feng.model.ParamConfig;
import tan.wei.feng.model.service.create.ArticleSaveService;
import tan.wei.feng.model.service.read.ArticleFindService;

/**
 * 文章控制器
 * @author 1015956962@163.com
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/api")
public class ArticleController {
	
	@Autowired
	private ArticleFindService articleFindService = null;
	@Autowired
	private ArticleSaveService articleSaveService = null;
	@Autowired
	private HttpServletRequest request = null;
	
	/**
	 * 获取新闻
	 * @param page
	 * @return
	 */
	@GetMapping(value = "/getnewslist/{page}",produces="application/json;charset=UTF-8")
	public ResponseEntity<List<Article>> getnewslist(@PathVariable Integer page) {
		
		if(page  < 1 ) {
			// "页码错误"
			return new ResponseEntity<>(HttpStatus.REQUESTED_RANGE_NOT_SATISFIABLE);
		}
		int pagesize = 20;
		List<Article> findpage = articleFindService.findByPageNews(page-1,pagesize);
		if(findpage.isEmpty()) {
			//"没有文章"
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
		return new ResponseEntity<>(findpage,HttpStatus.OK);
	} 
	
	/**
	 * 根据id获取文章
	 * @param id
	 * @return
	 */
	@GetMapping(value = "/getnew/{id}",produces= {"application/json;charset=UTF-8"})
	public ResponseEntity<Article> getnew(@PathVariable Long id) {
		Article findById = articleFindService.findById(id);
		if (findById != null) {
			return new ResponseEntity<>(findById,HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
	}
	
	/**
	 * 根据文章id,获取评论
	 * @param id
	 * @param page
	 * @return
	 */
	@GetMapping(value = "/getcomments/{id}/{page}", produces="application/json;charset=UTF-8")
	public ResponseEntity<List<Remark>> getRemarks(@PathVariable Long id,@PathVariable Integer page) {
		if(page  < 1 ) {
			// "页码错误"
			return new ResponseEntity<>(HttpStatus.REQUESTED_RANGE_NOT_SATISFIABLE);
		}
		List<Remark> findpage = articleFindService.findByPageRemark(id,page-1);
		if(findpage.isEmpty()) {
			// "没有评论"
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
		return new ResponseEntity<>(findpage,HttpStatus.OK);
	}
	
	/**
	 * 添加评论
	 * @param id
	 * @param jsob
	 * @return
	 */
	@PostMapping(value = "/postcomment/{id}", produces="text/plain;charset=UTF-8")
	public ResponseEntity<String> saveRemark(@PathVariable Long id, @RequestBody JSONObject jsob) {
		Claims claims = (Claims) request.getAttribute(ParamConfig.USER_CLAIMS);
		if(claims != null && !"".equals( claims.getId().trim() ) ) {
			String userid = claims.getId();
			articleSaveService.saveRemark(userid,id,jsob);
			return new ResponseEntity<>("发表评论成功",HttpStatus.OK);
		}
		String jwtstatus = request.getAttribute("error") == null 
				? "" : request.getAttribute("error").toString() ;
		if(jwtstatus !=null && !"".equals(jwtstatus.trim())) {
			return new ResponseEntity<>(HttpStatus.PARTIAL_CONTENT);
		}
		return new ResponseEntity<>(HttpStatus.UNAUTHORIZED);
		
	}
	
}
