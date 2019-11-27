package tan.wei.feng.task;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import tan.wei.feng.service.ai.CnnService;
import tan.wei.feng.service.ai.Word2VecService;

/**
 * *
 *  训练任务类 
 *  @author 10
 */ 
@Component 
public class TrainTask {
	
	private static final Logger logger = LoggerFactory.getLogger(TrainTask.class);
	
	@Autowired 
	private Word2VecService word2VecService = null; 
	
	@Autowired
	private CnnService cnnService = null;
	
	/**
	 * 训练模型 
	 */ 
	//@Scheduled(cron="30 55 * * * ?") 
	public void trainModel(){ 
		
		logger.info("开始合并语料库......"); 
		word2VecService.mergeWord(); 
		logger.info("合并语料库结束‐‐‐‐‐‐"); 
		
		logger.info("开始构建词向量模型"); 
		word2VecService.build(); 
		logger.info("构建词向量模型结束");
		
		logger.info("开始构建神经网络卷积模型"); 
		cnnService.build(); 
		logger.info("构建神经网络卷积模型结束");
		
	}
	
}
