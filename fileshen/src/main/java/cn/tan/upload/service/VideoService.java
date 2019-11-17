package cn.tan.upload.service;

import java.io.File;

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
 * 视频服务层
 * @author 10159
 *
 */
@Service
public class VideoService {
	
	@Autowired
	private FileMapper fileMapper;
	
	
	/**
	 * 根据资源id返回视频显示
	 * @param fileId
	 * @return
	 */
	public ResponseEntity<Resource> findByVideourl(String fileId ) {
		String filePath = fileMapper.findById(Long.parseLong(fileId)).get().getFileurl();
		HttpHeaders headers = new HttpHeaders();   
        File file = new File(filePath);
        Resource body = new FileSystemResource(file);
        // 设置响应方式
        headers.setContentType(MediaType.valueOf("video/".concat(filePath.substring(filePath.lastIndexOf('.') + 1)))); 
        headers.setContentLength(file.length());
        return new ResponseEntity<>(body,headers, HttpStatus.OK);
	}
	
}
