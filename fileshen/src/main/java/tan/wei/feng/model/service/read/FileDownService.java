package tan.wei.feng.model.service.read;

import java.io.File;
import java.io.IOException;

import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.UserFile;
import tan.wei.feng.model.mapper.FileMapper;

/**
 * file业务层
 * @author 1015956962@163.com
 *
 */
@Service
public class FileDownService {
	
	@Autowired
	private FileMapper fileMapper = null;
	
	
	/**
	 * 根据资源id返回文件下载
	 * @param fileId
	 * @return
	 * @throws IOException 
	 */
	public ResponseEntity<byte[]> fileDownload(String fileId) throws IOException {
		HttpHeaders headers = new HttpHeaders();  
		UserFile filefindById = fileMapper.selectByPrimaryKey("UserFile",Long.parseLong(fileId));
		if (filefindById != null) {
			String filePath = filefindById.getFileurl();
			File file = new File(filePath);
	        String fileName = filePath.substring(filePath.lastIndexOf('/'));
	        // 设置响应方式
	        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
	        //设置响应文件
	        headers.setContentDispositionFormData("attachment", fileName); 
	        headers.setContentLength(file.length());
	        return new ResponseEntity<>(FileUtils.readFileToByteArray(file), headers, HttpStatus.OK);
		}else {
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
          
	}
	
	
	

}
 