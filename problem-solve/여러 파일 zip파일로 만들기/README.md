###  여러 파일을 .zip파일로 압축하기

특정 경로에 있는 파일들을 찾아서 하나의 압축파일로 만들어야하는 상황에서 썻던 로직

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
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

1.  폴더 경로 설정
    + folder 변수에 압축할 파일들이 위치한 폴더 경로를 설정합니다.
2. 파일 목록 생성
   + File 객체를 사용하여 주어진 폴더에서 압축할 파일들을 생성합니다.
   + 이 파일들을 List<File>에 추가합니다.
3. 압축파일 및 출력 스트림 설정
   + 압축된 파일을 저장할 zipFile을 설정합니다.
   + ZipOutputStream을 사용하여 압축파일에 데이터를 쓸 출력 스트림을 설정합니다.
4. 파일 압축:
    + 파일 목록을 순회하면서 각 파일을 압축파일에 추가합니다.
    + ZipEntry 객체를 생성하여 압축파일에 추가할 파일의 메타데이터를 설정합니다.
    + 파일을 읽어들이고 압축파일에 쓰는 작업은 FileInputStream과 ZipOutputStream을 사용하여 수행됩니다.
    + 파일을 읽고 쓰는 동안 발생할 수 있는 예외를 처리하기 위해 try-catch 블록을 사용합니다.

