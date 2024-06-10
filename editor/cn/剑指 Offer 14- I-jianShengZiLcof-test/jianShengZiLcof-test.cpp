// 2022-08-22 22:24:54
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingRope(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        if (n <= 3) return n - 1;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(JianShengZiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().jianShengZiLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}