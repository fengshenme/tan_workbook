package tan.wei.feng.utils;

import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;

import com.aliyuncs.CommonRequest;
import com.aliyuncs.CommonResponse;
import com.aliyuncs.DefaultAcsClient;
import com.aliyuncs.IAcsClient;
import com.aliyuncs.exceptions.ClientException;
import com.aliyuncs.exceptions.ServerException;
import com.aliyuncs.http.MethodType;
import com.aliyuncs.profile.DefaultProfile;

/**
 * 阿里云短信工具类
 * @author 10159
 *
 */
public class SmsUtil {
	
	private static final Logger logger = LoggerFactory.getLogger(SmsUtil.class);
	
	@Value("${aliyun.sms.template_code}")
	private String templateCode;
	//签名
	@Value("${aliyun.sms.sign_name}")
	private String signName;
	@Value("${aliyun.sms.accessKeyId}")
	private String accessKeyId;
	@Value("${aliyun.sms.accessKeySecret}")
	private String accessKeySecret;
	
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
        
        logger.info("手机号：{}",map.get("mobile"));
        logger.info("验证码：{}",map.get("code"));
        
        //必填:待发送手机号
        request.putQueryParameter("PhoneNumbers", map.get("mobile"));
        //必填:短信签名-可在短信控制台中找到
        request.putQueryParameter("SignName",signName);
        //必填:短信模板-可在短信控制台中找到
        request.putQueryParameter("TemplateCode",templateCode);
        //可选:模板中的变量替换JSON串,如模板内容为"亲爱的${name},您的验证码为${code}"时,此处的值为
        request.putQueryParameter("TemplateParam", "{\'code\':\'"+ map.get("code") +"\'}");
        
        try {
            CommonResponse response = client.getCommonResponse(request);
            logger.info(response.getData());
        } catch (ServerException e) {
        	logger.info(e.getMessage());
        } catch (ClientException f) {
        	logger.info(f.getMessage());
        }
    	
    }
}
