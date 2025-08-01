package hello.login.domain.member;

import lombok.Data;

import javax.validation.constraints.NotEmpty;

@Data
public class Member {

    private Long id;

    @NotEmpty
    private String loginId; // Login ID

    @NotEmpty
    private String name; // User name

    @NotEmpty
    private String password; // Password
}

