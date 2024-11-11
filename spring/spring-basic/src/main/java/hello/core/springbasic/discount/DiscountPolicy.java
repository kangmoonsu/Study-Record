package hello.core.springbasic.discount;

import hello.core.springbasic.member.Member;

public interface DiscountPolicy {
    /**
     * @return discount target price
     */
    int discount(Member member, int price);
}
