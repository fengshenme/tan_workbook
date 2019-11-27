package tan.wei.feng.service;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import tan.wei.feng.entity.Testinsert;
import tan.wei.feng.mapper.TestMapper;

@Service
public class TestService {
	
	private static final Logger logger = LoggerFactory.getLogger(TestService.class);
	private TestMapper testMapper=null;
	List<Testinsert> arrayList = new ArrayList<> ();
	private Integer threshold = 30;
	
	
	@Autowired
	public TestService(TestMapper testMapper, List<Testinsert> arrayList) {
		this.testMapper = testMapper;
		this.arrayList = arrayList;
	}

	public void testSave(Testinsert testinsert) {
		testinsert.setAddtime(new Date());
		logger.info("{}",threshold.toString());
		threshold--;
		if(threshold<=0) {
			arrayList.add(testinsert);
		} else {
			testMapper.save(testinsert);
		}
	}
	
	@Scheduled(cron= "0/1 * * * * ?")
	private void saveall() {
		if(!arrayList.isEmpty()) {
			testMapper.saveAll(arrayList);
			arrayList.clear();
		}
		threshold = 30;
	}
}
