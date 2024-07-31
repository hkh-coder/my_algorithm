
import java.util.*;

public class Main {
    // public static void main(String[] args) {
    //     Queue<String> queue = new LinkedList<>();
    //     queue.offer("app");
    //     queue.offer("java");
    //     queue.offer("python");
    //     queue.offer("c++");

    //     while (queue.size() > 0) {
    //         System.out.println(queue.poll());
    //     }
    // }

    public static void main(String[] args) {
        Queue<String> que = new PriorityQueue<>();
        que.offer("app");
        que.offer("python");
        que.offer("jvaja");

        while (que.size() > 0) {
            System.out.println(que.poll());
        }
    }
}

class UserCimparator implements Comparator<User> {
    @Override
    public int compare(User u1, User u2) {
        if (u1.name.charAt(0) == u2.name.charAt(0)) {
            return u1.number.compareTo(u2.number);
        }
        if (u1.number.charAt(0) == 'V') {
            return -1;
        } else {
            return 1;
        }
    }
}

class User {
    public final String name;
    public final String number;
    public User(String name, String number) {
        this.name = name;
        this.number = number;
    }
}
