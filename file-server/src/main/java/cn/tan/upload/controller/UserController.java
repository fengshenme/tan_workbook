package cn.tan.upload.controller;

import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import cn.tan.upload.entity.Result;
import cn.tan.upload.entity.StatusCode;
import cn.tan.upload.entity.User;
import cn.tan.upload.service.UserService;
import cn.tan.upload.utils.JwtUtil;
import io.jsonwebtoken.Claims;


@RestController
@CrossOrigin
@RequestMapping("/user")
public class UserController {
	
	@Autowired
	private UserService userService;
	
	@Autowired
	private JwtUtil jwtUtil;
	
	@Autowired
	private HttpServletRequest request;
	
	@Autowired
	private RedisTemplate<String,String> redisTemplate;
	
	/**
	 * 用户手机号登陆
	 * @param mobile
	 * @param password
	 * @return
	 */
	@PostMapping(value = "/login")
	public Result login(@RequestBody User user) {
		user = userService.findByMobileAndPassword(user.getMobile(), user.getPassword());
		if(user.getUserid() !=null ) {
			// 生成token 
			String token = jwtUtil.createJWT(user.getUserid().toString(),user.getMobile(), "user");
					Map<String, String> map=new HashMap<String, String>();
					map.put("token",token);
					//昵称
					map.put("name",user.getNickname());
					
			// 返回token，昵称，头像等信息
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
			throw new RuntimeException("验证码输入不正确");
		}
		
	    if(userService.saveUser(user)) {
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
	 * 登录状态监测
	 * @return
	 */
	@GetMapping(value="/loginStatus")
	public Result loginStatus() {
		Claims claims=(Claims) request.getAttribute("user_claims");
		if(claims==null || "".equals(claims.getId())){
			String message = (String) request.getAttribute("error");
			return new Result(StatusCode.ERROR,message);
		}else {
			return new Result(StatusCode.OK);
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
			return new Result(StatusCode.ERROR);
		}else {
			return new Result(StatusCode.OK, "查询成功",userService.findAll());
		}
	}
}
