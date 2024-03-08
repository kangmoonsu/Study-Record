import com.ps.introduction_page.config.RecaptchaConfig;
import com.ps.introduction_page.dto.InquiryDto;
import lombok.RequiredArgsConstructor;
import org.springframework.mail.MailException;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.mail.javamail.MimeMessageHelper;
import org.springframework.stereotype.Service;

import javax.mail.*;
import javax.mail.internet.MimeMessage;
import java.io.IOException;


@Service
@RequiredArgsConstructor
public class MailService {

    private final JavaMailSender emailSender;
    private final RecaptchaConfig recaptchaConfig;

    public boolean sendEmail(InquiryDto dto) {
        try {
            boolean verify = recaptchaConfig.verify(dto.getRecaptcha());
            if (!verify) {
                return false;
            } else {
                MimeMessage mimeMessage = emailSender.createMimeMessage();
                MimeMessageHelper helper = new MimeMessageHelper(mimeMessage, true);
                helper.setFrom("phishingshield.co.kr"); // 발신자 이메일 고정
                helper.setTo("moonsu@marvelsystem.co.kr"); // 수신자 이메일
                helper.setSubject("피싱쉴드 문의 도착"); // 이메일 제목
                String emailContent = "발신인: " + dto.getEmail() + "\n문의 내용: " + dto.getContent(); // 이메일 본문
                helper.setText(emailContent);
                emailSender.send(mimeMessage);
                return true;
            }
        } catch (MessagingException | MailException e) {
            throw new RuntimeException("이메일 전송 중 오류가 발생했습니다.", e);
        }
    }
}