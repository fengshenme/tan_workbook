package tan.wei.feng.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import tan.wei.feng.entity.Article;
import tan.wei.feng.entity.Result;
import tan.wei.feng.entity.StatusCode;
import tan.wei.feng.service.read.ArticleFindService;

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
	@GetMapping(value = "/getnewslist/{page}/{pagesize}")
	public Result getnewslist(@PathVariable Integer page, @PathVariable Integer pagesize) {
		List<Article> findpage = articleFindService.findByPageNews(page-1,pagesize);
		if(findpage.isEmpty()) {
			return new Result(StatusCode.ERROR,"没有文章");
		}
		return new Result(StatusCode.OK,findpage);
	} 
	
}
