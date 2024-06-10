// 2023-09-19 23:03:04
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
        } else if (_size == 3){
            return max({nums[0], nums[1], nums[2]});
        }
        vector<int> dp(_size + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < _size - 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        // return max(dp[_size], dp[_size - 1]);
        int _max = dp[_size - 2];

        dp.clear();
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < _size; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return max(_max, dp[_size - 1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(HouseRobberIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().houseRobberIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}