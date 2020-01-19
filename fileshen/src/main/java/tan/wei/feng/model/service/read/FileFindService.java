package tan.wei.feng.model.service.read;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import tan.wei.feng.model.entity.PageResult;
import tan.wei.feng.model.entity.UserFile;
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
	
	@Autowired
	private RedisTemplate<String, String> redisTemplate=null ;
	
	
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
	public PageResult<UserFile> findByfileidPage(String fileid, Integer fileType, Integer page, Integer pagesize) {
		
		List<UserFile> selectByPageTotal = null;
		String total = redisTemplate.opsForValue().get("findByfileidPage_total");
		
		ArrayList<String> arrayList = new ArrayList<>();
		Integer pageIndex = (page-1)*pagesize ;
		arrayList.add(pageIndex.toString());
		arrayList.add(pagesize.toString());
		arrayList.add(fileid);
		arrayList.add(fileType.toString());
		if(total == null || "".equals(total )) {
			selectByPageTotal = fileMapper.selectByPageTotal("UserFile,userid,filetype",arrayList);
			redisTemplate.opsForValue().set("findByfileidPage_total", selectByPageTotal.get(0).getTotal().toString(), 5,TimeUnit.MINUTES);
		} else {
			selectByPageTotal = fileMapper.selectByPage("Remark,userid,filetype", arrayList);
		}
		
		PageResult<UserFile> pageResult = new PageResult<>();
		pageResult.setTotal(selectByPageTotal.get(0).getTotal());
		pageResult.setRows(selectByPageTotal);
		return pageResult;
	}
	
	
	/**
	 * 根据用户id查询名下所有资源
	 * @param id
	 */
	public List<Long> findByfileid(String userid ,Integer fileType) {
		return fileMapper.selectByIdaa(Long.parseLong(userid),fileType);
	}
	
	
}
