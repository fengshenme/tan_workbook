package org.web.demo.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.http.ResponseEntity;
import org.springframework.http.HttpStatus;

import org.web.demo.service.ArticleFindService;
import org.web.demo.pojo.Article;

@RestController
@CrossOrigin
public class HelloController {

	@Autowired
	private ArticleFindService articleFindService = null;

	/**
	 * 根据id获取文章
	 * 
	 * @param id
	 * @return
	 */
	@GetMapping(value = "/getnew/{id}", produces = { "application/json;charset=UTF-8" })
	public ResponseEntity<Article> getnew(@PathVariable Long id) {
		Article findById = articleFindService.findById(id);
		if (findById != null) {
			return new ResponseEntity<>(findById, HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
	}

}
