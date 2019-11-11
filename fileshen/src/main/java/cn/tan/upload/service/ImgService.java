package cn.tan.upload.service;

import java.io.File;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.FileSystemResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

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
	private FileMapper fileMapper;

	/**
	 * 根据资源id返回图片显示
	 * @param fileId
	 * @return
	 */
	public ResponseEntity<Resource> findByFileurl(String fileId) {
		String filePath = fileMapper.findById(fileId).get().getFileurl();
		logger.debug(filePath);
		HttpHeaders headers = new HttpHeaders();   
        File file = new File(filePath);
        Resource body = new FileSystemResource(file);
        // 设置响应方式
        headers.setContentType(MediaType.valueOf("image/".concat(filePath.substring(filePath.lastIndexOf('.') + 1)))); 
        headers.setContentLength(file.length());
        return new ResponseEntity<>(body,headers, HttpStatus.OK);
	}
	
}
