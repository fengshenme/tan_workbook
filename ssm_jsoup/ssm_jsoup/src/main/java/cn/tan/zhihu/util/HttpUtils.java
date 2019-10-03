package cn.tan.zhihu.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.zip.GZIPInputStream;

import org.apache.http.Header;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;

public class HttpUtils {
	

	/**
	 * http get请求
	 * @param url
	 * @return 
	 * @return
	 * @throws IOException 
	 * @throws ClientProtocolException 
	 */
	public String getHttpOne(String httpurl) throws ClientProtocolException, IOException {
		// 获得Http客户端(可以理解为:你得先有一个浏览器;注意:实际上HttpClient与浏览器是不一样的)
		CloseableHttpClient httpClient = HttpClientBuilder.create().build();
		// 创建Get请求
		HttpGet httpGet = new HttpGet(httpurl);
		
		// 响应模型 // 由客户端执行(发送)Get请求
		CloseableHttpResponse response = httpClient.execute(httpGet);
		Header[] headers = response.getHeaders("Content-Encoding");
		boolean isGzip = false;
		for (Header header : headers) {
			String value = header.getValue();
			if (value.equals("gzip")) {
				isGzip = true;
			}
		}
		InputStream  is = response.getEntity().getContent();
		 
		String str;
		if (!isGzip){
			str = streamToString(is);
		}else {
			GZIPInputStream gzipIn = new GZIPInputStream(is);
			str = streamToString(gzipIn);
		}
		System.out.println(response.getAllHeaders().toString());
		// 从响应模型中获取响应实体
		System.out.println("响应内容为:" + str);
		return str;
	}
	
	/**
	 * 将输入流转成字符串
	 * @param is
	 * @return
	 */
	public static String streamToString(InputStream is) {
	    BufferedReader reader =new BufferedReader(new InputStreamReader(is));
	    StringBuilder sb =new StringBuilder();
	    String line =null;
	    try{
	        while((line = reader.readLine()) != null) {
	            sb.append(line);
	        }
	    }catch (IOException e) {
	        e.printStackTrace();
	    }finally {
	        try{
	            is.close();
	        }catch (IOException e) {
	            e.printStackTrace();
	        }
	    }
	    return sb.toString();
	}

	
}
