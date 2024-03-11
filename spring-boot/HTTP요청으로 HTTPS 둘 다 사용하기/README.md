# HTTP 접속 시에 HTTPS로 강제 리다이렉트 시키는 방법

+ 웹사이트를 안전하게 유지하기 위해 HTTP 접속을 HTTPS로 강제하는 것은 중요합니다. 
+ HTTPS는 데이터 보안을 강화하고 사용자의 개인 정보를 보호합니다. 
+ 스프링 부트 환경에서 HTTP를 HTTPS로 강제 리다이렉트하는 간단한 방법입니다.

### 개발 환경
1. 스프링 부트 2.3.2
2. java 14
3. gradle 6.3


```yaml
server:
  port: 443
  http:
    port: 80
```
    server.port: 443: 이 설정은 웹 서버가 HTTPS를 통해 요청을 처리할 포트를 지정합니다.
    server.http.port: 80: 이 설정은 HTTP 요청을 받을 포트를 지정합니다.

```java
@Configuration
public class RedirectConfig {

    @Bean
    public ServletWebServerFactory servletContainer() {

        TomcatServletWebServerFactory tomcat = new TomcatServletWebServerFactory(){
            @Override
            protected void postProcessContext(Context context) {
                SecurityConstraint securityConstraint = new SecurityConstraint();
                securityConstraint.setUserConstraint("CONFIDENTIAL");
                SecurityCollection collection = new SecurityCollection();
                collection.addPattern("/*");
                securityConstraint.addCollection(collection);
                context.addConstraint(securityConstraint);
            }
        };
        tomcat.addAdditionalTomcatConnectors(createSslConnector());
        return tomcat;
    }
    
    private Connector createSslConnector() {
        Connector connector = new Connector("org.apache.coyote.http11.Http11NioProtocol");
        connector.setScheme("http");
        connector.setSecure(false);
        connector.setPort(80);
        connector.setRedirectPort(443);
        return connector;
    }
}
```

+ Spring의 Java Config 방식을 사용하여 리다이렉션을 구성합니다. 
  + @Configuration 어노테이션이 클래스에 지정되어 있어 Spring에게 이 클래스가 구성 클래스임을 알려줍니다.
+ servletContainer 메서드: 이 메서드는 ServletWebServerFactory 빈을 생성합니다. 
  + 이를 통해 Tomcat을 사용하여 웹 서버를 설정합니다.
+ postProcessContext 메서드: 이 메서드는 Tomcat의 Context에 보안 제약 조건을 추가합니다. 
  + 이 설정은 모든 요청에 대해 CONFIDENTIAL 보안 제약을 설정하고, 
  + 이는 HTTP를 통해 전송되는 데이터를 암호화된 HTTPS로 전송해야 함을 의미합니다.
+ createSslConnector 메서드: 이 메서드는 추가적인 Tomcat 커넥터를 생성합니다. 
  + 이 커넥터는 HTTP를 처리하기 위한 것이며, 포트 80에서 동작하고, HTTPS로 리다이렉트하기 위해 포트 443으로 리다이렉트합니다.