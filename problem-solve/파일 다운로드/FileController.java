import org.springframework.core.io.Resource;
import org.springframework.core.io.UrlResource;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.*;
import java.net.MalformedURLException;
import java.net.URLEncoder;

@RestController
public class FileController {
    @GetMapping("/download-brochure")
    public ResponseEntity<Resource> downloadBrochure() {

        try {
            String fileName = new File(".").getAbsoluteFile().toString() + "/brochure/파일명.pdf";
            Resource resource = new UrlResource("file:" + fileName);

            if (!resource.exists()) {
                return new ResponseEntity<>(HttpStatus.NOT_FOUND);
            }

            String encodedFileName = URLEncoder.encode(fileName, "UTF-8").replaceAll("\\+", "%20");

            HttpHeaders headers = new HttpHeaders();
            headers.add("Content-Type", "application/octet-stream; charset=UTF-8");
            headers.setContentDisposition(ContentDisposition.builder("attachment")
                    .filename(encodedFileName)
                    .build()
            );

            return ResponseEntity.ok()
                    .headers(headers)
                    .body(resource);

        } catch (UnsupportedEncodingException | MalformedURLException e) {
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }
}
