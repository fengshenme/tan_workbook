package cn.tan.upload.task;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;
import cn.hutool.core.util.IdUtil;
import cn.tan.upload.entity.Testinsert;
import cn.tan.upload.service.TestService;

@Component
public class TestTask {
	
	@Autowired
	private TestService testService=null;
	
	private int ia = 0;
	
	//@Scheduled(cron= "20 45 * * * ?")
	public void testInsert() {
		
		for (int i = 0; i < 3000; i++) {
			Testinsert testinsert = new Testinsert();
			testinsert.setId(IdUtil.getSnowflake(1, 1).nextId());
			testinsert.setNumber((long) ia++);
			testService.testSave(testinsert);
		}
		
	}
	
}
