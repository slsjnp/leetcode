// 2022-01-29 20:32:23
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> dir = {{-1, 0},
                               {0,  -1},
                               {1,  0},
                               {0,  1}};
    vector<vector<int>> res;
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        // int dp[m][n];
        // memset(dp, -1, sizeof(dp));
        res = vector<vector<int>> (m, vector<int>(-1, n));
        queue<pair<int, int>> qu;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    qu.push({i, j});
                    res[i][j] = 0;
                }
            }
        }
        int i, j;
        while (!qu.empty()) {
            [i, j] = qu.top();
            qu.pop();
            for (auto it: dir) {
                int xx = i + it[0];
                int yy = j + it[1];
                if (xx >= 0 and xx < m and yy >= 0 and yy < n) {
                    res[xx][yy] = getMax(xx, yy);
                    qu.push({xx, yy});
                }
            }
        }
        return res;
    }

    int getMax(int i, int j) {
        int min_ = INT_MAX;
        int max_ = 0;
        for (auto it: dir) {
            int xx = i + it[0];
            int yy = j + it[1];
            if (xx >= 0 and xx < m and yy >= 0 and yy < n) {
                if (res[xx][yy] != -1 and min_ > res[xx][yy]){
                    min_ = res[xx][yy];
                }
                if (max_ < res[xx][yy]){
                    max_ = res[xx][yy];
                }
            }
        }
        assert(abs(min_ - max_) <= 1);
        if (min_ == max_){
            return min_ + 1;
        }
        else{
            return max_;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MapOfHighestPeak, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().mapOfHighestPeak(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}