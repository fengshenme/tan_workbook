package tan.wei.feng.utils;

import org.apache.commons.math3.random.RandomDataGenerator;

/**
 * id
 * @author 10159
 *
 */
public class SimpleUtil {
	
	/**
	 * 主键id生成
	 * @param a 一个数据库代号
	 * @return
	 */
	public Long idCreate() {
		// 数据库代号
		Integer a = 1 ;
		RandomDataGenerator randomDataGenerator = new RandomDataGenerator();
		// 产生一个均匀分布随机整数之间 低到高(包括端点)
		Integer i = randomDataGenerator.nextInt(10, 99);
		Long c = System.currentTimeMillis();
		String s =  c.toString() + i.toString() + a.toString();
		return Long.parseLong(s);
	}

}
