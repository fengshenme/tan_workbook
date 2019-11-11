package cn.tan.upload.utils;

import java.io.File;

import org.apache.commons.math3.random.RandomDataGenerator;

public class FileDirUtils {
	
	
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
			if(files.length>50) {
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
	
	
	
	/**
	 * 生成唯一目录
	 * @param dataPath 定义存放的数据路径
	 * @param fileName 文件名
	 * @return
	 */
	public static String dirFile0(String dataPath,String fileName) {
		String name = new RandomDataGenerator().nextInt(0, 100) + fileName;
		int i = name.hashCode();
		//将hash码转成16进制的字符串
		String hex = Integer.toHexString(i);
		System.out.println(hex);
		int j=hex.length();
		System.out.println(j);
		for(int k=0;k<8-j;k++){
			hex="0"+hex;
		}
		System.out.println(hex);
		//设置文件的保存路径
		String filePatha = dataPath + "/"+hex.charAt(0)+"/"+hex.charAt(1)+"/"+hex.charAt(2)+"/"+
							hex.charAt(3)+"/"+hex.charAt(4)+"/"+hex.charAt(5)
							+"/"+hex.charAt(6)+"/"+hex.charAt(7)+"/";
		//内存中声明一个目录
		File newDir=new File(filePatha);
		if(!newDir.exists()){
			newDir.mkdirs();
		}
		return filePatha +name;
	}
	
}
