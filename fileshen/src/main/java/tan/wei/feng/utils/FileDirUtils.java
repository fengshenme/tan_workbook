package tan.wei.feng.utils;

import java.io.File;

import org.apache.commons.math3.random.RandomDataGenerator;

/**
 * 文件目录生成
 * @author 锋什么
 *
 */
public class FileDirUtils {
	
	 private FileDirUtils() {
		  throw new IllegalStateException("实用类");
	 }
	 
	/**
	 * 生成一个八层目录
	 * @param dataPath 定义存放的数据路径
	 * @param fileName 文件名
	 * @param ia 设置递归次数
	 * @return
	 */
	public static String dirFile(String dataPath,String fileName,int ia) {
		// String dataPath,String fileName
		RandomDataGenerator randomDataGenerator = new RandomDataGenerator();
		// 产生一个均匀分布随机整数之间 低到高(包括端点)
		Integer i = randomDataGenerator.nextInt(10000000, 99999999);
		String name = randomDataGenerator.nextInt(10, 99) + fileName;
		
		String hex = Integer.toString(i);
		StringBuilder bld = new StringBuilder(dataPath);
		//设置文件的保存路径
		for (int j = 0; j < hex.length(); j++) {
			bld.append("/").append(hex.charAt(j)) ;
		}
		String filePatha = bld.append("/").toString();
		String filePathb = bld.append(name).toString();
		//内存中声明一个目录
		File newDir=new File(filePatha);
		if(newDir.exists()){
			File[] files = newDir.listFiles();
			// 文件夹下可以存放文件的最大数量
			int len = 50;
			if(files.length>len) {
				// 设置递归循环次数
				ia -- ;
				if(ia!=0) {
					dirFile(dataPath,fileName,ia);
					return null;
				} else {
					return filePathb;
				}
			}
			return filePathb;
		} else {
			newDir.mkdirs();
			return filePathb;
		}
	}
	
}
