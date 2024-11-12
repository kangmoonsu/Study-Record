package hello.core.springbasic;

import hello.core.springbasic.discount.FixDiscountPolicy;
import hello.core.springbasic.member.MemberService;
import hello.core.springbasic.member.MemberServiceImpl;
import hello.core.springbasic.member.MemoryMemberRepository;
import hello.core.springbasic.order.OrderService;
import hello.core.springbasic.order.OrderServiceImpl;

public class AppConfig {
    public MemberService memberService() {
        return new MemberServiceImpl(new MemoryMemberRepository());
    }
    public OrderService orderService() {
        return new OrderServiceImpl(
                new MemoryMemberRepository(),
                new FixDiscountPolicy());
    }
}
