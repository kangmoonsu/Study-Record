package hello.springmvc.basic.request;

import hello.springmvc.basic.HelloData;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.Map;

@Slf4j
@Controller
public class RequestParamController {
    /**
     * If the return type is void and the response value is directly written,
     * the view is not resolved.
     */
    @RequestMapping("/request-param-v1")
    public void requestParamV1(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String username = request.getParameter("username");
        int age = Integer.parseInt(request.getParameter("age"));
        log.info("username={}, age={}", username, age);
        response.getWriter().write("ok");
    }

    /**
     * Using @RequestParam
     * - Binds the parameter by its name
     * Adding @ResponseBody
     * - Skips view resolution and directly writes the response to the HTTP message body
     */
    @ResponseBody
    @RequestMapping("/request-param-v2")
    public String requestParamV2(
            @RequestParam("username") String memberName,
            @RequestParam("age") int memberAge) {
        log.info("username={}, age={}", memberName, memberAge);
        return "ok";
    }

    /**
     * Using @RequestParam
     * If the HTTP parameter name matches the variable name,
     *
     * @RequestParam(name="xx") can be omitted.
     */
    @ResponseBody
    @RequestMapping("/request-param-v3")
    public String requestParamV3(
            @RequestParam("username") String username,
            @RequestParam("age") int age) {
        log.info("username={}, age={}", username, age);
        return "ok";
    }

    /**
     * Using @RequestParam
     * If the parameter is a simple type like String or int,
     *
     * @RequestParam can be omitted.
     */
    @ResponseBody
    @RequestMapping("/request-param-v4")
    public String requestParamV4(@RequestParam("username") String username,
                                 @RequestParam("age") int age) {
        log.info("username={}, age={}", username, age);
        return "ok";
    }

    /**
     * @RequestParam.required /request-param-required -> Throws an exception because "username" is missing
     * <p>
     * Note!
     * /request-param-required?username= -> Passes as an empty string
     * <p>
     * Note!
     * /request-param-required
     * int age -> Cannot assign null to a primitive int,
     * so use Integer instead (or use defaultValue as shown in the next example)
     */
    @ResponseBody
    @RequestMapping("/request-param-required")
    public String requestParamRequired(
            @RequestParam(name = "username", required = true) String username,
            @RequestParam(name = "age", required = false) int age) {
        log.info("username={}, age={}", username, age);
        return "ok";
    }


    /**
     * @RequestParam - Using defaultValue
     * <p>
     * Note: defaultValue is applied even when the parameter value is an empty string.
     * Example: /request-param-default?username=
     */
    @ResponseBody
    @RequestMapping("/request-param-default")
    public String requestParamDefault(
            @RequestParam(name = "username", required = true, defaultValue = "guest") String username,
            @RequestParam(name = "age", required = false, defaultValue = "-1") int age) {
        log.info("username={}, age={}", username, age);
        return "ok";
    }

    /**
     * @RequestParam Map, MultiValueMap
     * Map (key=value)
     * MultiValueMap (key=[value1, value2, ...])
     * Example: (key=userIds, value=[id1, id2])
     */
    @ResponseBody
    @RequestMapping("/request-param-map")
    public String requestParamMap(@RequestParam Map<String, Object> paramMap) {
        log.info("username={}, age={}", paramMap.get("username"), paramMap.get("age"));
        return "ok";
    }

    /**
     * Using @ModelAttribute
     * Note: model.addAttribute(helloData) is automatically applied as well.
     * This will be explained in detail when discussing the model later.
     */
    @ResponseBody
    @RequestMapping("/model-attribute-v1")
    public String modelAttributeV1(@ModelAttribute HelloData helloData) {
        log.info("username={}, age={}", helloData.getUsername(), helloData.getAge());
        return "ok";
    }

    /**
     * @ModelAttribute can be omitted
     * Simple types like String, int = Treated as @RequestParam
     * Types not specified as argument resolvers = Treated as @ModelAttribute
     */
    @ResponseBody
    @RequestMapping("/model-attribute-v2")
    public String modelAttributeV2(HelloData helloData) {
        log.info("username={}, age={}", helloData.getUsername(), helloData.getAge());
        return "ok";
    }


}
