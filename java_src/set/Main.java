
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Message> messages = List.of(
            new Message(1, "Hello"),
            new Message(2, "World"),
            new Message(2, "World"),
            new Message(3, "bye")
        );
        List<Message> dispalyMessages = process(messages);
        for (var msg : dispalyMessages) {
            System.out.println(msg.text + "," + msg.seqence);
        }
    }
    static List<Message> process(List<Message> messages) {
        Set<Integer> set = new HashSet<>();
        List<Message> result = new ArrayList<>();
        for (var tmp : messages) {
            if (set.contains(tmp.seqence)) continue;
            set.add(tmp.seqence);
            result.add(tmp);
        }
        return result;
    }
}

class Message {
    public final int seqence;
    public final String text;
    public Message(int seqence, String text) {
        this.seqence = seqence;
        this.text = text;
    }
}