package tan.wei.feng.model.controller;

import java.io.IOException;
import java.util.Map;

import org.apache.http.HttpEntity;
import org.apache.http.ParseException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.alibaba.fastjson.JSON;

/**
 * 接收文档(String[])并返回分类结果
 * @author 1015956962@163.com
 *
 */
@RestController
@CrossOrigin
@RequestMapping("/doc")
public class DocsController {
	
	private static final Logger logger = LoggerFactory.getLogger(DocsController.class);
	
	/**
	 *  发送post请求
	 * @param map
	 * @return
	 */
	@PostMapping(value = "/smap" ,produces="text/plain;charset=UTF-8")
    public ResponseEntity<String> send(@RequestBody Map<String,String> map) {
    	String url = "http://127.0.0.1:9909";
        String body = "";
        //创建post方式请求对象
        HttpPost httpPost = new HttpPost(url);
        //装填参数并设置参数到请求对象中
        httpPost.setEntity(new StringEntity(JSON.toJSONString(map), "utf-8"));
        //设置header信息指定报文头【Content-type】、【User-Agent】
        httpPost.setHeader(HTTP.CONTENT_TYPE, "application/json");
        //执行请求操作，并拿到结果（同步阻塞）
        CloseableHttpResponse response = null;
        //创建httpclient对象
		try (CloseableHttpClient client = HttpClients.createDefault()){
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
			logger.info(e.getMessage());
		} catch (ParseException sa) {
			logger.info(sa.getMessage());
		}
        return new ResponseEntity<> (body,HttpStatus.OK);
    }

}
