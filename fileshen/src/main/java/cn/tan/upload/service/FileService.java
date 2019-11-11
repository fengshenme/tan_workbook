package cn.tan.upload.service;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Map;

import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.UserFile;
import cn.tan.upload.mapper.FileMapper;

/**
 * file业务层
 * @author 10159
 *
 */
@Service
public class FileService {
	
	@Autowired
	private FileMapper fileMapper;
	
	@Autowired
	private UserFile userFile;
	
	/**
	 * 根据资源id返回文件下载
	 * @param fileId
	 * @return
	 * @throws IOException 
	 */
	public ResponseEntity<byte[]> fileDownload(String fileId) throws IOException {
		HttpHeaders headers = new HttpHeaders();   
        String filePath = fileMapper.findById(fileId).get().getFileurl();
        File file = new File(filePath);
        String fileName = filePath.substring(filePath.lastIndexOf('/'));
        // 设置响应方式
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        //设置响应文件
        headers.setContentDispositionFormData("attachment", fileName); 
        headers.setContentLength(file.length());
        return new ResponseEntity<>(FileUtils.readFileToByteArray(file), headers, HttpStatus.OK);  
	}
	
	/**
	 * 根据用户id查询名下所有资源
	 * @param id
	 */
	public List<String> findByfileid(String id ,String fileType) {
		List<String> list = new ArrayList<>();
		for (String filecode : fileMapper.selectByIdaa(id,fileType)) {
			list.add(filecode);
		}
		return list ;
	}
	
	/**
	 * 文件保存
	 * @param file
	 * @param id
	 */
	public synchronized boolean addFile(String filePath,String userId) {
			String nextId = IdUtil.getSnowflake(1, 1).nextIdStr();
            userFile.setId(nextId);
            userFile.setUserid(userId);
    		userFile.setFileurl(filePath);
    		userFile.setAddtime(new Date());
    		String fileType = filePath.substring(filePath.lastIndexOf('.') + 1);
    		// 1代表图片2代表视频3代表其它
    		if("png".equals(fileType)||"jpg".equals(fileType)||"jpeg".equals(fileType)) {
    			userFile.setFiletype("1");
    		}else if("mp4".equals(fileType)){
    			userFile.setFiletype("2");
    		}else {
    			userFile.setFiletype("3");
    		}
	        try {
	            fileMapper.save(userFile);
	            return true ;
	        } catch (Exception e) {
	        	fileMapper.deleteById(userFile.getId());
	            e.printStackTrace();
	            return false ;
	        } 
	}
	
	/**
	 * 
	 * 删除文件
	 * @param fileId
	 * @return
	 */
	public  boolean delfile(String fileId) {
		String filePath = fileMapper.findById(fileId).get().getFileurl();
        File file = new File(filePath);
        if(file.delete()) {
        	fileMapper.deleteById(fileId);
        	return true;
        }else {
        	return false;
        }  
	}
	
	/**
	 * 分页查询
	 * @param id
	 * @param fileType
	 * @param map
	 * @return
	 */
	public Page<UserFile> findByfileidPage(String id, String fileType, Map<String, String> map) {
		int page = Integer.parseInt(map.get("page"));
		int size = Integer.parseInt(map.get("limit"));
		return fileMapper.findByUseridAndFiletype(id,fileType, PageRequest.of(page-1,size));
	}

}
 