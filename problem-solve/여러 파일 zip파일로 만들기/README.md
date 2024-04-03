###  여러 파일을 .zip파일로 압축하기

```java
import java.io.*;
import java.util.*;

public class CreateZipFile {
    final static String folder = "/Users/shane/Downloads/fileTest";
    public static void main(String[] args) {
        File file1 = new File(folder, "1.txt");
        File file2 = new File(folder, "2.txt");

        List<File> files = new ArrayList<>();
        files.add(file1);
        files.add(file2);
        
        File zipFile = new File(folder, "압축파일.zip");
        byte[] buf = new byte[4096];

        try {
            try (ZipOutputStream out = new ZipOutputStream(new FileOutputStream(zipFile))) {

                for (File file : files) {
                    try (FileInputStream in = new FileInputStream(file)) {
                        ZipEntry ze = new ZipEntry(file.getName());
                        out.putNextEntry(ze);

                        int len;
                        while ((len = in.read(buf)) > 0) {
                            out.write(buf, 0, len);
                        }

                        out.closeEntry();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
            System.out.println("압축 파일 생성 성공");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

```