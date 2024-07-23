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
16. 最接近的三数之和
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT32_MAX;
        int ress = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    int num = abs(nums[i] + nums[j] + nums[k] - target);
                    if (num < res) {
                        res = num;
                        ress = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return ress;
    }
};

int main() {
    return 0;
}