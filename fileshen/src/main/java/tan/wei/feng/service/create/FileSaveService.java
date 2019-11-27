package tan.wei.feng.service.create;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.UserFile;
import tan.wei.feng.mapper.FileMapper;
import tan.wei.feng.utils.SimpleUtil;

/**
 * 文件保存业务
 * @author 10159
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
	
	private int threshold = 30;
	List<UserFile> fileSaveList = new ArrayList<> ();
	
	/**
	 * 文件保存synchronized
	 * @param file
	 * @param id
	 */
	public boolean addFile(String filePath,String userId) {
		UserFile userFile = new UserFile();
		SimpleUtil simpleUtil = new SimpleUtil();
        userFile.setId(simpleUtil.idCreate());
        userFile.setUserid(Long.parseLong(userId));
		userFile.setFileurl(filePath);
		userFile.setAddtime(new Date());
		String fileType = filePath.substring(filePath.lastIndexOf('.') + 1);
		// 1代表图片2代表视频3代表其它
		if(PNG.equals(fileType)||JPG.equals(fileType)||JPEG.equals(fileType)) {
			userFile.setFiletype("1");
		}else if(MP4.equals(fileType)){
			userFile.setFiletype("2");
		}else {
			userFile.setFiletype("3");
		}
        try {
    		if(threshold<=0) {
    			fileSaveList.add(userFile);
            	threshold--;
    		} else {
    			fileMapper.save(userFile);
    		}
            return true ;
        } catch (Exception e) {
        	fileMapper.deleteById(userFile.getId());
        	logger.error("error",e);
            return false ;
        } 
	}

	/**
	 * 定时提交
	 */
	@Scheduled(cron= "0/1 * * * * ?")
	private void saveall() {
		if(!fileSaveList.isEmpty()) {
			fileMapper.saveAll(fileSaveList);
			fileSaveList.clear();
		}
		threshold = 30;
	}
	
}
