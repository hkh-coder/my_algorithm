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

// 1 3 5 4    --> 4 
// 3 2 1      --> 0
// 8 9 1 2 3  --> 2

int f(std::vector<int> &vec) {
    int n = vec.size();
    if (n == 0) {
        return 0;
    }
    std::vector<int> dp(n, 0);
    dp[0] = 0; // 收益
    int min_p = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        dp[i] = std::max(dp[i - 1], vec[i] - min_p);
        min_p = std::min(min_p, vec[i]);
    }
    return dp[n - 1];
}

int main() {
    std::vector<int> vec = {3,2,1};
    std::cout << f(vec) << std::endl;
    return 0;
}