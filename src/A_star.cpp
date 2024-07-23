#include <iostream>
#include <vector>
#include <algorithm>

/*
A* 算法 - 启发式算法
适用范围：图形平面中 有多个节点路径，求出最低成本路径
*/

struct Node {
    std::vector<std::pair<Node*, int> > next_node;
};

int main() {
    return 0;
}
