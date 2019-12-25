package tan.wei.feng.controller;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import tan.wei.feng.entity.Article;
import tan.wei.feng.service.read.ArticleFindService;

/**
 * 
 * @author 10159
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/api")
public class ArticleController {
	
	@Autowired
	private ArticleFindService articleFindService = null;
	
	/**
	 * 获取新闻
	 * @return
	 * 
	 */
	@GetMapping(value = "/getnewslist/{page}")
	public ResponseEntity<List<Article>> getnewslist(@PathVariable Integer page) {
		if(page  < 1 ) {
			// "页码错误"
			return new ResponseEntity<>(HttpStatus.REQUESTED_RANGE_NOT_SATISFIABLE);
		}
		int pagesize = 20;
		List<Article> findpage = articleFindService.findByPageNews(page-1,pagesize);
		if(findpage.isEmpty()) {
			//"没有文章"
			return new ResponseEntity<>(HttpStatus.UNAUTHORIZED);
		}
		return new ResponseEntity<>(findpage,HttpStatus.OK);
	} 
	
	/**
	 * 根据id获取文章
	 * @param id
	 * @return
	 */
	@GetMapping(value = "/getnew/{id}")
	public ResponseEntity<Article> getnew(@PathVariable Long id) {
		Optional<Article> findById = articleFindService.findById(id);
		if (findById.isPresent()) {
			return new ResponseEntity<>(findById.get(),HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
	}
	
	@GetMapping(value = "/getcomments/{id}/{page}")
	public ResponseEntity<String> getComments(@PathVariable Integer id,@PathVariable Integer page) {
		
		int pagesize = 20 ;
		
		return new ResponseEntity<>(HttpStatus.OK);
	}
	
}
