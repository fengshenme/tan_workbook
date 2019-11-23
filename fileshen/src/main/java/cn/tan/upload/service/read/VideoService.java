package tan.wei.feng.service.read;

import java.io.File;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.FileSystemResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.UserFile;
import tan.wei.feng.mapper.FileMapper;

/**
 * 视频服务层
 * @author 10159
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
	public ResponseEntity<Resource> findByVideourl(String fileId ) {
		Optional<UserFile> findById = fileMapper.findById(Long.parseLong(fileId));
		if (findById.isPresent()) {
			String filePath = findById.get().getFileurl();
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
