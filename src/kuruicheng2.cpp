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


int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if (n == 0) {
        return 0;
    }
    int dp[n][2];
    dp[0][0] = -prices[0] - fee;
    dp[0][1] = 0;
    for (int i = 0; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}


int main() {
    int k = 2;
    std::vector<int> prices = {2,4,1};
    maxProfit(k, prices);
    return 0;
}
