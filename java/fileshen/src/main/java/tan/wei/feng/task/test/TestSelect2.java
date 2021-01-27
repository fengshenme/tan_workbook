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

import com.alibaba.fastjson.JSON;

import tan.wei.feng.model.entity.Remark;
import tan.wei.feng.model.mapper.RemarkMapper;

/**
 * @author 10159
 *
 */
@Component
public class TestSelect2 {
	
	@Autowired
	private RemarkMapper remarkMapper = null ;
	
	private static final Logger logger = LoggerFactory.getLogger(TestSelect2.class);
	
	@Autowired
    private RedisTemplate<String, String> redisTemplate=null;
	
	private static final String REMARK_TOTAL = "remark_total";
	
//	@PostConstruct
	public void remark(){
		List<Remark> selectByP = null;
		long aa = 222;
		 selectByP = remarkMapper.selectByPagecache(aa, 100);
		
		String jsonString = JSON.toJSONString(selectByP);
		
		redisTemplate.opsForValue().set("abccct", jsonString, 5,TimeUnit.MINUTES);
		
		long starttime1 = System.currentTimeMillis();
		List<Remark> lista  =  JSON.parseArray(redisTemplate.opsForValue().get("abccct"), Remark.class);

//		for (Remark remark : lista) {
//			logger.info(remark.toString());
//		}
		System.out.println(System.currentTimeMillis() - starttime1);
		logger.info("{}-----",selectByP.get(0).getTotal().toString());
		logger.info("----------{}",selectByP.size());
		
	}
	
	
	
}
