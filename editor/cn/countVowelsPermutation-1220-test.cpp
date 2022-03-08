// 2022-01-17 22:50:49
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[20005][5];
        memset(dp, 0, sizeof(dp));
        // {a, e, i, o, u}
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
        dp[0][4] = 1;
        const long long m = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % m; //a
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % m;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % m;
            dp[i][3] = (dp[i - 1][2]) % m;
            dp[i][4] = (dp[i - 1][3] + dp[i - 1][2]) % m;
        }
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += (int) (dp[n - 1][i] % (long long)(1e9 + 7));
        }

        return sum;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CountVowelsPermutation, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().countVowelsPermutation(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}