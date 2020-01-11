package tan.wei.feng.model.service.read;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.PageResult;
import tan.wei.feng.entity.UserFile;
import tan.wei.feng.model.mapper.FileMapper;

/**
 * 文件查寻服务
 * @author 1015956962@163.com
 *
 */
@Service
public class FileFindService {
	
	@Autowired
	private FileMapper fileMapper = null;
	
	
	public void testaa() {
		int filetype = 6;
		String userid = "1574598104377731" ; 
		Object countby = fileMapper.countByFiletypeAndUserid(filetype,Long.parseLong(userid) );
		System.out.println(countby.toString());
		
	}
	
	
	/**
	 * 分页查询
	 * @param id
	 * @param fileType
	 * @param map
	 * @return
	 */
	public PageResult<UserFile> findByfileidPage(String id, Integer fileType, Integer page, Integer pagesize) {
		Page<UserFile> findFilePage = fileMapper.findByUseridAndFiletype(Long.parseLong(id),fileType, PageRequest.of(page-1,pagesize));
		return new PageResult<>(findFilePage.getTotalElements(),findFilePage.getContent());
	}
	
	
	/**
	 * 根据用户id查询名下所有资源
	 * @param id
	 */
	public List<Long> findByfileid(String userid ,Integer fileType) {
		return fileMapper.selectByIdaa(Long.parseLong(userid),fileType);
	}
	
	
}
