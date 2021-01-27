package tan.wei.feng.model.service.create;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import tan.wei.feng.model.entity.UserFile;
import tan.wei.feng.model.mapper.FileMapper;
import tan.wei.feng.utils.IdUtil;

/**
 * 文件保存
 * @author 1015956962
 *
 */
@Service
public class FileSaveService {
	
	private static final Logger logger = LoggerFactory.getLogger(FileSaveService.class);
	@Autowired
	private  FileMapper fileMapper = null ;
	
	private static final String PNG = "png";
	private static final String JPG= "jpg";
	private static final String JPEG = "jpeg";
	private static final String MP4= "mp4";
	
	private Integer threshold = 30;
	private static final List<UserFile> FILE_SAVE_LIST= new ArrayList<> ();
	
	/**
	 * 文件保存synchronized
	 * @param file
	 * @param id
	 */
	public boolean addFile(String filePath,String userId) {
		UserFile userFile = new UserFile();
        userFile.setId(IdUtil.getInstance().idGenerate());
        userFile.setUserid(Long.parseLong(userId));
		userFile.setFileurl(filePath);
		userFile.setAddtime(new Date());
		String fileType = filePath.substring(filePath.lastIndexOf('.') + 1);
		// 1代表图片2代表视频3代表其它
		if(PNG.equals(fileType)||JPG.equals(fileType)||JPEG.equals(fileType)) {
			userFile.setFiletype(1);
		}else if(MP4.equals(fileType)){
			userFile.setFiletype(2);
		}else {
			userFile.setFiletype(3);
		}
        try {
    		if(threshold <= 0) {
    			FILE_SAVE_LIST.add(userFile);
            	threshold--;
    		} else {
    			fileMapper.insert("UserFile",userFile);
    		}
            return true ;
        } catch (Exception e) {
        	fileMapper.deleteByPrimaryKey("UserFile",userFile.getId());
        	logger.error("error",e);
            return false ;
        } 
	}

	/**
	 * 定时提交
	 */
	@Scheduled(cron= "0/1 * * * * ?")
	private void saveall() {
		if(!FILE_SAVE_LIST.isEmpty()) {
			fileMapper.insertAll("UserFile",FILE_SAVE_LIST);
			FILE_SAVE_LIST.clear();
		}
		threshold = 30;
	}
	
}
