package hello.core.springbasic.singleton;

import hello.core.springbasic.AppConfig;
import hello.core.springbasic.member.MemberService;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.assertj.core.api.Assertions.*;

public class SingletonTest {

    @Test
    @DisplayName("Pure DI container without spring")
    void pureContainer() {

        AppConfig appConfig = new AppConfig();

        // 1. Retrieve: Creates a new object every time it is called
        MemberService memberService1 = appConfig.memberService();

        // 2. Retrieve: Creates a new object every time it is called
        MemberService memberService2 = appConfig.memberService();

        // check reference value is different
        System.out.println("memberService1 = " + memberService1);
        System.out.println("memberService2 = " + memberService2);

        //memberService1 != memberService2
        assertThat(memberService1).isNotSameAs(memberService2);
    }

    @Test
    @DisplayName("Using an object with the Singleton pattern applied")
    public void singletonServiceTest() {
        // The constructor is blocked with private. A compile error occurs.
        // new SingletonService();

        // 1. Retrieve: Returns the same object every time it is called
        SingletonService singletonService1 = SingletonService.getInstance();

        // 2. Retrieve: Returns the same object every time it is called
        SingletonService singletonService2 = SingletonService.getInstance();

        // Confirm that the reference values are the same
        System.out.println("singletonService1 = " + singletonService1);
        System.out.println("singletonService2 = " + singletonService2);

        // singletonService1 == singletonService2
        assertThat(singletonService1).isSameAs(singletonService2);

        singletonService1.logic();
    }

    @Test
    @DisplayName("Spring Container and Singleton")
    void springContainer() {
        // Create a Spring application context using the AppConfig class
        ApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

        // 1. Retrieve: Returns the same object every time it is called
        MemberService memberService1 = ac.getBean("memberService", MemberService.class);

        // 2. Retrieve: Returns the same object every time it is called
        MemberService memberService2 = ac.getBean("memberService", MemberService.class);

        // Verify that both references point to the same object
        System.out.println("memberService1 = " + memberService1);
        System.out.println("memberService2 = " + memberService2);

        // memberService1 == memberService2
        assertThat(memberService1).isSameAs(memberService2);
    }

}
