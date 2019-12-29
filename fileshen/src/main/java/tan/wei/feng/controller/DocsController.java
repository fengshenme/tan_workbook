package tan.wei.feng.controller;

import java.io.IOException;
import java.util.Map;

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
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * 接收文档(String[])并返回分类结果
 * @author 锋什么
 *
 */
@RestController
@CrossOrigin
@RequestMapping("/doc")
public class DocsController {
	
	private static final Logger logger = LoggerFactory.getLogger(DocsController.class);
	
	/**
	 * 发送post请求
	 * @param map
	 * @return
	 * @throws JsonProcessingException
	 */
	@PostMapping(value = "/smap" ,produces="application/json;charset=UTF-8")
    public String send(@RequestBody Map<String,String> map) throws JsonProcessingException {
    	String url = "http://127.0.0.1:9909";
        String body = "";
        //创建post方式请求对象
        HttpPost httpPost = new HttpPost(url);
        ObjectMapper mapper = new ObjectMapper();
        String json  = mapper.writeValueAsString(map);
        //装填参数
        StringEntity s = new StringEntity(json, "utf-8") ;
        s.setContentEncoding(new BasicHeader(HTTP.CONTENT_TYPE,"application/json"));
        //设置参数到请求对象中
        httpPost.setEntity(s);
        //设置header信息指定报文头【Content-type】、【User-Agent】
        httpPost.setHeader("Content-type", "application/json");
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
        return body;
    }

}
