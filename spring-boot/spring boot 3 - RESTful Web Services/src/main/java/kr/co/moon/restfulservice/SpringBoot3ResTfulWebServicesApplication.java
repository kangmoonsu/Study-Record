package kr.co.moon.restfulservice;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.web.servlet.LocaleResolver;
import org.springframework.web.servlet.i18n.SessionLocaleResolver;

import java.util.Locale;

@SpringBootApplication
public class SpringBoot3ResTfulWebServicesApplication {

	public static void main(String[] args) {

		SpringApplication.run(SpringBoot3ResTfulWebServicesApplication.class, args);

//		실행중인 bean 다 불러와서 출력
//		ApplicationContext ac = SpringApplication.run(SpringBoot3ResTfulWebServicesApplication.class, args);
//		String[] allBeanNames = ac.getBeanDefinitionNames();
//		for(String beanName : allBeanNames) {
//			System.out.println(beanName);
//		}
	}

	@Bean
	public LocaleResolver localeResolver() {
		SessionLocaleResolver localeResolver = new SessionLocaleResolver();
		localeResolver.setDefaultLocale(Locale.US);
		return localeResolver;
	}

}
