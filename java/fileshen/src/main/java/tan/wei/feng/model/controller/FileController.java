package tan.wei.feng.model.controller;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
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

import io.jsonwebtoken.Claims;
import tan.wei.feng.model.ParamConfig;
import tan.wei.feng.model.entity.PageResult;
import tan.wei.feng.model.entity.UserFile;
import tan.wei.feng.model.service.create.FileSaveService;
import tan.wei.feng.model.service.delete.FileDeleteService;
import tan.wei.feng.model.service.read.FileDownService;
import tan.wei.feng.model.service.read.FileFindService;
import tan.wei.feng.utils.FileDirUtils;

/**
 * 文件控制层
 * @author 1015956962@163.com
 *
 */
@RestController
@CrossOrigin
@RequestMapping(value = "/file")
public class FileController {
	
	private static final Logger logger =  LoggerFactory.getLogger(FileController.class);
	
	@Autowired
	private HttpServletRequest request = null;
	@Autowired
	private FileDownService fileDownService = null;
	@Autowired
	private FileFindService fileFindService = null;
	@Autowired
	private FileSaveService fileSaveService = null;
	@Autowired
	private FileDeleteService fileDeleteService = null;
	
	
	@Value("${storessd.filepath}")
	private String datapath;
	
	/**
	 * 获取用户下的文件列表
	 * @return
	 */
	@GetMapping(value = "/fileList/{fileType}",produces="application/json;charset=UTF-8")
	public ResponseEntity<List<Long>> fileUrlList(@PathVariable Integer fileType){
		Claims claims = (Claims) request.getAttribute(ParamConfig.USER_CLAIMS);
		List<Long> findByfileid = null ;
		if(claims != null && !"".equals(claims.getId().trim())){
			findByfileid = fileFindService.findByfileid(claims.getId(),fileType);
		}
		if(findByfileid != null && !findByfileid.isEmpty()) {
			return new ResponseEntity<>(findByfileid,HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		
	}
	
	/**
	 * 获取用户下的分页文件列表
	 * @return
	 */
	@GetMapping(value = "/filePageList/{fileType}/{page}/{pagesize}",produces="application/json;charset=UTF-8")
	public ResponseEntity<PageResult<UserFile>> fetchList(@PathVariable Integer fileType , @PathVariable Integer page,@PathVariable Integer pagesize){
		Claims claims = (Claims) request.getAttribute(ParamConfig.USER_CLAIMS);
		if(claims != null && !"".equals(claims.getId().trim())){
			PageResult<UserFile> findByfileidPage = fileFindService.findByfileidPage(claims.getId(),fileType,page,pagesize);
			return new ResponseEntity<>(findByfileidPage,HttpStatus.OK);
		}
		
		return new ResponseEntity<>(HttpStatus.UNAUTHORIZED);
	}
	
	/**
	 * 文件下载
	 * @param fileName
	 * @param filePath
	 * @return
	 * @throws IOException
	 */
	@GetMapping(value = "/fileDownload/{filecode}",produces = "application/octet-stream")
	public ResponseEntity<byte[]> fileDownload(@PathVariable String filecode) throws IOException {  
		Claims claims = (Claims) request.getAttribute(ParamConfig.USER_CLAIMS);
		if(claims != null && !"".equals(claims.getId().trim())){
			logger.info(claims.getId());
	        return fileDownService.fileDownload(filecode);
		}
		return new ResponseEntity<>(HttpStatus.UNAUTHORIZED);
	}
	
	
	/**
	 * 文件保存
	 * @param <file>
	 * @param file
	 * @return
	 */
	@PostMapping(value = "/uploadFile",produces="text/plain;charset=UTF-8")
	public ResponseEntity<String> fileSave(@RequestParam("file") MultipartFile file){
		Claims claims = (Claims) request.getAttribute(ParamConfig.USER_CLAIMS);
		logger.info("{}",claims);
		if(!file.isEmpty() && claims != null && !"".equals(claims.getId().trim())) {
			
			// 递归次数
			int ia = 3;
			String filePath = FileDirUtils.dirFile(datapath,file.getOriginalFilename(),ia) ;
			//转存文件
	        try {
	            file.transferTo(new File(filePath));
	            if(fileSaveService.addFile(filePath,claims.getId())) {
					return new ResponseEntity<>("文件保存成功",HttpStatus.OK) ;
				} 
	        } catch (IOException e) {
	        	try {
	        		Path path = Paths.get(filePath);
					Files.delete(path);
				} catch (IOException e1) {
					logger.info(e1.getMessage());
				}
	        	// 文件保存失败501
	            return new ResponseEntity<>("文件保存失败,请重新上传",HttpStatus.NOT_IMPLEMENTED) ;
	        }
		}
		// 身份验证出错401
		return new ResponseEntity<>("没有权限上传,请登录在上传",HttpStatus.UNAUTHORIZED);
	}
		
	/**
	 * 文件删除
	 * @param fileId
	 * @return
	 */
	@DeleteMapping(value = "/delFile/{fileId}",produces="text/plain;charset=UTF-8")
	public ResponseEntity<String> delFile(@PathVariable String fileId) {
		Claims claims = (Claims) request.getAttribute(ParamConfig.USER_CLAIMS);
		if(claims != null && !"".equals(claims.getId().trim()) && fileDeleteService.delfile(Long.parseLong(fileId))){
			return new ResponseEntity<>(HttpStatus.OK);
		}
		// 服务器成功处理了请求,且没有返回任何内容
		return new ResponseEntity<>(HttpStatus.NO_CONTENT);
	}

}
