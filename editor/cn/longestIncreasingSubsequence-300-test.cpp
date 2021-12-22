// 2021-12-19 21:02:02
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int _size = nums.size();
        vector<int> dp;
        dp.emplace_back(nums[0]);
        for (int i = 1; i < _size; ++i) {
            auto up = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (up == dp.end()) {
                dp.emplace_back(nums[i]);
            } else {
                *up = nums[i];
            }
        }
        return dp.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestIncreasingSubsequence, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().longestIncreasingSubsequence(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}