package tan.wei.feng.task.test;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashSet;
import java.util.List;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Component;

import tan.wei.feng.model.entity.User;
import tan.wei.feng.model.mapper.UserMapper;
import tan.wei.feng.utils.IdUtil;


/**
 * 实验类
 * @author 1015956962
 *
 */
@Component
public class TestInesrt {
	
	@Autowired
	private UserMapper userMapper = null ;
	
	private static final  Logger logger = LoggerFactory.getLogger(TestInesrt.class);
	
	private static final List<User> USER = new ArrayList<> ();
	
	
	public void remarkInesrt() {
		ArrayList<Long> arrayList = new ArrayList<> (10000);	
		int t = 0 ;
		int beg = 1000;
		int end = 10;
		int ss = 361472900;
		for (int cc = 0; cc < beg; cc++) {
			// 一定要记得清除
			USER.clear();
			long startTime = 0;
			long endTime = 0;
			for (int i = 0; i < end; i++) {
				User user = new User();
				user.setEmail("1015956962@163.com");
				user.setNickname("测试数据");
				 startTime = System.currentTimeMillis();
				user.setPassword(new BCryptPasswordEncoder().encode("123456"));
				 endTime = System.currentTimeMillis();
				user.setSex(1);
				user.setMobile(""+ ss++);
				Long idGenerate = IdUtil.getInstance().idGenerate();
				user.setId(idGenerate);
				user.setUpdateTime(new Date());
				USER.add(user);
//				arrayList.add(idGenerate);
//				userMapper.insert(user);
				// 01:40:30
				
			}
			
			
			if(ss%100 == 0) {
				System.out.println("插入1000条");
				System.out.println(ss);
			}
			
			logger.info("{}",endTime - startTime);
				userMapper.insertAll("User",USER);
			
		}
		HashSet<Long> hashSet = new HashSet<>(arrayList);
		logger.info("重复id数: {}",beg*end - hashSet.size());
		logger.info("保存失败数:{}",t);
	}
	
	
	
}
