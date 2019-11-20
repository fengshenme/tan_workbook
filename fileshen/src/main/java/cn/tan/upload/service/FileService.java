package cn.tan.upload.service;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import cn.tan.upload.entity.PageResult;
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
	private FileMapper fileMapper = null;
	
	
	/**
	 * 根据资源id返回文件下载
	 * @param fileId
	 * @return
	 * @throws IOException 
	 */
	public ResponseEntity<byte[]> fileDownload(String fileId) throws IOException {
		HttpHeaders headers = new HttpHeaders();  
		Optional<UserFile> filefindById = fileMapper.findById(Long.parseLong(fileId));
		if (filefindById.isPresent()) {
			String filePath = filefindById.get().getFileurl();
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
	
	/**
	 * 根据用户id查询名下所有资源
	 * @param id
	 */
	public List<Long> findByfileid(String userid ,String fileType) {
		List<Long> list = new ArrayList<>();
		for (Long filecode : fileMapper.selectByIdaa(Long.parseLong(userid),fileType)) {
			list.add(filecode);
		}
		return list ;
	}
	
	
	/**
	 * 
	 * 删除文件
	 * @param fileId
	 * @return
	 */
	public  boolean delfile(Long fileId) {
		Optional<UserFile> filefindById = fileMapper.findById(fileId);
		if (filefindById.isPresent()) {
	        File file = new File(filefindById.get().getFileurl());
	        if(file.delete()) {
	        	fileMapper.deleteById(fileId);
	        } 
	        return true;
        } else {
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
	public PageResult<String> findByfileidPage(String id, String fileType, Map<String, String> map) {
		int page = Integer.parseInt(map.get("page"));
		int size = Integer.parseInt(map.get("limit"));
		 Page<Long> findByUseridAndFiletype = fileMapper.findByUseridAndFiletype(Long.parseLong(id),fileType, PageRequest.of(page-1,size));
		 
		 String[] strlist = findByUseridAndFiletype.getContent().toString().split(",");
		 ArrayList<String> arrayList = new ArrayList<>();
		 for (String string : strlist) {
			 arrayList.add(string.replace("[", "").replace("]", "").trim());
		}
		return new PageResult<>(findByUseridAndFiletype.getTotalElements(),arrayList);
	}

}
 