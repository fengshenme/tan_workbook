package cn.tan.upload.service;

import java.util.ArrayList;
import java.util.Date;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import cn.tan.upload.entity.Testinsert;
import cn.tan.upload.mapper.TestMapper;

@Service
public class TestService {
	
	
	@Autowired
	private TestMapper testMapper=null;
	
	
	ArrayList<Testinsert> arrayList = new ArrayList<> ();
	
	public void testSave(Testinsert testinsert) {
		testinsert.setAddtime(new Date());
		arrayList.add(testinsert);
		if(arrayList.size() >10) {
			testMapper.saveAll(arrayList);
			arrayList.clear();
		}	
	}
	
	@Scheduled(cron= "0/1 * * * * ?")
	public void saveall() {
		if(!arrayList.isEmpty()) {
			testMapper.saveAll(arrayList);
			arrayList.clear();
		}
	}
}
