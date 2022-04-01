// 2022-03-11 20:01:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {
        int _size = s.size();
        int t_size = t.size();
        int dp[_size + 1][t_size + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= _size; ++i) {
            dp[i][t_size] = 1;
        }
        int l = 0;
        for (int i = _size - 1; i >= 0; --i) {
            for (int j = t_size - 1; j >= 0; --j) {
                if (s[i] == t[j]){
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                }
                else{
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DistinctSubsequences, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().distinctSubsequences(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}