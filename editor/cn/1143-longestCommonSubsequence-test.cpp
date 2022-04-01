// 2022-03-11 12:05:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        // for (int i = 0; i < n; ++i) {
        //     if (text1[i] == text2[0]) dp[i][0] = 1;
        // }
        // for (int i = 0; i < m; ++i) {
        //     if (text2[i] == text1[0]) dp[0][i] = 1;
        // }
        // int sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
                // if (text1[i - 1] == text2[j - 1]) {
                //     dp[i][j] = dp[i - 1][j - 1] + 1;
                // } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // sum = max(sum, dp[i][j]);
            }
        }
        return dp[n][m];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestCommonSubsequence, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().longestCommonSubsequence("abcde", "ace");
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}