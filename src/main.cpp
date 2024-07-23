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
给你一个 n * n 的网格 grid ，上面放置着一些 1 x 1 x 1 的正方体。​

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。​

放置好正方体后，任何直接相邻的正方体都会互相粘在一起，形成一些不规则的三维形体。​

请你返回最终这些形体的总表面积。​

注意：每个形体的底面也需要计入表面积中。​

输入：grid = [[1,2],[3,4]]​
输出：34​

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]​
输出：32
*/

int calculate_area(std::vector<std::vector<int> > &vec) {
    if (vec.size() == 0 || vec[0].size() == 0) {
        return 0;
    }
    int all_area = 0;
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        if (vec[i].size() != n) {
            return 0;
        }
        int max_raw = 0;
        int max_col = 0;
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] > 0) {
                all_area += 2;
            }
            if (vec[i][j] > max_raw) {
                max_raw = vec[i][j];
            }
            if (vec[j][i] > max_col) {
                max_col = vec[j][i];
            }
        }
        all_area += 2 * max_raw;
        all_area += 2 * max_col;
    }
    return all_area;
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

std::vector<int> f(std::vector<std::vector<int> > &vec, int m, int n) {
    int i = 0;
    int j = 0;
    std::vector<int> res;
    while(i < m - i && j < n - j) {
        int ii = i;
        int jj = j;
        while (jj <= n - j - 1) {
            res.push_back(vec[ii][jj]);
            jj++;
        }
        jj--;
        ii++;
        while (ii <= m - i - 1) {
            res.push_back(vec[ii][jj]);
            ii++;
        }
        ii--;
        jj--;
        while(jj >= j + 1) {
            res.push_back(vec[ii][jj]);
            jj--;
        }
        jj++;
        ii--;
        while(ii >= i + 1) {
            res.push_back(vec[ii][jj]);
            ii--;
        }
        i++;
        j++;
    }
    return res;
}
std::vector<int> print_array(std::vector<std::vector<int> > &vec) {
    if (vec.size() == 0 || vec[0].size() == 0) {
        return std::vector<int>();
    }
    int left = 0;
    int right = vec[0].size() - 1;
    int top = 0;
    int bottom = vec.size() - 1;
    std::vector<int> res;
    while(left < right && top < bottom) {
        for (int i = left; i < right; i++) {
            res.push_back(vec[top][i]);
        }
        for (int i = top + 1; i < bottom; i++) {
            res.push_back(vec[i][right]);
        }
        for (int i = right -1; i > left; i--) {
            res.push_back(vec[bottom][i]);
        }
        for (int i = bottom - 1; i > top; i--) {
            res.push_back(vec[i][left]);
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return res;
}

void print(std::vector<int> &vec) {
    for(const auto &key : vec) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
}

// 
class CalculateMaxArea {
public:
    double calculate_area(const vector<int> &point1,
                            const vector<int> &point2,
                            const vector<int> &point3) {
        double x1 = point2[0] - point1[0];
        double y1 = point2[1] - point1[1];

        double x2 = point3[0] - point1[0];
        double y2 = point3[1] - point1[1];

        double area = x1 * y2 - x2 * y1;
        return area > 0 ? area * 0.5 : -area * 0.5;
    }
    double largestTriangleArea(vector<vector<int> >& points) {
        // 叉乘
        if (points.size() < 3) {
            return 0.0;
        }
        int n = points.size();
        double max_area = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; j++) {
                for (int m = j + 1; m < n; m++) {
                    double area =  calculate_area(points[i], points[j], points[m]);
                    if (max_area < area) {
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};

class MatrixOverlap {
public:
    bool is_point_in_line_right(vector<int> &point1, vector<int> &point2, vector<int> &point3) {
        // 计算 pt 在 p1,p2 的坐标
        double x1 = point2[0] - point1[0];
        double y1 = point2[1] - point1[1];

        double x2 = point3[0] - point1[0];
        double y2 = point3[1] - point1[1];

        double area = x1 * y2 - x2 * y1;
        return area < 0;
    }
    std::vector<std::vector<int> > getPoints(const vector<int> &rec) {
        // 计算四个点
        std::vector<std::vector<int> > points;
        points.push_back({rec[0], rec[1]});
        points.push_back({rec[2], rec[1]});
        points.push_back({rec[2], rec[3]});
        points.push_back({rec[0], rec[3]});
        return points;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        std::vector<std::vector<int> > rec1_points = getPoints(rec1);
        std::vector<std::vector<int> > rec2_points = getPoints(rec2);
        for (int i = 1; i < rec1_points.size(); i++) {
            bool is_right = true;
            for (int j = 0; j < rec2_points.size(); j++) {
                if (!is_point_in_line_right(rec1_points[i - 1], rec1_points[i], rec2_points[j])) {
                    is_right = false;
                    break;
                }
            }
            if (is_right) {
                return false;
            }
        }
        return true;
    }
};

/*
给你两个下标从 0 开始的字符串 s 和 target 
你可以从 s 取出一些字符并将其重排，得到若干新的字符串。
从 s 中取出字符并重新排列，返回可以形成 target 的最大副本数。

 
示例 1：
输入：s = "ilovecodingonleetcode", target = "code"
输出：2
解释：
对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
可以形成最多 2 个 "code" 的副本，所以返回 2

示例 2：
输入：s = "abcba", target = "abc"
输出：1
解释：
选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。 
可以形成最多 1 个 "abc" 的副本，所以返回 1 。
注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。

示例 3：
输入：s = "abbaccaddaeea", target = "aaaaa"
输出：1
解释：
选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。
 

提示：
1 <= s.length <= 100
1 <= target.length <= 10
s 和 target 由小写英文字母组成
*/

class RearrangeCharacters {
public:
    int rearrangeCharacters(string s, string target) {
        std::vector<int> s_count(target.size(), 0);
        int min_size = std::MAX_INT;
        for (const auto ch : s) {
            if (target.find(ch) != std::string::npos) {
                s_count[target.find(ch)]++;
            }
            for (int i = 0; i < target.size(); i++) {
                if (s_count[i] < min_size) {
                    min_size = s_count[i];
                }
            }
        }
        return min_size;
    }
};

/*
1170. 比较字符串最小字母出现频次
定义一个函数 f(s)，统计 s  中（按字典序比较）最小字母的出现频次
其中 s 是一个非空字符串。
例如，若 s = "dcce"，那么 f(s) = 2，因为字典序最小字母是 "c"，它出现了 2 次。

现在，给你两个字符串数组待查表 queries 和词汇表 words 。对于每次查询 queries[i] 
需统计 words 中满足 f(queries[i]) < f(W) 的 词的数目 ，W 表示词汇表 words 中的每个词。

请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是第 i 次查询的结果。

 

示例 1：

输入：queries = ["cbd"], words = ["zaaaz"]
输出：[1]
解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
示例 2：

输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
输出：[1,2]
解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 

提示：

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j]、words[i][j] 都由小写英文字母组成
words =
["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]
*/

class NumSmallerByFrequency {
public:
    int find_min_num(const std::string& s) {
        int num = 1;
        char a = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (a == s[i]) {
                num++;
            } else if (s[i] < a) {
                a = s[i];
                num = 1;
            }
        }
        return num;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        std::vector<int> res;
        for (const auto w : words) {
            res.emplace_back(find_min_num(w));
        }
        std::sort(res.begin(), res.end());
        std::vector<int> ans;
        for (const auto &q : queries) {
            int num = find_min_num(q);
            auto it = std::upper_bound(res.begin(), res.end(), num);
            ans.emplace_back(std::distance(it, res.end()));
        }
        return ans;
    }
};

/*
最大的以 1 为边界的正方形
给你一个由若干 0 和 1 组成的二维网格 grid，
请你找出边界全部由 1 组成的最大 正方形 子网格，
并返回该子网格中的元素数量。如果不存在，则返回 0。
https://mp.weixin.qq.com/s?__biz=MzU0ODMyNDk0Mw==&mid=2247490443&idx=1&sn=fc1b5e2f52083366fa73c0b9b47c6d31&chksm=fb4188abcc3601bda60a042d2908d50f00b362cd14631b30bf4bff0e277e3187134a666ddd2c&scene=21&poc_token=HG-9XmajWlwsJcxdPxefEVu1kpbLsKNLRr9m_Vb6
示例 1：
输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9
示例 2：

输入：grid = [[1,1,0,0]]
输出：1
提示：
1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] 为 0 或 1
*/

class Largest1BorderedSquare {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {

    }
};
/*
779. 第K个语法符号
我们构建了一个包含 n 行( 索引从 1  开始 )的表。首先在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

例如，对于 n = 3 ，第 1 行是 0 ，第 2 行是 01 ，第3行是 0110 。
给定行 数 n 和序数 k，返回第 n 行中第 k 个字符。（ k 从索引 1 开始）
0    1 
01   2
01 10   4
01 10 10 01   8 
01 10 10 01 10 01 01 10   16
01 10 10 01 10 01 01 10 10 01 01 10 01 10 10 01   32

示例 1:

输入: n = 1, k = 1
输出: 0
解释: 第一行：0
示例 2:

输入: n = 2, k = 1
输出: 0
解释: 
第一行: 0 
第二行: 01
示例 3:

输入: n = 2, k = 2
输出: 1
解释:
第一行: 0
第二行: 01
*/

class KthGrammar {
public:
    int kthGrammar(int n, int k) {
        int left = 1, right = 1<<(n - 1), mid = -1;
        int cur = 0;
        while(left < right) {
            mid = (left + right)>>1;
            if (k < mid) {
                right = mid - 1;
                cur = cur == 0 ? 0 : 1;
            } else {
                left = mid;
                cur = cur == 0 ? 1 : 0;
            }
        }
        return cur;
    }
};

/*
1288. 删除被覆盖区间
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
在完成所有删除操作后，请你返回列表中剩余区间的数目。

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 

提示：​​​​​​
1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
对于所有的 i != j：intervals[i] != intervals[j]
*/
class RemoveCoveredIntervals {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int del_num = 0; // [[1,4],[3,6],[2,8]]
        std::vector<bool> is_del(intervals.size(), false);
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = i + 1; j < intervals.size(); ++j) {
                if (is_del[j] || is_del[i]) {
                    continue;
                }
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                    is_del[j] = true;
                    del_num++;
                    continue;
                }
                if (intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    is_del[i] = true;
                    del_num++;
                }
            }
        }
        return intervals.size() - del_num;
    }
};


