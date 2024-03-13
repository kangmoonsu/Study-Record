package kr.co.moon.restfulservice.controller;

import kr.co.moon.restfulservice.bean.HelloWorldBean;
import org.springframework.context.MessageSource;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RestController;

import java.util.Locale;

@RestController
public class HelloWorldController {

    private MessageSource messageSource;

    public HelloWorldController(MessageSource messageSource) {
        this.messageSource = messageSource;
    }

    // GET
    // URI - /hello-world
    // @RequestMapping(method=RequestMethod.GET, path="/hello-world")
    @GetMapping(path = "/hello-world")
    public String helloWorld() {
        return "Hello world";
    }

    @GetMapping(path = "/hello-world-bean")
    public HelloWorldBean helloWorldBean() {
        return new HelloWorldBean("Hello World");
    }

    @GetMapping(path = "/hello-world-bean/path-variable/{name}")
    public HelloWorldBean helloWorldBeanPathVariable(@PathVariable String name) {
        return new HelloWorldBean(String.format("Hello World, %s", name));
    }

    @GetMapping(path = "/hello-world-internationalization")
    public String helloWorldInternationalization(
            @RequestHeader(name = "Accept-Language", required = false) Locale locale) {
        return messageSource.getMessage("greeting.message", null, locale);
    }
}
