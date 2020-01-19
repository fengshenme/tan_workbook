/**
 * 
 */
package tan.wei.feng.task.test;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

import tan.wei.feng.model.entity.Remark;
import tan.wei.feng.model.mapper.RemarkMapper;

/**
 * @author 10159
 *
 */
@Component
public class TestSelect {
	
	@Autowired
	private RemarkMapper remarkMapper = null ;
	
	private static final Logger logger = LoggerFactory.getLogger(TestSelect.class);
	
	@Autowired
    private RedisTemplate<String, String> redisTemplate=null;
	
	private static final String REMARK_TOTAL = "remark_total";
	
	@PostConstruct
	public void remark() {
		
		List<Remark> selectByPageTotal = null;
		String total = redisTemplate.opsForValue().get(REMARK_TOTAL);
		ArrayList<String> arrayList = new ArrayList<>();
		Integer page = 0;
		Integer pagesize = 10;
		Integer pageIndex = page*pagesize ;
		arrayList.add(pageIndex.toString());
		arrayList.add(pagesize.toString());
		arrayList.add("github_36519260");
		if(total != null && !"".equals(total )) {
			selectByPageTotal = remarkMapper.selectByPage("Remark,user_name", arrayList);
			total = redisTemplate.opsForValue().get(REMARK_TOTAL);
			selectByPageTotal.get(0).setTotal(Integer.parseInt(total));
		} else {
			selectByPageTotal = remarkMapper.selectByPageTotal("Remark,user_name", arrayList);
			redisTemplate.opsForValue().set(REMARK_TOTAL, selectByPageTotal.get(0).getTotal().toString(), 5,TimeUnit.MINUTES);
		}
		
		if(!selectByPageTotal.isEmpty()) {
			logger.info("aaaaaaaaaaa");
			logger.info("{}",selectByPageTotal.get(0).toString());
		}
		
	}
	
	
	
}
