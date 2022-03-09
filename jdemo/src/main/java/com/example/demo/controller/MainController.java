package com.example.demo.controller;

import com.example.demo.entity.User;
import com.example.demo.mapper.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

/**

  这意味着URL以/demo开头（在应用程序路径之后）
  这意味着该类是一个控制器

 */
@Controller
@RequestMapping(path = "/demo")
public class MainController {

  /**
  这意味着获取名为userRepository的bean
  它是由Spring自动生成的，我们将使用它来处理数据
  */
  @Autowired private UserRepository userRepository;

  /**
   * http://127.0.0.1:9090/demo/add?name=ta&email=101@163.com
    // @ResponseBody 表示返回的字符串是响应，而不是视图名称
    // @RequestParam 表示它是GET或POST请求中的参数
   *
   */
  @PostMapping(path = "/add")
  public @ResponseBody String
  addNewUser(@RequestParam(value = "name", defaultValue = "World") String name,
             @RequestParam(value = "email",
                           defaultValue = "unkin@163.com") String email) {

    User n = new User();
    n.setName(name);
    n.setEmail(email);
    userRepository.save(n);

    return "Saved";
  }

  /**

     http://127.0.0.1:9090/demo/all
   *
   */
  @GetMapping(path = "/all")
  public @ResponseBody Iterable<User> getAllUsers() {
    //这将返回用户的JSON或XML
    return userRepository.findAll();
  }
}
