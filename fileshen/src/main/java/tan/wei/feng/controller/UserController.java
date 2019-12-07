package tan.wei.feng.controller;

import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.jsonwebtoken.Claims;
import tan.wei.feng.entity.Result;
import tan.wei.feng.entity.StatusCode;
import tan.wei.feng.entity.User;
import tan.wei.feng.service.create.UserRegisterService;
import tan.wei.feng.service.create.UserService;


/**
 * 注册控制
 * @author 10159
 *
 */
@RestController
@CrossOrigin
@RequestMapping("/user")
public class UserController {
	
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
	@PostMapping(value = "/login")
	public Result login(@RequestBody User user) {
		Map<String, String> map = userService.findByMobileAndPassword(user.getMobile(), user.getPassword());
		if(map !=null ) {
			return new  Result(StatusCode.OK,"登录成功",map);
		}else {
			return new Result(StatusCode.ERROR, "手机号或密码错误");
		}
	}
	
	

	/**
	 * 用户注册
	 * @param user
	 * @param code
	 * @return
	 */
    @PostMapping(value="/register/{code}")
    public Result register( @RequestBody User user ,@PathVariable String code){
    	//提取缓存中验证码判断验证码是否正确
		String syscode = redisTemplate.opsForValue().get("smscode_" + user.getMobile());
		//提取系统正确的验证码
		if(syscode==null){
			return new Result(StatusCode.ERROR,"请点击获取短信验证码");
		}
		if(!syscode.equals(code)){
			return new Result(StatusCode.ERROR,"验证码输入不正确");
		}
	    if(userRegisterService.saveUser(user)) {
	    	return new Result(StatusCode.OK,"注册成功");
	    }else{
	    	return new Result(StatusCode.ERROR,"注册失败,重新注册");
	    }
    }
	
    /**
	* 发送短信验证码
	* @param mobile
	*/
	@GetMapping(value="/sendsms/{mobile}")
	public Result sendsms(@PathVariable String mobile ){
		userService.sendSms(mobile);
		return new Result(StatusCode.OK,"验证码已发送");
	}
	
	/**
	 * 登录退出
	 * @return
	 */
	@DeleteMapping(value="/logout")
	public Result logout() {
		try {
			Claims claims=(Claims) request.getAttribute("user_claims");
			redisTemplate.delete("userid_".concat(claims.getId()));
			return new Result(StatusCode.OK,"退出成功") ;
		} catch (Exception e) {
			return new Result(StatusCode.OK,"退出成功") ;
		}
	}
	
	/**
	 * 获取全部用户
	 * @return
	 */
	@GetMapping(value="/findall")
	public Result findAll() {
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			return new Result(StatusCode.ERROR,"请重新登录");
		}else {
			return new Result(StatusCode.OK, "查询成功",userService.findAll());
		}
	}
	
}
