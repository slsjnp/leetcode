// 2022-03-09 21:42:04
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        int _size = nums.size();
        vector<int> dp(_size + 1, 0);
        if (_size == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        if (_size == 2) return dp[_size - 1];
        for (int i = 2; i < _size; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[_size - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Gu0c2T, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().Gu0c2T(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}