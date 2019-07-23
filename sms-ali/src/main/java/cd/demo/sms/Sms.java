package cd.demo.sms;

import java.util.Map;

import org.springframework.amqp.rabbit.annotation.RabbitHandler;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.aliyuncs.CommonRequest;
import com.aliyuncs.CommonResponse;
import com.aliyuncs.DefaultAcsClient;
import com.aliyuncs.IAcsClient;
import com.aliyuncs.exceptions.ClientException;
import com.aliyuncs.exceptions.ServerException;
import com.aliyuncs.http.MethodType;
import com.aliyuncs.profile.DefaultProfile;

/**
 * 短信微服务
 * @author 什么李大爷
 *
 */
@Component
@RabbitListener(queues = "sms")
public class Sms {
	//模板编号
	@Value("${aliyun.sms.template_code}")
	private String template_code;
	//签名
	@Value("${aliyun.sms.sign_name}")
	private String sign_name;
	@Value("${aliyun.sms.accessKeyId}")
	private String accessKeyId;
	@Value("${aliyun.sms.accessKeySecret}")
	private String accessKeySecret;
	
    @RabbitHandler
	public void sendSms(Map<String,String> map) {

    	DefaultProfile profile = DefaultProfile.getProfile("cn-hangzhou", accessKeyId, accessKeySecret);
        IAcsClient client = new DefaultAcsClient(profile);
        //组装请求对象-具体描述见控制台-文档部分内容
        CommonRequest request = new CommonRequest();
        request.setMethod(MethodType.POST);
        request.setDomain("dysmsapi.aliyuncs.com");
        request.setVersion("2017-05-25");
        request.setAction("SendSms");
        request.putQueryParameter("RegionId", "cn-hangzhou");
        
        System.out.println("手机号："+map.get("mobile"));
        System.out.println("验证码："+map.get("code"));
        
        //必填:待发送手机号
        request.putQueryParameter("PhoneNumbers", map.get("mobile"));
        //必填:短信签名-可在短信控制台中找到
        request.putQueryParameter("SignName",sign_name);
        //必填:短信模板-可在短信控制台中找到
        request.putQueryParameter("TemplateCode",template_code);
        //可选:模板中的变量替换JSON串,如模板内容为"亲爱的${name},您的验证码为${code}"时,此处的值为
        request.putQueryParameter("TemplateParam", "{\'code\':\'"+ map.get("code") +"\'}");
        
        try {
            CommonResponse response = client.getCommonResponse(request);
            System.out.println(response.getData());
        } catch (ServerException e) {
            e.printStackTrace();
        } catch (ClientException e) {
            e.printStackTrace();
        }
    	
    }

}
