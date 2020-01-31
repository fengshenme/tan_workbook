package tan.wei.feng.model.service.read;

import java.io.File;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.FileSystemResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import tan.wei.feng.model.entity.UserFile;
import tan.wei.feng.model.mapper.FileMapper;

/**
 * 视频服务
 * @author 1015956962
 *
 */
@Service
public class VideoService {
	
	@Autowired
	private FileMapper fileMapper = null;
	
	/**
	 * 根据资源id返回视频显示
	 * @param fileId
	 * @return
	 */
	public ResponseEntity<Resource> findByVideourl(Long fileId ) {
		UserFile findById = fileMapper.selectByPrimaryKey("UserFile",fileId);
		if (findById != null) {
			String filePath = findById.getFileurl();
			HttpHeaders headers = new HttpHeaders();   
	        File file = new File(filePath);
	        Resource body = new FileSystemResource(file);
	        // 设置响应方式
	        headers.setContentType(MediaType.valueOf("video/".concat(filePath.substring(filePath.lastIndexOf('.') + 1)))); 
	        headers.setContentLength(file.length());
	        return new ResponseEntity<>(body,headers, HttpStatus.OK);
		} else {
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
		
        
	}
	
}
