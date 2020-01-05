package tan.wei.feng.utils;

import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;

import com.alibaba.fastjson.JSON;
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
	@Value("${aliyun.sms.sign_name}")
	private String signName;
	@Value("${aliyun.sms.accessKeyId}")
	private String accessKeyId;
	@Value("${aliyun.sms.accessKeySecret}")
	private String accessKeySecret;
	
	/**
	 * 发短信
	 * @param map
	 * @return
	 */
	public boolean sendSms(Map<String,String> map) {

    	DefaultProfile profile = DefaultProfile.getProfile("cn-hangzhou", accessKeyId, accessKeySecret);
        IAcsClient client = new DefaultAcsClient(profile);
        //组装请求对象
        CommonRequest request = new CommonRequest();
        request.setMethod(MethodType.POST);
        request.setDomain("dysmsapi.aliyuncs.com");
        request.setVersion("2017-05-25");
        request.setAction("SendSms");
        request.putQueryParameter("RegionId", "cn-hangzhou");
        
        logger.info("手机号：{}",map.get("mobile"));
        logger.info("验证码：{}",map.get("code"));
        
        request.putQueryParameter("PhoneNumbers", map.get("mobile"));
        request.putQueryParameter("SignName",signName);
        request.putQueryParameter("TemplateCode",templateCode);
        request.putQueryParameter("TemplateParam", "{\'code\':\'"+ map.get("code") +"\'}");
        boolean ac = true;
        try {
            CommonResponse response = client.getCommonResponse(request);
            logger.info(response.getData());
            return JSON.parseObject(response.getData()).get("Message").equals("OK") ? ac:!ac;
        } catch (ServerException se) {
        	logger.info(se.getMessage());
        } catch (ClientException ce) {
        	logger.info(ce.getMessage());
        }
        return !ac;
    }
}
