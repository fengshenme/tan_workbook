package tan.wei.feng.model.controller;

import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.alibaba.fastjson.JSONObject;

import io.jsonwebtoken.Claims;
import tan.wei.feng.entity.User;
import tan.wei.feng.model.service.create.UserRegisterService;
import tan.wei.feng.model.service.create.UserService;


/**
 * 注册控制
 * @author 1015956962@163.com
 *
 */
@RestController
@CrossOrigin
@RequestMapping("/user")
public class UserController {
	
	private static final String USERID = "userid_";
	
	@Autowired
	private  UserService userService = null;
	@Autowired
	private  HttpServletRequest request = null;
	@Autowired
	private  RedisTemplate<String,String> redisTemplate = null ;
	@Autowired
	private UserRegisterService userRegisterService = null ;
	
	
	/**
	 * 用户手机号登陆
	 * @param mobile
	 * @param password
	 * @return
	 */
	@PostMapping(value = "/login",produces="application/json;charset=UTF-8")
	public ResponseEntity<Map<String, String>> login(@RequestBody JSONObject jsob) {
		Map<String, String> ma = userService.findByMobileAndPassword(jsob.getString("mobile"), jsob.getString("password"));
		return new ResponseEntity<>(ma,HttpStatus.OK);
	}
	
	/**
	 * 用户注册
	 * @param user
	 * @param code
	 * @return
	 */
    @PostMapping(value="/register/{code}", produces="text/plain;charset=UTF-8")
    public ResponseEntity<String> register( @RequestBody JSONObject jsob ,@PathVariable String code){
    	//提取缓存中验证码判断验证码是否正确
		String syscode = redisTemplate.opsForValue().get("smscode_" + jsob.getString("mobile"));
		if(syscode == null || !syscode.equals(code)){
			return new ResponseEntity<>("验证码不正确,请重新输入",HttpStatus.NOT_EXTENDED);
		}
	    if(userRegisterService.saveUser(jsob)) {
			return new ResponseEntity<>("注册成功",HttpStatus.OK);
	    }
	    return new ResponseEntity<>("注册失败,重新注册",HttpStatus.NOT_EXTENDED);
    }
	
    /**
	* 发送短信验证码
	* @param mobile
	*/
	@GetMapping(value="/sendsms/{mobile}", produces="text/plain;charset=UTF-8")
	public ResponseEntity<String> sendsms(@PathVariable String mobile ){
		if(userService.sendSms(mobile)) {
			return new ResponseEntity<>("验证码已发送",HttpStatus.OK);
		}
		return new ResponseEntity<>("请重新获取验证码",HttpStatus.NO_CONTENT);
	}
	
	/**
	 * 获取全部用户
	 * @return
	 */
	@GetMapping(value="/findall",produces="application/json;charset=UTF-8")
	public ResponseEntity<List<User>> findAll() {
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims !=null && !"".equals(claims.getId().trim())){
			return new ResponseEntity<>(userService.findAll(),HttpStatus.OK);
		}
		return new ResponseEntity<>(HttpStatus.UNAUTHORIZED);
	}
	
	
	/**
	 * 登录退出
	 * @return
	 */
	@DeleteMapping(value="/logout", produces="text/plain;charset=UTF-8")
	public ResponseEntity<String> logout() {
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims !=null && !"".equals(claims.getId().trim())){
			redisTemplate.delete(USERID.concat(claims.getId()));
		}
		return new ResponseEntity<>(HttpStatus.RESET_CONTENT) ;
	}
	
}
