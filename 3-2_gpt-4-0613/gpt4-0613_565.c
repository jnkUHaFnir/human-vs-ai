
You can use it in Java as well:

```java
public class Main {
    public static void main(String[] args) {
        String str = "/opt/home/etc/sample";
        String baseName = str.substring(str.lastIndexOf('/') + 1);
        System.out.println(baseName);
    }
}

Above code simply splits the string into a list/array by delimiter '/', then picks the last element which is the base name.
