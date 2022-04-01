// 2022-03-11 11:38:15
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int _size = nums.size();
        int dp[_size];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int sum = 1;
        for (int i = 1; i < _size; ++i) {
            if (nums[i] > nums[i - 1]){
                dp[i] = dp[i - 1] + 1;
            }
            else{
                dp[i] = 1;
            }
            sum = max(dp[i], sum);
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestContinuousIncreasingSubsequence, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().longestContinuousIncreasingSubsequence(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}