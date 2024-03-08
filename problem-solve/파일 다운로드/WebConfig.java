import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import java.io.File;

@Configuration
public class WebConfig implements WebMvcConfigurer {
    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry){

        String separator = File.separator;
        String path = new File(".").getAbsoluteFile().toString();
        String rePath = path.replace("\\", separator).replace(".", "");
        String brochurePath = rePath + separator + "brochure" + separator;

        registry.addResourceHandler("/brochure/**")
                .addResourceLocations("file://" + brochurePath);
    }
}




