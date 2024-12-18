package hello.core.springbasic;

import hello.core.springbasic.discount.DiscountPolicy;
import hello.core.springbasic.discount.FixDiscountPolicy;
import hello.core.springbasic.member.MemberRepository;
import hello.core.springbasic.member.MemberService;
import hello.core.springbasic.member.MemberServiceImpl;
import hello.core.springbasic.member.MemoryMemberRepository;
import hello.core.springbasic.order.OrderService;
import hello.core.springbasic.order.OrderServiceImpl;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    @Bean
    public MemberService memberService() {
        System.out.println("call AppConfig.memberService");
        return new MemberServiceImpl(memberRepository());
    }

    @Bean
    public MemberRepository memberRepository() {
        System.out.println("call AppConfig.memberRepository");
        return new MemoryMemberRepository();
    }

    @Bean
    public OrderService orderService() {
        System.out.println("call AppConfig.orderService");
        return new OrderServiceImpl(memberRepository(), discountPolicy());
    }

    @Bean
    public DiscountPolicy discountPolicy() {
        return new FixDiscountPolicy();
        // return new RateDiscountPolicy();
    }
}