import java.io.*;

public class FileMain {
    public static void main(String[] args) throws IOException {
        // File f = new File("../");
        // System.out.println(f.getPath());
        // System.out.println(f.getAbsolutePath());
        // System.out.println(f.getCanonicalPath());
        // Path p = Paths.get(f.getCanonicalPath(), "test.txt");
        // System.out.println(p);

        // File [] fs1 = f.listFiles();
        // for (File f1 : fs1) {
        //     System.out.println(f1);
        // }

        readFile();
        readByteFile();
        in_out();
    }

    public static void readFile() throws IOException {
        // InputStream input = new FileInputStream("../test.java");
        // while (true) {
        //     int n = input.read();
        //     if (n == -1) {
        //         break;
        //     }
        //     System.out.print(n);
        // }
        try(InputStream input = new FileInputStream("../test.java")) {
            while (true) {
                int n = input.read();
                if (n == -1) {
                    break;
                }
                System.out.print(n);
            }
        }

        try(InputStream input = new FileInputStream("../test.java")) {
            byte [] buf = new byte[1024];
            int n;
            while((n = input.read(buf)) != -1) {
                System.out.println("read " + n);
                System.out.println(new String(buf, 0, n));
            }
        }

        try(InputStream input = new FileInputStream("../test.java")) {
            String s = readAsString(input);
            System.out.println(s);
        }
    }

    public static String readAsString(InputStream input) throws IOException {
        int n = -1;
        StringBuilder sb = new StringBuilder();
        while((n = input.read()) != -1) {
            sb.append((char)n);
        }
        return sb.toString();
    }

    public static void readByteFile() throws IOException {
        byte [] data = {11,22,33,44};
        try(InputStream input = new ByteArrayInputStream(data)) {
            int n = 0;
            while((n = input.read()) != -1) {
                System.out.println(n);
            }
        }
    }

    public static void in_out() throws IOException {
        try(InputStream input = new FileInputStream("../test.java");
            OutputStream output = new FileOutputStream("out.txt")) {
           byte [] buf = new byte[10];
           int n;
           while((n = input.read(buf)) != -1) {
               output.write(buf, 0, n);
           }
        }
    }
}