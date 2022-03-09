package com.example.demo.controller;

import com.example.demo.entity.Greeting;
import java.util.concurrent.atomic.AtomicLong;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class GreetingController {

  private static final String template = "Hello, %s!";
  private final AtomicLong counter = new AtomicLong();

  /**

    http://127.0.0.1:9090/greeting?name=wei

   */
  @GetMapping("/greeting")
  public Greeting greeting(@RequestParam(value = "name",
                                         defaultValue = "World") String name) {
    return new Greeting(counter.incrementAndGet(),
                        String.format(template, name));
  }

  /**
    http://127.0.0.1:9090/a1?name=wei

   */
  @PostMapping("/a1")
  public @ResponseBody String str(@RequestParam String name) {
    return String.format(template, name);
  }

  /**
    http://127.0.0.1:9090/a1?name=wei

   */
  @PostMapping("/a2")
  public @ResponseBody
  String poststr(@PathVariable(value = "name") String name) {
    return String.format(template, name);
  }
}
