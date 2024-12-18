package hello.core.springbasic.singleton;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;

import static org.junit.jupiter.api.Assertions.*;

public class StatefulServiceTest {

    @Test
    void statefulServiceSingleton() {
        // Create Spring application context using the TestConfig class
        ApplicationContext ac = new AnnotationConfigApplicationContext(TestConfig.class);

        // Retrieve the same StatefulService bean twice (singleton scope)
        StatefulService statefulService1 = ac.getBean("statefulService", StatefulService.class);
        StatefulService statefulService2 = ac.getBean("statefulService", StatefulService.class);

        // ThreadA: User A places an order for 10,000 won
        statefulService1.order("userA", 10000);

        // ThreadB: User B places an order for 20,000 won
        statefulService2.order("userB", 20000);

        // ThreadA: Retrieve the order amount for User A
        int price = statefulService1.getPrice();

        // ThreadA: User A expects the price to be 10,000 won,
        // but the output unexpectedly shows 20,000 won
        System.out.println("price = " + price);

        // Verify the price, which reflects the shared state issue in the singleton
        Assertions.assertThat(statefulService1.getPrice()).isEqualTo(20000);
    }

    static class TestConfig {
        // Define a StatefulService bean for testing
        @Bean
        public StatefulService statefulService() {
            return new StatefulService();
        }
    }
}
