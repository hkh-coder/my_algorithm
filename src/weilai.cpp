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
题目描述

给你一个 n * n 的网格 grid ，上面放置着一些 1 x 1 x 1 的正方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

放置好正方体后，任何直接相邻的正方体都会互相粘在一起，形成一些不规则的三维形体。

请你返回最终这些形体的总表面积。

注意：每个形体的底面也需要计入表面积中。

输入：grid = [[1,2],[3,4]]
输出：34

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：32
*/

int cal_area(std::vector<std::vector<int>> &vec) {
    if (vec.size() == 0 || vec[0].size() == 0) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].size() == 0 || vec[i].size() != vec.size()) {
            return 0;
        }
        int max_row = 0;
        int max_col = 0;
        for (int j = 0; j < vec[i].size(); ++j) {
            if (vec[i][j] > 0) {
                res += 2;
            }
            if (vec[i][j] > max_row) {
                max_row = vec[i][j];
            }
            if (vec[j][i] > max_col) {
                max_col = vec[j][i];
            }
        }
        res += max_row * 2;
        res += max_col * 2;
    }
    return res;
}



/*
/ 给定一个m x n大小的矩阵（m行，n列），按螺旋的顺序返回矩阵中的所有元素。
//例如，
//给出以下矩阵：
//[
// [ 1，2，3，4],
// [5，6，7，8],
// [9，10，11，12],
// [13，14，15，16]，
// [17，18，19，20]
//]

//
//你应该返回[1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17, 13, 9, 5, 6, 7, 11, 15, 14, 10]。
*/

std::vector<int> print_array(std::vector<std::vector<int>> &vec) {
    std::vector<int> res;
    if (vec.size() == 0 || vec[0].size() == 0) {
        return res;
    }

    int t = 0;
    int b = vec.size() - 1;
    int l = 0;
    int r = vec[0].size() - 1;

    while(l < r && t < b) {
        for (int i = l; i < r; ++i) {
            res.push_back(vec[t][i]);
        }
        for (int i = t; i < b; ++i) {
            res.push_back(vec[i][r]);
        }
        for (int i = r; i > l; --i) {
            res.push_back(vec[b][i]);
        }
        for (int i = b; i > t; --i) {
            res.push_back(vec[i][l]);
        }
        l++;
        r--;
        t++;
        b--;
    }
    return res;
}

int show(std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ",";
    }
    std::cout << std::endl;
}

int main() {
    // std::vector<std::vector<int>> vec = {{1,2},{3,4}};
    // std:cout << cal_area(vec) << std::endl;

    std::vector<std::vector<int>> vec = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    auto res = print_array(vec);
    show(res);
    return 0;
}