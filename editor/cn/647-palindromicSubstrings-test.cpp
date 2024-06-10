// 2022-03-11 17:42:11
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        int _size = s.size();
        int sum = 0;
        bool dp[_size][_size];
        memset(dp, 0, sizeof(dp));
        for (int i = _size - 1; i >= 0; --i) {
            for (int j = i; j < _size; ++j) {
                dp[i][j] = (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]));
                if(dp[i][j]) sum++;
            }
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(PalindromicSubstrings, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().palindromicSubstrings(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}