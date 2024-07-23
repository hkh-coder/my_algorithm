#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
面试题 17.14. 最小K个数

设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))
*/

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k >= arr.size()) {
            return std::vector<int>();
        }
        std::sort(arr.begin(), arr.end());
        return std::vector<int>(arr.begin(), arr.begin() + k);
    }
    // 小根堆
    vector<int> smallestK_1(vector<int>& arr, int k) {
        if (k >= arr.size()) {
            return std::vector<int>();
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> tk;
        for (const auto &num : arr) {
            tk.push(num);
        }
        std::vector<int> res;
        while (k-- > 0) {
            res.push_back(tk.top());
            tk.pop();
        }
        return res;
    }
};

int main() {
    return 0;
}