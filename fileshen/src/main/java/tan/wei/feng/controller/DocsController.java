package tan.wei.feng.controller;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;

import org.apache.http.HttpEntity;
import org.apache.http.ParseException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicHeader;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.configurationprocessor.json.JSONObject;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import tan.wei.feng.entity.Result;
import tan.wei.feng.entity.StatusCode;

@RestController
@CrossOrigin
@RequestMapping("/doc")
public class DocsController {
	
	private static final Logger logger = LoggerFactory.getLogger(DocsController.class);
	
	/**
	 * 传入json
	 * @param jsonParam
	 * @return
	 */
	@PostMapping()
	public Result getJsonData(@RequestBody JSONObject jsonParam) {
		StringBuilder sb = new StringBuilder();
		String urls = "http://127.0.0.1:9909";
		try {
			// 创建url资源
			URL url = new URL(urls);
			// 建立http连接
			HttpURLConnection conn = (HttpURLConnection) url.openConnection();
			// 设置允许输出
			conn.setDoOutput(true);
            // 设置允许输入
            conn.setDoInput(true);
           // 设置不用缓存
           conn.setUseCaches(false);
           // 设置传递方式
           conn.setRequestMethod("POST");
           // 设置维持长连接
            conn.setRequestProperty("Connection", "Keep-Alive");
           // 设置文件字符集:
           conn.setRequestProperty("Charset", "UTF-8");
           // 转换为字节数组
           byte[] data = (jsonParam.toString()).getBytes();
          // 设置文件长度,设置文件类型:
           conn.setRequestProperty("Content-Length", String.valueOf(data.length));
          conn.setRequestProperty("contentType", "application/json");
           // 开始连接请求
           conn.connect();		
           OutputStream out = new DataOutputStream(conn.getOutputStream()) ;
			// 写入请求的字符串
			out.write((jsonParam.toString()).getBytes());
			out.flush();
			out.close();
 
			// 请求返回的状态
			if (HttpURLConnection.HTTP_OK == conn.getResponseCode()){
				logger.info("连接成功");
				// 请求返回的数据
				InputStream in1 = conn.getInputStream();
			      String readLine = "";
			      BufferedReader responseReader = new BufferedReader(new InputStreamReader(in1,StandardCharsets.UTF_8));
			      while((readLine=responseReader.readLine())!=null){
			        sb.append(readLine).append("\n");
			      }
			      responseReader.close();
			} else {
				logger.info("error++");
			}
		} catch (Exception e) {
			logger.info(e.getMessage());
		}
		return new Result(StatusCode.OK,sb.toString());
	}

	
	

	/**
     * 发送post请求
     * @param jsonObject  参数(json类型)
     * @return
     * @throws ParseException
     * @throws IOException
     */
	@PostMapping(value = "/smap")
    public String send(@RequestBody JSONObject jsonObject) {
    	String url = "http://127.0.0.1:9909";
        String body = "";
        //创建httpclient对象
        CloseableHttpClient client = HttpClients.createDefault();
        //创建post方式请求对象
        HttpPost httpPost = new HttpPost(url);
        //装填参数
        StringEntity s = new StringEntity(jsonObject.toString(), "utf-8");
        s.setContentEncoding(new BasicHeader(HTTP.CONTENT_TYPE,"application/json"));
        //设置参数到请求对象中
        httpPost.setEntity(s);
        System.out.println("请求地址："+url);
 
        //设置header信息指定报文头【Content-type】、【User-Agent】
        httpPost.setHeader("Content-type", "application/json");
        httpPost.setHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:71.0) Gecko/20100101 Firefox/71.0");
        //执行请求操作，并拿到结果（同步阻塞）
        CloseableHttpResponse response = null;
		try {
			response = client.execute(httpPost);
			//获取结果实体
	        HttpEntity entity = response.getEntity();
	        if (entity != null) {
	            //按指定编码转换结果实体为String类型
				body = EntityUtils.toString(entity, "utf-8");
				EntityUtils.consume(entity);
				//释放链接
		        response.close();
	        }
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ParseException e) {
			e.printStackTrace();
		}
        return body;
    }

}
