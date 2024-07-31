package java_src.list;
import java.util.*;

public class FoundMiss {
    public static void main(String[] args) {
        final int start = 10;
        final int end = 20;
        List<Integer> list = new ArrayList<>();
        for (int i = start; i <= end; i++) {
            list.add(i);
        }
        int remove = list.remove((int)(Math.random() * list.size()));
        int found = findMissingNumber(list, start, end);
        System.out.println("list: " + list.toString());
        System.out.println("remove: " + remove + ", found: " + found);
    }
    static int findMissingNumber(List<Integer> list, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (!list.contains(i)) {
                return i;
            }
        }
        return -1;
    }
}
