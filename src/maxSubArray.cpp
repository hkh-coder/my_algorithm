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
53. 最大子数组和
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // f(i) = max(f(i - 1) + nums[i], nums[i])
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = std::max(nums[i], nums[i - 1] + nums[i]);
            if (nums[i] > max_sum) {
                max_sum = nums[i];
            }
        }
        return max_sum;
    }
};




int main() {
    return 0;
}