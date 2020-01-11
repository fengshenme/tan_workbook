package tan.wei.feng.utils;

import java.util.ArrayList;
import java.util.List;

/**
 * 简单工具,id生成,...
 * @author 1015956962@163.com
 *
 */
public class SimpleUtil {
	
	/**
	 * 这样定义初始化后,作用阈值就跟基本数据类型一样,到最大加一则变为最小
	 * 就不会有索引溢出的问题
	 */
	private static final List<Integer> NUMLIST = new ArrayList<> (800);
	
	private static int nu = 0;
	
	/**
	 * 主键id生成
	 * @return
	 */
	public static Long idCreate() {
		Long c = System.currentTimeMillis();
		List<Integer> i = genNum(100,900);
		return Long.parseLong(c +"" + i.get(nu++));
	}
	
	/***
	 * 生成递增数的列表
	 * @param beg
	 * @param end
	 * @return
	 */
	public static List<Integer> genNum(int beg,int end) {
		for (int i = beg; i < end; i++) {
			NUMLIST.add(i);
		}
		return NUMLIST ;
	}
	
	/**
	 * 去除拼接后最后一个逗号
	 * @param cona
	 * @return
	 */
	public static String rmComma(StringBuilder cona) {
		String str = cona.toString();
		return str.substring(0, str.lastIndexOf(','));
	}
	
	/**
	 * 数值检测
	 * @param num
	 * @return
	 * 
	 */
	public int numTransform(int num) {
		 return num < 50 && num > 0 ? num : 50;
		
	}
	
}