/*
1186. 删除一次得到子数组最大和
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，
所能得到的最大元素总和。换句话说，你可以从原数组中选出一个子数组，
并可以决定要不要从中删除一个元素（只能删一次哦），
（删除后）子数组中至少应当有一个元素，
然后该子数组（剩下）的元素总和是所有子数组之中最大的。
注意，删除一个元素后，子数组 不能为空。


示例 1：

输入：arr = [1,-2,0,3]
输出：4
解释：我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。
示例 2：

输入：arr = [1,-2,-2,3]
输出：3
解释：我们直接选出 [3]，这就是最大和。
示例 3：

输入：arr = [-1,-1,-1,-1]
输出：-1
解释：最后得到的子数组不能为空，所以我们不能选择 [-1] 并从中删去 -1 来得到 0。
     我们应该直接选择 [-1]，或者选择 [-1, -1] 再从中删去一个 -1。
 

提示：
1 <= arr.length <= 105
-104 <= arr[i] <= 104
*/

class MaximumSum { //*******
public: 
    int maximumSum(vector<int>& arr) {
        std::vector<vector<int> > dp(arr.size());
        dp[0].resize(2); 
        dp[0][0] = arr[0]; // 未删除 1
        dp[0][1] = arr[0]; // 删除 1
        int max_num = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            dp[i].resize(2);
            dp[i][0] = dp[i - 1][0] + arr[i]; // 未删除 -1
            dp[i][1] = dp[i][0];             
            for(int j = i - 1; j >=0; j--) {
                dp[i][1] = std::max(dp[i][1], arr[i] + dp[j][1]);
            }
            max_num = std::max(max_num, dp[i][1]);
        }
        return max_num;
    }
};

