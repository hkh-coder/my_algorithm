package Dijkstra.utils;

public class Graph {
    private final int MAXNUM = 20;
    private final int MAXINT = 9999999;
    private int nodeNum;
    private int treeNum;
    private int adjMatrix[][];
    private Node nodeList[];
    private DistPare sPath[];
    private int currentNode;
    private int currentDist;
    
    public Graph() {
        adjMatrix = new int[MAXNUM][MAXNUM];
        nodeList = new Node[MAXNUM];
        sPath = new DistPare[MAXNUM];
        nodeNum = 0;
        treeNum = 0;
        for (int i = 0; i < MAXNUM; ++i) {
            for (int j = 0; j < MAXNUM; ++j) {
                adjMatrix[i][j] = MAXINT;
            }
        }
    }

    public void addVertex(char id) {
        nodeList[nodeNum++] = new Node(id);
    }

    public void addEdge(int start, int end, int weight) {
        adjMatrix[start][end] = weight;
    }

    public int getMin() {
        int minDist = MAXINT;
        int idxMin = -1;
        for (int j = 0; j < nodeNum; ++j) {
            if (!nodeList[j].isInTree() && sPath[j].getDistance() < minDist) {
                minDist = sPath[j].getDistance();
                idxMin = j;
            }
        }
        return idxMin;
    }
    private void adjustPath() {
        int num = 1;
        while(num < nodeNum) {
            if (nodeList[num].isInTree()) {
                num++;
                continue;
            }
            int currentToFringe = adjMatrix[currentNode][num];
            int startToFringe = currentDist + currentToFringe;
            int sPathDist = sPath[num].getDistance();
            if (startToFringe < sPathDist) {
                sPath[num].setParentNode(currentNode);
                sPath[num].setDistance(startToFringe);
            }
            num++;
        }
    }

    private void printPath() {
        for (int i = 0; i < nodeNum; ++i) {
            System.out.print(nodeList[i].getId() + "=");
            if (sPath[i].getDistance() == MAXINT) {
                System.out.print("infinnty");
            } else {
                System.out.print(sPath[i].getDistance());
            }
            char patent = nodeList[sPath[i].getParentNode()].getId();
            System.out.print("(" + patent + ")");
        }
        System.out.println();
    }

    public void dijkstra() {
        int sourceNode = 0;
        nodeList[sourceNode].setInTree(true);
        treeNum++;
        for (int i = 0; i < nodeNum; ++i) {
            int weight = adjMatrix[sourceNode][i];
            sPath[i] = new DistPare(sourceNode, weight);
        }
        while(treeNum < nodeNum) {
            int minNode = getMin();
            int minDist = sPath[minNode].getDistance();
            if (minDist == MAXINT) {
                System.out.println("The node cannot be reached");
            } else {
                currentNode = minNode;
                currentDist = minDist;
            }
            nodeList[currentNode].setInTree(true);
            treeNum++;
            adjustPath();   
        }
        printPath();
    }
}
