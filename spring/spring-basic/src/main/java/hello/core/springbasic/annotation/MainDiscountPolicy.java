package hello.core.springbasic.annotation;

import org.springframework.beans.factory.annotation.Qualifier;

import java.lang.annotation.*;

import static java.lang.annotation.ElementType.*;

@Target(value = {FIELD, METHOD, PARAMETER, TYPE, ANNOTATION_TYPE})
@Retention(RetentionPolicy.RUNTIME)
@Inherited
@Documented
@Qualifier("mainDiscountPolicy")
public @interface MainDiscountPolicy {
}
