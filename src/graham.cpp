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
凸包函数 -- Graham(格雷厄姆)算法
*/

struct Point {
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}
    Point(): x(0.0), y(0.0) {}
};

// 叉乘
int cross(const Point &a, const Point &b, const Point &c) {
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = c.x - a.x;
    int y2 = c.y - a.y;
    return (x1 * y2) - (x2 * y1);
}

std::vector<Point> convex_hull(const std::vector<Point> &src_vec) {
    
}