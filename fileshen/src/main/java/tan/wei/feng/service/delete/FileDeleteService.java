package tan.wei.feng.service.delete;

import java.io.File;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.UserFile;
import tan.wei.feng.mapper.FileMapper;

/**
 * 文件删除服务
 * @author 锋什么
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
	
}
