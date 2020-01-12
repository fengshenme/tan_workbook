/**
 * 
 */
package tan.wei.feng.utils;

/**
 * 时间毫秒拼接单调递增的三位数<br>
 * 用的急切版单例模式
 * @author 1015956962
 *
 */
public class IdUtil {
	
	private IdUtil (){ } 
	private static final IdUtil IDUTIL = new IdUtil();
    public static IdUtil getIdUtil() {  
	    return IDUTIL; 
	}
	    
    private long ti = 0 ;
	private int beg = 100 ;
	
	/**
	 * 生成Long型的16位数字<br>
	 * 时间序列拼接单调递增
	 * @return
	 */
	public Long idGenerate() {
		Long c = System.currentTimeMillis();
			if(c != ti) {
				ti = c;
				beg = 100;
			} 
			if(beg >= 990) {
				try {
					Thread.sleep(1);
				} catch (InterruptedException e) {
					e.getMessage();
					Thread.currentThread().interrupt();
				}
			}
		return Long.parseLong(c + "" + beg++);
	}
		
}
