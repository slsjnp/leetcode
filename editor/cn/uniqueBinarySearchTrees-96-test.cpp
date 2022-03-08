// 2022-01-19 21:27:25
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        int dp[20];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] += dp[j - 0] + dp[i - j];
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(UniqueBinarySearchTrees, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().uniqueBinarySearchTrees(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}