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
凸包函数 -- Andrew(安格鲁)算法
1、排序: 按照 X 轴从小到大，X 相同的 Y进行排序 [排序后的第一个点和最后一个点一定在凸包上]
-- 逆时针旋转一圈。
2、然后从最小到最大 -- 处理凸包的下半部分数据，
    如果栈中最后两个点和第三个点，如果是左转了，那就丢到栈中最后一个点，然后第三个点入栈。
    以此类推
3、从最大到最小 -- 处理凸包的上半部分。
    如果栈中最后两个点和第三个点，如果是左转了，那就丢到栈中最后一个点，然后第三个点入栈。
    以此类推
4、起始点计算了两次，去掉一次。

*/

// 叉乘
int cross(const std::vector<int> &a, 
          const std::vector<int> &b, 
          const std::vector<int> &c) {
    if (a.size() != 2 || b.size() != 2 || c.size() != 2) {
        return 0;
    }
    int x1 = b[0] - a[0];
    int y1 = b[1] - a[1];
    int x2 = c[0] - a[0];
    int y2 = c[1] - a[1];
    return (x1 * y2) - (x2 * y1);
}

std::vector<std::vector<int>> convex_hull(const std::vector<std::vector<int>> &src_vec) {
    if (src_vec.size() < 4) {
        return src_vec;
    }
    // 小到大排序
    std::sort(src_vec.begin(), src_vec.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    std::vector<int> hull;
    std::vector<bool> visited(src_vec.size(), false);
    // 先把第一个点push
    hull.push_back(0);
    /*求凸包的下半部分*/
    for(int i = 1;i < src_vec.size(); ++i) {
        while(hull.size() > 1 && cross(src_vec[hull[hull.size() - 2]], src_vec[hull[hull.size() - 1]], src_vec[i]) < 0) {
            visited[hull[hull.size() - 1]] = false;
            hull.pop_back(); // 说明比它左边的还有点
        }
        hull.push_back(i);
        visited[i] = true;
    }
    /*求上半部分*/
    int hull_size = hull.size();
    for (int i = src_vec.size() - 2; i >=0; --i) {
        if (!visited[i]) {
            while(hull.size() > hull_size && cross(src_vec[hull[hull.size() - 2]], src_vec[hull[hull.size() - 1]], src_vec[i]) < 0) {
                visited[hull[hull.size() - 1]] = false;
                hull.pop_back(); // 说明比它左边的还有点
            }
            visited[i] = true;
            hull.push_back(i);
        }
    }
    /* 0被记录了两次，删掉一个*/
    hull.pop_back();
    std::vector<std::vector<int>> res;
    for (const auto &v : hull) {
        res.emplace_back(src_vec[v]);
    }
    return res;
}