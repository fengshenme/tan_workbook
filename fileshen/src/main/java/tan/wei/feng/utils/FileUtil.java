package tan.wei.feng.utils;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory; 
/**
 *  文件工具类 
 *  @author 10
 */ 
public class FileUtil { 
	
	private static final Logger logger = LoggerFactory.getLogger(FileUtil.class);
	
	 private FileUtil() {
	    throw new IllegalStateException("实用类");
	  }
	
	/**
	 * 将多个文本文件合并为一个文本文件
	 * @param fileName
	 * @param inFileNames
	 * @throws IOException
	 */
	public static void writerFilemerge(String fileName,Iterable<String> inFileNames) {
		Path path = Paths.get(fileName); 
	    try (BufferedWriter writer = Files.newBufferedWriter(path, StandardCharsets.UTF_8)) {
	    	for(String inFileName :inFileNames ){
			    	String txt= readToString(inFileName);
			    	writer.append(txt);
		    }
	    	writer.flush();
	    }catch (IOException e){ 
			logger.info("文本文件合并出错".concat(e.getMessage()));
		}
	 }
	
	/**
	 * * 查找某目录下的所有文件名称 
	 * * @param path * 
	 * @return 
	 */ 
	public static List<String> getFiles(String path) { 
		List<String> files = new ArrayList<>();
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
	public static String readToString(String fileName) { 
		File file = new File(fileName); 
		StringBuilder stringBuilder = new StringBuilder();
		String line = "";
		// 将filereader链接到bufferedreader以获取更高效率,它只会在缓存区读空时才会回头去磁盘读取
		try(FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);) {
			while((line = bufferedReader.readLine() ) != null) {
				stringBuilder.append(line + "\n");
			}
		} catch (FileNotFoundException e) {
			logger.info("没有找到这个文件:".concat(e.getMessage()));
		} catch (IOException ie) {
			logger.info("读取文本文件异常:".concat(ie.getMessage()));
		}
		return stringBuilder.toString();
	}
	
}
































