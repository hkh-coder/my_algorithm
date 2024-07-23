#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
2368. 受限条件下可到达节点的数目

[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]

[4,5]

0: 1 4 5
1: 0 2 3
2: 1
3: 1
4: 0
5: 0 6
6: 5

*/
class ReachableNodes {
public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                              vector<int>& restricted) {
        std::vector<int> restricted_(n, 0);
        for(auto r : restricted) {
            restricted_[r] = 1;
        } 
        std::unordered_map<int, std::vector<int>> graph;
        std::deque<int> deq;
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][0] == 0 || edges[i][1] == 0) {
                if (edges[i][0] != 0 && !restricted_[edges[i][0]]) {
                    deq.push_back(edges[i][0]);
                }
                if (edges[i][1] != 0 && !restricted_[edges[i][1]]) {
                    deq.push_back(edges[i][1]);
                }
                continue;            
            }
            
            if (!restricted_[edges[i][0]]) {
                if (graph.find(edges[i][0]) == graph.end()) {
                    graph[edges[i][0]] = std::vector<int>();
                }
                if (!restricted_[edges[i][1]]) {
                    graph[edges[i][0]].push_back(edges[i][1]);
                }
            }
            if (!restricted_[edges[i][1]]) {
                if (graph.find(edges[i][1]) == graph.end()) {
                    graph[edges[i][1]] = std::vector<int>();
                }
                if (!restricted_[edges[i][0]]) {
                    graph[edges[i][1]].push_back(edges[i][0]);
                }
            }
        }
        std::unordered_set<int> visited;
        while( !deq.empty()) {
            int num = deq.front();
            deq.pop_front();
            visited.insert(num);
            if (graph.find(num) != graph.end()) {
                for (auto n : graph[num]) {
                    if (visited.find(n) != visited.end()){
                        continue;
                    }
                    deq.push_back(n);
                }
            }
        }
        return visited.size() + 1;
    }
};

int main() {
    // [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]
    return 0;
}
