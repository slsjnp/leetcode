// 2023-09-19 22:46:29
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        int _size = nums.size();
        if (_size == 1){
            return nums[0];
        } else if (_size == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(_size + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < _size; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        // return max(dp[_size], dp[_size - 1]);
        return dp[_size - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(HouseRobber, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().houseRobber(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}