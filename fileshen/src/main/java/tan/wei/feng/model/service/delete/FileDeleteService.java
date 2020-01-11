package tan.wei.feng.model.service.delete;

import java.io.File;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.UserFile;
import tan.wei.feng.model.mapper.FileMapper;

/**
 * 文件删除服务
 * @author 1015956962@163.com
 *
 */
@Service
public class FileDeleteService {
	
	@Autowired
	private FileMapper fileMapper = null;
	
	/**
	 * 
	 * 删除文件
	 * @param fileId
	 * @return
	 */
	public  boolean delfile(Long fileId) {
		UserFile filefindById = fileMapper.selectByPrimaryKey("UserFile",fileId);
		if (filefindById != null && !"".equals(filefindById.getFileurl().trim())) {
	        File file = new File(filefindById.getFileurl());
	        if(file.delete()) {
	        	fileMapper.deleteByPrimaryKey("UserFile",fileId);
	        } 
	        return true;
        } else {
        	return false;
        }
	}
	
}
