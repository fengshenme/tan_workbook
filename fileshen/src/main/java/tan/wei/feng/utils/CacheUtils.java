/**
 * 
 */
package tan.wei.feng.utils;

import java.io.UnsupportedEncodingException;
import java.util.HashSet;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

/**
 * @author 10159
 *
 */
@Component
public class CacheUtils {
	
	private static final HashSet<String> KEYS = new HashSet<>();
	/**
	 * 设置超过600m，就开始清除
	 */
	private static final Integer MEMORYTOTAL = 1024*1024*600;
	private  Integer memorySize = 0;
	
	@Autowired
	private  RedisTemplate<String, String> redisTemplate = null;
	
	private static final Logger logger = LoggerFactory.getLogger(CacheUtils.class);
	 
		
	/**
	 * k,v,设置字符串，设置过期时间，时间单位
	 * @param key
	 * @param value
	 * @param timeout
	 * @param unit
	 */
	public void redisStringSet(String key, String value, long timeout, TimeUnit unit) {
		redisTemplate.opsForValue().set(key,value,timeout,unit);
		// 传入redis的key和存入字符串字节大小
		Integer memsize = 0 ;	
		try {
			memsize = value.getBytes("utf-8").length ;
		} catch (UnsupportedEncodingException e) {
			logger.info("计算字符串长度失败原因:{}",e.getMessage());
		}
		memorySize += memsize;
		if (memorySize >= MEMORYTOTAL) {
			redisTemplate.delete(KEYS);
			KEYS.clear();
			memorySize = 0;
		} 
		memorySize += memsize;
		KEYS.add(key);
	}
	
	/**
	 * 通过key，返回字符串
	 * @param key
	 * @return
	 */
	public String redisStringGet(String key) {
		return redisTemplate.opsForValue().get(key);
	}
	
	
}

