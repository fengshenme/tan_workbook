package tan.wei.feng.utils;

import java.util.Random;

/**
 * id
 * @author 锋什么
 *
 */
public class SimpleUtil {
	
	private SimpleUtil() {
	    throw new IllegalStateException("实用类");
	 }

	private static Random rand = new Random();	
	
	/**
	 * 主键id生成
	 * @param a 一个数据库代号
	 * @return
	 */
	public static Long idCreate() {
		// 数据库代号
		Integer a = 1 ;
		// 产生一个均匀分布随机整数之间 低到高(包括端点)
		Integer i = 10 + rand.nextInt(90);
		Long c = System.currentTimeMillis();
		String s =  c.toString() + i.toString() + a.toString();
		return Long.parseLong(s);
	}
	
	/**
	 * 
	 * @param num
	 * @return
	 * 
	 */
	public int numTransform(int num) {
		 return num < 50 && num > 0 ? num : 50;
		
	}
	
}
