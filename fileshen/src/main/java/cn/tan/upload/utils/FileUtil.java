package tan.wei.feng.utils;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List; 
/**
 *  文件工具类 
 *  @author 10
 */ 
public class FileUtil { 
	
	/**
	 * * 将多个文本文件合并为一个文本文件 
	 * * @param outFileName *
	 *  @param inFileNames * 
	 *  @throws IOException 
	 */ 
	public static void merge(String outFileName ,List<String> inFileNames) throws IOException {
		FileWriter writer = new FileWriter(outFileName, false); 
		for(String inFileName :inFileNames ){ 
			try {
				String txt= readToString(inFileName);
				writer.write(txt); 
				}catch (Exception e){ 
				} 
			}
		writer.close(); 
	}
	
	/**
	 * 这是一个新方法,旧方法合并的文件编码有问题,将多个文本文件合并为一个文本文件
	 * @param fileName
	 * @param inFileNames
	 * @throws IOException
	 */
	public static void writerFilemerge(String fileName,Iterable<String> inFileNames) throws IOException {
		Path path = Paths.get(fileName); 
	    // Collection<String> Iterable<String>
	    //try (BufferedWriter reader = Files.newBufferedWriter(path, StandardCharsets.UTF_8,StandardOpenOption.CREATE)) {
	    try (BufferedWriter reader = Files.newBufferedWriter(path, StandardCharsets.UTF_8)) {
	    	//reader.write("");
	    	for(String inFileName :inFileNames ){
			    	String txt= readToString(inFileName);
			    	reader.append(txt);
		    }
	    	reader.flush();
	    	reader.close();
	    }catch (Exception e){ 
			e.printStackTrace();
		}
	 }
	
	/**
	 * * 查找某目录下的所有文件名称 
	 * * @param path * 
	 * @return 
	 */ 
	public static List<String> getFiles(String path) { 
		List<String> files = new ArrayList<String>();
		File file = new File(path); 
		File[] tempList = file.listFiles(); 
		for (int i = 0; i < tempList.length; i++) { 
			if (tempList[i].isFile()) {
				//如果是文件 
				files.add(tempList[i].toString()); 
				}
			if (tempList[i].isDirectory()) {
				//如果是文件夹 
				files.addAll( getFiles(tempList[i].toString()) ); 
				} 
			}
		return files; 
		}
	
	/**
	 * 读取文本文件内容到字符串  
	 * @param fileName 
	 * @return 
	 */ 
	public static String readToString(String fileName) throws IOException { 
		String encoding = "UTF-8"; 
		File file = new File(fileName); 
		Long filelength = file.length(); 
		byte[] filecontent = new byte[filelength.intValue()]; 
		FileInputStream in = new FileInputStream(file); 
		in.read(filecontent); 
		in.close(); 
		return new String(filecontent, encoding); 
	}
	
}
































