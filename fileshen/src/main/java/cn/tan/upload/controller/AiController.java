package tan.wei.feng.controller;

import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import tan.wei.feng.service.ai.CnnService; 

@RestController 
@RequestMapping("/ai") 
public class AiController { 
	
	@Autowired 
	private CnnService cnnService=null; 
	
	/**
	 * 
	 * @param content
	 * @return
	 */
	@PostMapping(value="/textclassify") 
	public Map<String, Double> textClassify(@RequestBody Map<String,String> content){ 
		return cnnService.textClassify(content.get("content")); 
	}
	
}
