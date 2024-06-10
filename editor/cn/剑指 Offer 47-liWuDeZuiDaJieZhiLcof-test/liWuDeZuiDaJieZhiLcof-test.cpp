// 2022-10-01 09:37:36
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j] = max(dp[j], dp[j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n];
    }
    // typedef pair<int, int> prii;
    // map<prii, int> ma;
    // vector<vector<int>> dir{{-1, 0},
    //                         {0,  -1}};
    //
    // int maxValue(vector<vector<int>> &grid) {
    //     queue<prii> qu;
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     prii tmp(m - 1, n - 1);
    //     ma[tmp] = grid[m - 1][n - 1];
    //     qu.push(prii(m - 1, n - 1));
    //     int x, y, xx, yy;
    //     while (!qu.empty()) {
    //         auto top = qu.front();
    //         qu.pop();
    //         x = top.first;
    //         y = top.second;
    //         for (auto it: dir){
    //             xx = it[0] + x;
    //             yy = it[1] + y;
    //             tmp = prii(xx, yy);
    //             if (xx < m && xx >= 0 && yy < n && yy >= 0 && (ma.count(tmp) == 0 || (ma.count(tmp) && ma[tmp] < ma[top] + grid[xx][yy]))){
    //                 ma[tmp] = ma[top] + grid[xx][yy];
    //                 qu.push(tmp);
    //             }
    //         }
    //     }
    //     return ma[prii(0, 0)];
    // }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LiWuDeZuiDaJieZhiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().liWuDeZuiDaJieZhiLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}