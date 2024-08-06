package Dijkstra.utils;

public class DistPare {
    private int parentNode;
    private int distance;
    public DistPare(int parentNode, int distance) {
        this.parentNode = parentNode;
        this.distance = distance;
    }
    public int getParentNode() {
        return parentNode;
    }

    public void setParentNode(int parentNode) {
        this.parentNode = parentNode;
    }

    public int getDistance() {
        return distance;
    }

    public void setDistance(int distance) {
        this.distance = distance;
    }
}
