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
1905. 统计子岛屿
*/

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool is_lands = true;  // 已 grid2 为标准进行判断，
                dfs(grid1, grid2, i, j, m, n, is_lands);
                if (is_lands) {
                    count++;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             int i, int j, int m, int n, bool &is_lands) {
        grid2[i][j] = 0;
        if (grid1[i][j] == 0) {
            is_lands = false;
        }
        if (i - 1 >= 0 && grid2[i-1][j] == 1) {
            dfs(grid1, grid2, i-1, j, m, n, is_lands);
        }
        if (i + 1 < m && grid2[i+1][j] == 1) {
            dfs(grid1, grid2, i+1, j, m, n, is_lands);
        }
        if (j - 1 >= 0 && grid2[i][j-1] == 1) {
            dfs(grid1, grid2, i, j-1, m, n, is_lands);
        }
        if (j + 1 < n && grid2[i][j+1] == 1) {
            dfs(grid1, grid2, i, j+1, m, n, is_lands);
        }
    }
};

int main() {
    return 0;
}