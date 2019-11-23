package tan.wei.feng.task;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import tan.wei.feng.entity.Testinsert;
import tan.wei.feng.service.TestService;
import tan.wei.feng.utils.SimpleUtil;

@Component
public class TestTask {
	
	@Autowired
	private TestService testService=null;
	
	private int ia = 0;
	
	//@Scheduled(cron= "0/5 * * * * ?")
	public void testInsert() {
		for (int i = 0; i < 10; i++) {
			Testinsert testinsert = new Testinsert();
			SimpleUtil simpleUtil = new SimpleUtil();
			testinsert.setId(simpleUtil.idCreate());
			testinsert.setNumber((long) ia++);
			testService.testSave(testinsert);
		}
		
	}
	
}
