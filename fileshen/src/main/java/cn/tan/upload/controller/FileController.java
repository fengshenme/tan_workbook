package cn.tan.upload.controller;

import java.io.File;
import java.io.IOException;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.domain.Page;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import cn.tan.upload.entity.PageResult;
import cn.tan.upload.entity.Result;
import cn.tan.upload.entity.StatusCode;
import cn.tan.upload.entity.UserFile;
import cn.tan.upload.service.FileSaveService;
import cn.tan.upload.service.FileService;
import cn.tan.upload.utils.FileDirUtils;
import io.jsonwebtoken.Claims;

/**
 * 文件控制层
 * @author 10159
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/api")
public class FileController {
	
	private static final Logger logger =  LoggerFactory.getLogger(FileController.class);
	private final HttpServletRequest request;
	private final FileService fileService;
	private final FileSaveService fileSaveService;
	
	@Value("${storessd.filepath}")
	private String datapath;
	
	@Autowired
	public FileController(HttpServletRequest request, FileService fileService,FileSaveService fileSaveService) {
		this.request = request;
		this.fileService = fileService;
		this.fileSaveService = fileSaveService; 
	}
	
	
	/**
	 * 获取用户下的文件列表
	 * @return
	 */
	@GetMapping(value = "/fileList/{fileType}")
	public Result fileUrlList(@PathVariable String fileType){
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			String message = (String) request.getAttribute("error");
			return new Result(StatusCode.ERROR,message);
		}else {
			return new Result(StatusCode.OK,"查询成功",fileService.findByfileid(claims.getId(),fileType));
		}
	}
	
	/**
	 * 获取用户下的分页文件列表
	 * @return
	 */
	@GetMapping(value = "/filePageList/{fileType}")
	public Result fetchList(@RequestParam Map<String,String> map,@PathVariable String fileType){
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			String message = (String) request.getAttribute("error");
			return new Result(StatusCode.ERROR,message);
		}else {
			Page<UserFile> pageList = fileService.findByfileidPage(claims.getId(),fileType,map);
			return new Result(StatusCode.OK,"查询成功",new PageResult<UserFile>(pageList.getTotalElements(),pageList.getContent()));
		}
	}
	
	
	/**
	 * 文件下载
	 * @param fileName
	 * @param filePath
	 * @return
	 * @throws IOException
	 */
	@GetMapping(value = "/fileDownload/{filecode}")
	public ResponseEntity<?> fileDownload(@PathVariable String filecode) throws IOException {  
		Claims claims=(Claims) request.getAttribute("user_claims");
		logger.info(claims.getId());
		if(claims==null || "".equals(claims.getId())){
			Result result = new Result("请登录在下载"); 
			// 也可以放置页面,图片等
			return new ResponseEntity<>(result, HttpStatus.UNAUTHORIZED);
		} else {
	        return fileService.fileDownload(filecode);
		}
	}
	
	
	/**
	 * 文件保存
	 * @param <file>
	 * @param file
	 * @return
	 * 
	 */
	@PostMapping(value = "/uploadFile")
	public Result fileSave(@RequestParam("file") MultipartFile file){
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			return new Result(StatusCode.ERROR,"请登录在上传");
		}  
		if(!file.isEmpty()){
			// 递归次数
			int ia = 3;
			String filePath = FileDirUtils.dirFile(datapath,file.getOriginalFilename(),ia) ;
			//转存文件
	        try {
	            file.transferTo(new File(filePath));
	        } catch (Exception e) {
	        	File filea = new File(filePath);
	        	filea.delete();
	            return new Result(StatusCode.ERROR,e.getMessage());
	        }
	        if(fileSaveService.addFile(filePath,claims.getId())) {
				return new Result(StatusCode.OK,"上传成功");
			} 
	     }
		return new Result(StatusCode.ERROR,"上传失败重新上传");
	}
		
	/**
	 * 文件删除
	 * @param fileId
	 * @return
	 */
	@DeleteMapping(value = "/delFile/{fileId}")
	public  Result delFile(@PathVariable String fileId) {
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			return new Result(StatusCode.ERROR,"请登录在下载");
		}else {
			if(fileService.delfile(Long.parseLong(fileId))) {
				return new Result(StatusCode.OK,"删除成功");
			} else {
				return new Result(StatusCode.ERROR,"删除失败");
			}
		}
	}
}
