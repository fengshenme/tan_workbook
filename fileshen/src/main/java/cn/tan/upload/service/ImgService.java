package cn.tan.upload.service;

import java.io.File;
import java.util.Optional;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.FileSystemResource;
import org.springframework.core.io.Resource;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import cn.tan.upload.entity.UserFile;
import cn.tan.upload.mapper.FileMapper;

/**
 * 图片服务层
 * @author 10159
 *
 */
@Service
public class ImgService {
	
	private static final Logger logger = LoggerFactory.getLogger(UserService.class);
	
	@Autowired
	private FileMapper fileMapper = null;
	@Autowired
	private RedisTemplate<String,String> redisTemplate = null;
	
	/**
	 * 根据资源id返回图片显示
	 * @param fileId
	 * @return
	 */
	public ResponseEntity<Resource> findByFileurl(String fileId) {
		String filePath = redisTemplate.opsForValue().get("fileId_" + fileId);
		if(filePath == null ||"".equals(filePath.trim()))  {
			Optional<UserFile> filefindById = fileMapper.findById(Long.parseLong(fileId));
			if (filefindById.isPresent()) {
				String filePath1 = filefindById.get().getFileurl();
				redisTemplate.opsForValue().set("fileId_" + fileId, filePath1,1,TimeUnit.DAYS);
				logger.debug(filePath1);
				return retuFile(filePath1);
			}
		} else {
			return retuFile(filePath);
		} 
		logger.debug(fileId+filePath);
		return new ResponseEntity<>(HttpStatus.NOT_FOUND);
	}
	
	/**
	 * 返回文件
	 * @param filePath
	 * @return
	 */
	private ResponseEntity<Resource> retuFile(String filePath){
		HttpHeaders headers = new HttpHeaders();   
        File file = new File(filePath);
        Resource body = new FileSystemResource(file);
        // 设置响应方式
        headers.setContentType(MediaType.valueOf("image/".concat(filePath.substring(filePath.lastIndexOf('.') + 1)))); 
        headers.setContentLength(file.length());
        return new ResponseEntity<>(body,headers, HttpStatus.OK);
	}
	
}
