package tan.wei.feng.controller;

import java.io.IOException;
import java.math.BigInteger;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import tan.wei.feng.service.read.ImgService;

/**
 * 图片控制层
 * @author 锋什么
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/img")
public class ImgController {
	
	private final ImgService imgService;
	
	@Autowired
	private HttpServletRequest request = null;
	
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
	public ResponseEntity<Resource> fileExport(@PathVariable String fileId) {  
	        return imgService.findByFileurl(fileId);   
    }
	
	/**
	 * 根据用途获取图片id
	 * @param filetype 文件用途
	 * @return
	 */
	@GetMapping(value = "/indeximg/{filetype}")
	public ResponseEntity<List<BigInteger>> indexImg(@PathVariable Integer filetype) {
		String jwtstatus = request.getAttribute("error") == null 
							? "" : request.getAttribute("error").toString() ;
		if(jwtstatus !=null && !"".equals(jwtstatus.trim())) {
			return new ResponseEntity<>(imgService.findByfileType(filetype), HttpStatus.PARTIAL_CONTENT);
		}
		return new ResponseEntity<>(imgService.findByfileType(filetype), HttpStatus.OK);
	}
	
}
