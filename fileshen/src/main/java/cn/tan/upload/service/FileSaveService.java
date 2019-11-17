package cn.tan.upload.service;

import java.util.ArrayList;
import java.util.Date;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.UserFile;
import cn.tan.upload.mapper.FileMapper;

/**
 * 文件保存业务层
 * @author 10159
 *
 */
@Service
public class FileSaveService {
	
	
	@Autowired
	private FileMapper fileMapper = null;
	
	ArrayList<UserFile> arrayList = new ArrayList<> ();
	
	/**
	 * 文件保存synchronized
	 * @param file
	 * @param id
	 */
	public boolean addFile(String filePath,String userId) {
		UserFile userFile = new UserFile();
        userFile.setId(IdUtil.getSnowflake(1, 1).nextId());
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
        	arrayList.add(userFile);
    		if(arrayList.size() >10) {
    			fileMapper.saveAll(arrayList);
    			arrayList.clear();
    		}
            return true ;
        } catch (Exception e) {
        	fileMapper.deleteById(userFile.getId());
            e.printStackTrace();
            return false ;
        } 
	}
	
	@Scheduled(cron= "0/1 * * * * ?")
	public void saveall() {
		if(!arrayList.isEmpty()) {
			fileMapper.saveAll(arrayList);
			arrayList.clear();
		}
	}
	
}