/*
1026. 节点与其祖先之间的最大差值
给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。
（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

示例 1：
输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。

示例 2：
输入：root = [1,null,2,null,0,3]
输出：3
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class MaxAncestorDiff {
public:
    void generateMaxVal(TreeNode* root, int &max_val, int root_num){
        if (!root) { 
            return;
        }
        if (root->left) {
            max_val = std::max(max_val, abs(root_num - root->left->val));
            generateMaxVal(root->left, max_val, root_num);
        }
        if (root->right) {
            max_val = std::max(max_val, abs(root_num - root->right->val));
            generateMaxVal(root->right, max_val, root_num);
        }
    }
    void maxAncestorDiff(TreeNode* root, int &max_num){
        if (!root) { 
            return;
        }
        generateMaxVal(root, max_num, root->val);
        maxAncestorDiff(root->left, max_num);
        maxAncestorDiff(root->right, max_num);
    }
    int maxAncestorDiff(TreeNode* root) {
        int max_num = 0;
        maxAncestorDiff(root, max_num);
        return max_num;
    }
};
/*
/*
2368. 受限条件下可到达节点的数目

[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]

[4,5]

*/
class ReachableNodes {
public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                              vector<int>& restricted) {
        std::unordered_map<int, std::vector<int>> graph;
        std::deque<int> deq;
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][0] == 0 || edges[i][1] == 0) {
                if (edges[i][0] != 0) {
                    auto it = std::find(restricted.begin(), restricted.end(), edges[i][0]);
                    if (it == restricted.end()){
                        deq.push_back(edges[i][0]);
                    }
                }
                if (edges[i][1] != 0) {
                    auto it = std::find(restricted.begin(), restricted.end(), edges[i][1]);
                    if (it == restricted.end()){
                        deq.push_back(edges[i][1]);
                    }
                }
                continue;            
            }
            auto it = std::find(restricted.begin(), restricted.end(), edges[i][0]);
            auto it1 = std::find(restricted.begin(), restricted.end(), edges[i][1]);
            if (it == restricted.end()) {
                if (graph.find(edges[i][0]) == graph.end()) {
                    graph[edges[i][0]] = std::vector<int>();
                }
                if (it1 == restricted.end()) {
                    graph[edges[i][0]].push_back(edges[i][1]);
                }
            }
            if (it1 == restricted.end()) {
                if (graph.find(edges[i][1]) == graph.end()) {
                    graph[edges[i][1]] = std::vector<int>();
                }
                if (it == restricted.end()) {
                    graph[edges[i][1]].push_back(edges[i][0]);
                }
            }
        }
        std::unordered_set<int> visited;
        while(!deq.empty()) {
            int num = deq.front();
            deq.pop_front();
            visited.insert(num);
            if (graph.find(num) == graph.end()) {
                for (auto n : graph[num]) {
                    deq.push_back(n);
                }
            }
        }
        return visited.size() + 1;
    }
};

int main() {
    // [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]

    // [4,5]
    std:vector<std::vector<int>> edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    std::vector<int> restricted = {4,5};
    ReachableNodes rn;
    std::cout << rn.reachableNodes(7, edges, restricted) << std::endl;
    return 0;
}
