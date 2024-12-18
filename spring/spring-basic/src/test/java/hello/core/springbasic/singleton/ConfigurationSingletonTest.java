package hello.core.springbasic.singleton;

import hello.core.springbasic.AppConfig;
import hello.core.springbasic.member.MemberRepository;
import hello.core.springbasic.member.MemberServiceImpl;
import hello.core.springbasic.order.OrderServiceImpl;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.assertj.core.api.Assertions.assertThat;

public class ConfigurationSingletonTest {

    @Test
    void configurationTest() {
        // Create a Spring application context using the AppConfig class
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

        // Retrieve beans from the Spring container
        MemberServiceImpl memberService = ac.getBean("memberService", MemberServiceImpl.class);
        OrderServiceImpl orderService = ac.getBean("orderService", OrderServiceImpl.class);
        MemberRepository memberRepository = ac.getBean("memberRepository", MemberRepository.class);

        // All references point to the same instance
        System.out.println("memberService -> memberRepository = " + memberService.getMemberRepository());
        System.out.println("orderService -> memberRepository = " + orderService.getMemberRepository());
        System.out.println("memberRepository = " + memberRepository);

        // Verify that all beans refer to the same instance
        assertThat(memberService.getMemberRepository()).isSameAs(memberRepository);
        assertThat(orderService.getMemberRepository()).isSameAs(memberRepository);
    }

    @Test
    void configurationDeep() {
        // Create a Spring application context using the AppConfig class
        ApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

        // AppConfig is also registered as a Spring bean
        AppConfig bean = ac.getBean(AppConfig.class);

        // Print the class of the bean
        System.out.println("bean = " + bean.getClass());
        // output : class hello.core.springbasic.AppConfig$$SpringCGLIB$$0
    }
}

