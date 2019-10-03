package cn.tan.zhihu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import cn.tan.zhihu.pojo.Article;
import cn.tan.zhihu.service.ArticleService;

@RestController
@RequestMapping(value = "/article")
public class ArticleController {
	
	@Autowired
	private ArticleService articleService;
	@Autowired
	public Article article;
	
    @RequestMapping("/gettitle/{id}")
    public String findIdByAeticle(@PathVariable String id) {
		return articleService.findcount(id);
	}
    @RequestMapping("/getcount")
    public int findcount() {
    	return articleService.count();
    }
}
