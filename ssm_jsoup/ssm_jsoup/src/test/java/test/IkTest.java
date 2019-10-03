package test;

import java.util.Iterator;

import org.junit.Test;

import cn.hutool.core.collection.CollUtil;
import cn.hutool.extra.tokenizer.Result;
import cn.hutool.extra.tokenizer.Word;
import cn.hutool.extra.tokenizer.engine.ikanalyzer.IKAnalyzerEngine;

public class IkTest {
	
	@Test
	public void  testIk () {
		String ab = "Hutool是Hu + tool的自造词，前者致敬我的“前任公司”，后者为工具之意，谐音“糊涂”，寓意追求“万事都作糊涂观，无所谓失，无所谓得”的境界。";
		IKAnalyzerEngine ikAnalyzerEngine = new IKAnalyzerEngine();
		Result ac = ikAnalyzerEngine.parse(ab);
		String resultStr = CollUtil.join((Iterator<Word>)ac, " ");
		System.out.println(resultStr);
	} 
	
	
}
