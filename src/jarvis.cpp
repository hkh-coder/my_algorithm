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
凸包函数 -- Jarvis(贾维斯)算法
1、先找到最左侧的点p0
2、以p0为基准，找到下一个点p1，保证其他的点都在 p0p1的左侧
3、check p0p1的共线的点
4、p0 ==> p1 重复2 3 步骤。
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
    if (src_vec.size() < 4) {
        return src_vec;
    }

    // 先找到最左边的点。
    int left_most_idx = 0;
    for (int i = 1; i < src_vec.size(); ++i) {
        if (src_vec[i].x < src_vec[i - 1].x) {
            left_most_idx = i;
        }
    }

    int idx = left_most_idx;
    std::vector<Point> res_vec;
    std::vector<bool> visited(src_vec.size(), false);
    while (idx != left_most_idx) {
        int next_idx = (idx + 1) % src_vec.size();
        // 找到以idx为起点的所有的点都在左侧的next_idx;
        for (int i = 0; i < src_vec.size(); ++i) {
            if (cross(src_vec[idx], src_vec[next_idx], src_vec[i]) < 0) {
                next_idx = i;
            } 
        }
        // 确认是否有共线的点
        for (int i = 0; i < src_vec.size(); ++i) {
            if(visited[i] || i == idx || i == next_idx) {
                continue;
            }
            if (cross(src_vec[idx], src_vec[next_idx], src_vec[i]) == 0) {
                res_vec.emplace_back(src_vec[i]);
                visited[i] = true;
            }
        }
        // 将next_idx 加入
        if (!visited[next_idx]) {
            res_vec.emplace_back(src_vec[next_idx]);
            visited[next_idx] = true;
        }
        // 更新idx 
        idx = next_idx;
    }
    return res_vec;
}

std::vector<Point> generate_points(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 10);
    std::vector<Point> res_vec;
    for(int i = 0; i < n; ++i) {
        res_vec.emplace_back(Point(dis(gen), dis(gen)));
    }
    return res_vec;
}

void print(const std::vector<Point> res_vec) {
    std::cout << "======================" << std::endl;
    for (const auto &p : res_vec) {
        std::cout << p.x << "," << p.y << std::endl;
    }
}


int main() {
    auto src_points = generate_points(5);
    print(src_points);
    auto res_points = convex_hull(src_points);
    print(src_points);
    return 0;
}