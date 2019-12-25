package tan.wei.feng.service.read;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.PageResult;
import tan.wei.feng.entity.UserFile;
import tan.wei.feng.mapper.FileMapper;

@Service
public class FileFindService {
	
	@Autowired
	private FileMapper fileMapper = null;
	
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
	
//	public Map<Integer,List<UserFile>> findByfileidPage(String id, Integer fileType, Integer page, Integer pagesize) {
//		Page<UserFile> findFilePage = fileMapper.findByUseridAndFiletype(Long.parseLong(id),fileType, PageRequest.of(page-1,pagesize));
//		Map<Integer,List<UserFile>> map = new HashMap<>();
//		map.put((int) findFilePage.getTotalElements(),findFilePage.getContent());
//		return map;
//	}
	
	/**
	 * 根据用户id查询名下所有资源
	 * @param id
	 */
	public List<Long> findByfileid(String userid ,Integer fileType) {
		return fileMapper.selectByIdaa(Long.parseLong(userid),fileType);
	}
	
	
}
