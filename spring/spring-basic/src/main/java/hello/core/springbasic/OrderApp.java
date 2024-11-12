package hello.core.springbasic;

import hello.core.springbasic.member.Grade;
import hello.core.springbasic.member.Member;
import hello.core.springbasic.member.MemberService;
import hello.core.springbasic.member.MemberServiceImpl;
import hello.core.springbasic.order.Order;
import hello.core.springbasic.order.OrderService;
import hello.core.springbasic.order.OrderServiceImpl;

public class OrderApp {
    public static void main(String[] args) {
        AppConfig appConfig = new AppConfig();
        MemberService memberService = appConfig.memberService();
        OrderService orderService = appConfig.orderService();

        long memberId = 1L;
        Member member = new Member(memberId, "memberA", Grade.VIP);
        memberService.join(member);

        Order order = orderService.createOrder(memberId, "itemA", 10000);

        System.out.println("order = " + order);
    }
}
