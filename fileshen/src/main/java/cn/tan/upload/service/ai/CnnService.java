package tan.wei.feng.service.ai;

import java.io.File;
import java.io.IOException;
import java.util.Map;
import java.util.Random;

import org.deeplearning4j.models.embeddings.loader.WordVectorSerializer;
import org.deeplearning4j.models.embeddings.wordvectors.WordVectors;
import org.deeplearning4j.nn.graph.ComputationGraph;
import org.deeplearning4j.util.ModelSerializer;
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import tan.wei.feng.utils.CnnUtil;
import tan.wei.feng.utils.IKUtil;


/*** 
 * 人工智能分类模型 
 * @author 1S
 * */
@Service
public class CnnService {
	
	//词向量模型 
	@Value("${ai.vecModel}") 
	private String vecModel; 
	//训练模型结果保存路径 
	@Value("${ai.cnnModel}") 
	private String cnnModel; 
	//爬虫分词后的数据路径 
	@Value("${ai.dataPath}") 
	private String dataPath; 
	
	/** 
	 * 返回map集合 分类与百分比 * 
	 * @param content * 
	 * @return 
	 * */ 
	public Map<String, Double> textClassify(String content) { 
		//分词 
		try {
			content= IKUtil.split(content," "); 
		} catch (IOException e) { 
			e.printStackTrace(); 
		}
		String[] childPaths={"java","DB","web","python",}; 
		//获取预言结果 
		Map<String, Double> map = null; 
		try {
			map = CnnUtil.predictions(vecModel, cnnModel, dataPath, childPaths, content); 
		} catch (IOException e) { 
			e.printStackTrace(); 
		}
		return map; 
	}
	
	/**
	 *  构建卷积模型  
	 * @return 
	 * */ 
	public boolean build(){
		try{
			//创建计算图对象 
			ComputationGraph net = CnnUtil.createComputationGraph(100); 
			//加载词向量 训练数据集 
			WordVectors wordVectors = WordVectorSerializer.loadStaticModel(new File(vecModel));
			String[] childPaths={"java","DB","web","python"}; 
			// path 数据集所在目录  childPaths 子目录 wordVectors 词向量模型 minibatchSize 最小批处理数量32  maxSentenceLength 最大句子长度256 rng 随机种子 
			DataSetIterator trainIter = CnnUtil.getDataSetIterator(dataPath,childPaths, wordVectors, 32, 256, new Random(12345)); 
			//模型训练 
			net.fit(trainIter); 
			//保存模型之前先删除 
			new File(cnnModel).delete(); 
			//保存模型 
			ModelSerializer.writeModel(net,cnnModel,true); 
			return true; 
			}catch (Exception e){
				e.printStackTrace(); 
			}
		return false; 
	}
}
