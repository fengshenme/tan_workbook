package cn.tan.upload.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * 实用类
 * @author 10159
 *
 */
public class ReadWriterFileUtils {
	
	private ReadWriterFileUtils() {
	    throw new IllegalStateException("实用类");
	}
	
	/**
	 * 写入文件 编码GB18030
	 * @param ff
	 * @throws IOException
	 */
	public static void writer(String ff,String filePath) throws IOException {
		File file = new File(filePath);
		FileOutputStream fop = null;
		if(!file.exists()){
			// 构建FileOutputStream对象,文件不存在会自动新建
            fop = new FileOutputStream(file);//首次写入获取
        }else{
            //如果文件已存在，那么就在文件末尾追加写入
        	//这里构造方法多了一个参数true,表示在文件末尾追加写入
        	fop = new FileOutputStream(file,true);
        }
		// 构建OutputStreamWriter对象,参数可以指定编码,默认为操作系统默认编码,windows上是gbk
        OutputStreamWriter writer = new OutputStreamWriter(fop,"GB18030");
        // 写入到缓冲区
        writer.append(ff);
        // 换行
        writer.append("\r\n");
        // 刷新缓存冲,写入到文件,如果下面已经没有写入的内容了,直接close也会写入
        writer.close();
        // 关闭写入流,同时会把缓冲区内容写入文件,所以上面的注释掉
        fop.close();
        // 关闭输出流,释放系统资源
	}
	
	/**
	 * 读取文件
	 * @param f
	 * @throws IOException
	 */
	public static void read(String f) throws IOException{
		// 构建FileInputStream对象 
        FileInputStream fip = new FileInputStream(f);
        // 构建InputStreamReader对象,编码与写入相同
        InputStreamReader reader = new InputStreamReader(fip, "UTF-8");
        StringBuffer sb = new StringBuffer();
        while (reader.ready()) {
        	// 转成char加到StringBuffer对象中
            sb.append((char) reader.read());
        }
        // 关闭读取流
        reader.close();
        // 关闭输入流,释放系统资源
        fip.close();
	}
	
}
