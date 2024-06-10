// 2022-03-27 14:19:55
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int _size = piles.size();
        int dp[_size][_size];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < _size; ++i) {
            dp[i][i] = piles[i];
        }

        // 转移方程为
        // dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
        for (int i = _size - 2; i > 0 ; --i) {
            for (int j = i + 1; j < _size; ++j) {
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
            }
        }
        return dp[0][_size - 1] > 0;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(StoneGame, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().stoneGame(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}