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
812. 最大三角形面积
给你一个由 X-Y 平面上的点组成的数组 points ，其中 points[i] = [xi, yi] 
从其中取任意三个不同的点组成三角形，返回能组成的最大三角形的面积。与真实值误差在 10-5 内的答案将会视为正确答案。
*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return 0;
        } 
        double max_area = 0;
        for(int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    double area = std::abs(cross(points[i], points[j], points[k]) * 0.5);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
private:
    double cross(const std::vector<int> &p1,  
            const std::vector<int> &p2, 
            const std::vector<int> &p3) {
        if (p1.size() != 2 || p2.size() != 2 || p3.size() != 2) {
            return 0;
        }
        double x1 = p2[0] - p1[0];
        double y1 = p2[1] - p1[1];
        double x2 = p3[0] - p1[0];
        double y2 = p3[1] - p1[1];
        return (x1 * y2 - x2 * y1);
    }
};

int main() {
    // [[0,0],[0,1],[1,0],[0,2],[2,0]]
    std::vector<std::vector<int>> vec = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    Solution sol;
    std::cout << sol.largestTriangleArea(vec) << std::endl;
}