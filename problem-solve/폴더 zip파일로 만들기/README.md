# 폴더를 .zip으로 압축

파일을 업로드하면서 압축 해제를 하고 다른이름으로 압축해야될 업무가 있었다. 

여러가지 방법을 찾아보다가 아주 간단하게 할 수 있는 라이브러리가 있었다.

### 1. Ziputil.pack()

```java
public void compressZip(File sourceDir, File targetZipFile) {
    ZipUtil.pack(sourceDir, targetZipFile);
}
```

+ sourceDir: 압축할 파일 또는 디렉토리가 위치한 경로를 나타내는 File 객체입니다.
+ targetZipFile: 압축된 Zip 파일을 저장할 경로를 나타내는 File 객체입니다.

ZipUtil 클래스에서 제공되는 pack 메서드를 호출하여 파일 또는 디렉토리를 Zip 파일로 압축합니다. 

ZipUtil.pack() 메서드는 sourceDir에서 시작하여 해당 내용을 targetZipFile로 압축합니다.

이 코드를 사용하려면 ZipUtil 클래스가 적절히 정의되어 있어야 합니다. 

ZipUtil 클래스는 일반적으로 파일 및 디렉토리를 압축하는 데 사용되는 유틸리티 메서드를 포함합니다. 

위 코드에서는 ZipUtil.pack() 메서드를 사용하고 있으므로 ZipUtil 클래스는 이 메서드를 제공해야 합니다.

전체적으로 이 코드는 주어진 디렉토리의 내용을 Zip 파일로 압축하는 간단한 기능을 제공합니다.