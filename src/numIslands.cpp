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
200. 岛屿数量
1905. 统计子岛屿
*/

class NumIslands {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        // 遍历当前节点的前后左右，是否还有陆地
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {dfs(grid, i - 1, j, n, m);}
        if (i + 1 < n && grid[i + 1][j] == '1') {dfs(grid, i + 1, j, n, m);}
        if (j - 1 >= 0 && grid[i][j - 1] == '1') {dfs(grid, i, j - 1, n, m);}
        if (j + 1 < m && grid[i][j + 1] == '1') {dfs(grid, i, j + 1, n, m);}
    }

    int numIslands_DFS(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        int land_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // 找到一个陆地，然后进行深度优先搜索，将遍历过的陆地标记为0
                if (grid[i][j] == '1') {
                    land_count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return land_count;
    }

    int numIslands_BFS(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        int land_count = 0;
        std::deque<std::pair<int, int>> deq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    land_count++;
                    grid[i][j] = '0';
                    deq.push_back(std::make_pair(i, j));
                    while(!deq.empty()) {
                        auto p = deq.front();
                        deq.pop_front();
                        int x = p.first;
                        int y = p.second;
                        if (x - 1 >=0 && grid[x-1][y]=='1'){
                            grid[x-1][y] = '0';
                            deq.push_back(std::make_pair(x - 1, y));
                        }
                        if (x + 1 < n && grid[x+1][y]=='1'){
                            grid[x+1][y] = '0';
                            deq.push_back(std::make_pair(x + 1, y));
                        }
                        if (y - 1 >=0 && grid[x][y-1]=='1'){
                            grid[x][y-1] = '0';
                            deq.push_back(std::make_pair(x, y - 1));
                        }
                        if (y + 1 < m && grid[x][y+1]=='1'){
                            grid[x][y+1] = '0';
                            deq.push_back(std::make_pair(x, y + 1));
                        }
                    }
                }
            }
        }
        return land_count;
    }
};

int main() {
    std::cout << "11" << std::endl;
    return 0;
}