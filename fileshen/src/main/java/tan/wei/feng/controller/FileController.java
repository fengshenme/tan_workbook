package tan.wei.feng.controller;

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
import tan.wei.feng.entity.PageResult;
import tan.wei.feng.entity.UserFile;
import tan.wei.feng.service.create.FileSaveService;
import tan.wei.feng.service.delete.FileDeleteService;
import tan.wei.feng.service.read.FileDownService;
import tan.wei.feng.service.read.FileFindService;
import tan.wei.feng.utils.FileDirUtils;

/**
 * 文件控制层
 * @author 10159
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
	// 用户权限
	private static final String USERCLA = "user_claims";  
	
	/**
	 * 获取用户下的文件列表
	 * @return
	 */
	@GetMapping(value = "/fileList/{fileType}")
	public ResponseEntity<List<Long>> fileUrlList(@PathVariable Integer fileType){
		Claims claims = (Claims) request.getAttribute(USERCLA);
		if(claims != null && !"".equals(claims.getId().trim())){
			List<Long> findByfileid = fileFindService.findByfileid(claims.getId(),fileType);
			if(findByfileid.isEmpty()) {
				return new ResponseEntity<>(HttpStatus.OK);
			}
			return new ResponseEntity<>(findByfileid,HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		
	}
	
	/**
	 * 获取用户下的分页文件列表
	 * @return
	 */
	@GetMapping(value = "/filePageList/{fileType}/{page}/{pagesize}")
	public ResponseEntity<PageResult<UserFile>> fetchList(@PathVariable Integer fileType , @PathVariable Integer page,@PathVariable Integer pagesize){
		Claims claims = (Claims) request.getAttribute(USERCLA);
		if(claims != null && !"".equals(claims.getId().trim())){
			PageResult<UserFile> findByfileidPage = fileFindService.findByfileidPage(claims.getId(),fileType,page,pagesize);
			return new ResponseEntity<>(findByfileidPage,HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
	}
	
	/**
	 * 文件下载
	 * @param fileName
	 * @param filePath
	 * @return
	 * @throws IOException
	 */
	@GetMapping(value = "/fileDownload/{filecode}")
	public ResponseEntity<byte[]> fileDownload(@PathVariable String filecode) throws IOException {  
		Claims claims = (Claims) request.getAttribute(USERCLA);
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
	 * 
	 */
	@PostMapping(value = "/uploadFile")
	public ResponseEntity<String> fileSave(@RequestParam("file") MultipartFile file){
		Claims claims = (Claims) request.getAttribute(USERCLA);
		if(!file.isEmpty() && claims != null && !"".equals(claims.getId().trim())) {
			// 递归次数
			int ia = 3;
			String filePath = FileDirUtils.dirFile(datapath,file.getOriginalFilename(),ia) ;
			//转存文件
	        try {
	            file.transferTo(new File(filePath));
	            if(fileSaveService.addFile(filePath,claims.getId())) {
					return new ResponseEntity<>("上传成功",HttpStatus.OK) ;
				} 
	        } catch (IOException e) {
	        	try {
	        		Path path = Paths.get(filePath);
					Files.delete(path);
				} catch (IOException e1) {
					logger.info(e1.getMessage());
				}
	            return new ResponseEntity<>("上传失败重新上传"+e.getMessage(),HttpStatus.EXPECTATION_FAILED);
	        }
		}
		return new ResponseEntity<>("上传失败重新上传",HttpStatus.EXPECTATION_FAILED);
	}
		
	/**
	 * 文件删除
	 * @param fileId
	 * @return
	 */
	@DeleteMapping(value = "/delFile/{fileId}")
	public  ResponseEntity<String> delFile(@PathVariable String fileId) {
		Claims claims = (Claims) request.getAttribute(USERCLA);
		if(claims != null && !"".equals(claims.getId().trim()) && fileDeleteService.delfile(Long.parseLong(fileId))){
			return new ResponseEntity<>("删除成功",HttpStatus.OK);
		}
		return new ResponseEntity<>("删除失败",HttpStatus.NOT_FOUND);
		
	}

}
