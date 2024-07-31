package java_src.list;
import java.util.ArrayList;
import java.util.List;

public class main {
    public static void main(String[] args) {
       List<Integer> list = new ArrayList<>();
       for (int i = 0; i < 10; ++i) {
           list.add(i);
       }
       for (int num : list) {
           System.out.print(num);
       }
       System.out.println();
       List<Integer> list2 = List.of(1, 2, 3);
       for (int num : list2) {
           System.out.print(num);
       }
    }
}
