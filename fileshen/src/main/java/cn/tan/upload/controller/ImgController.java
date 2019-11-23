package tan.wei.feng.controller;

import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import tan.wei.feng.service.read.ImgService;

/**
 * 图片控制层
 * @author 10159
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/img")
public class ImgController {
	
	private final ImgService imgService;
	
	@Autowired 
	public ImgController(ImgService imgService) {
		this.imgService = imgService;
	}

	/**
	 * 单个图片显示
	 * @param fileName
	 * @param filePath
	 * @return
	 * @throws IOException
	 */
	@GetMapping(value = "/file/{fileId}")
	public ResponseEntity<Resource> fileExport(@PathVariable String fileId) throws IOException {  
	        return imgService.findByFileurl(fileId);   
    }
	
}
