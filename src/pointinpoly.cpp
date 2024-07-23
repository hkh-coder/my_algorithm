#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <random>

/*
 -- 点在面内
射线法
如何射线和面的边线的交点是偶数，则点在面外，否则点在面内
 - 特殊情况
  - 射线和交点相交。
  - 射线和边共线
*/

bool point_in_poly(std::vector<std::vector<int>> polys, std::vector<int> pt) {
    if (polys.size() < 3 || pt.size() != 2) {
        return false;
    }
    bool c = false;
    for (int i = 0; i < polys.size(); ++i) {
        int j = (i + 1) % (polys.size());
        if (polys[i].size() != 2 || polys[j].size() != 2) {
            return false;
        }
        if ((polys[i][1] <= pt[1] && pt[1] < polys[j][1]) ||
           (polys[j][1] <= pt[1] && pt[1] < polys[i][1]) &&
           ((pt[0] - polys[i][0]) * (polys[i][1] - polys[j][1])) - ((pt[1] - polys[i][1]) * (polys[i][0] - polys[j][0]))) {
            c = !c;
        }
    }
    return c;
}

int main() {
    std::vector<std::vector<int>> polygon = {{0, 0}, {5, 0}, {5, 5}, {0, 5}};
    std::vector<int> point1 = {3, 3}; // inside
    std::vector<int> point2 = {6, 6}; // outside
    std::vector<int> point3 = {5, 2}; // on edge
    std::cout << "pt:" <<  point_in_poly(polygon, point1) << std::endl;
    std::cout << "pt:" <<  point_in_poly(polygon, point2) << std::endl;
    std::cout << "pt:" <<  point_in_poly(polygon, point3) << std::endl;
    return 0;
}