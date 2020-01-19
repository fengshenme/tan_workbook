package tan.wei.feng.utils;

/**
 * 简单工具,id生成,...
 * @author 1015956962
 *
 */
public class SimpleUtil {
	
	private SimpleUtil (){
		 throw new IllegalStateException("初始化失败");
	} 
	
	 private static long ti = 0 ;
	 private static int beg = 100 ;
		
		/**
		 * 生成Long型的16位数字
		 * 时间序列拼接单调递增
		 * @return
		 */
		public static Long idGenerate() {
			Long c = System.currentTimeMillis();
				if(beg >= 990) {
					try {
						Thread.sleep(1);
					} catch (InterruptedException e) {
						e.getMessage();
						Thread.currentThread().interrupt();
					}
				}
				if(c > ti) {
					ti = c;
					beg = 100;
				}
			return Long.parseLong(c + "" + beg++);
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
