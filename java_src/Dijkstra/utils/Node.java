package Dijkstra.utils;

public class Node {
    private char id;
    private boolean isInTree;

    public Node(char id) {
        this.id = id;
        setInTree(false);
    }
    public char getId() {
        return id;
    }
    public void setId(char id) {
        this.id = id;
    }
    public boolean isInTree() {
        return isInTree;
    }
    public void setInTree(boolean isInTree) {
        this.isInTree = isInTree;
    }
}
