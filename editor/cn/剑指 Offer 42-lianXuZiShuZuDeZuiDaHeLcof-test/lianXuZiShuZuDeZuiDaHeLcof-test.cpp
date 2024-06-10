// 2022-08-30 18:09:31
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int _size = nums.size();
        // vector<int> pre(_size + 1, 0);
        // for (int i = 0; i < _size; ++i) {
        //     pre[i + 1] = pre[i] + nums[i];
        // }
        int dp[_size + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < _size; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LianXuZiShuZuDeZuiDaHeLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().lianXuZiShuZuDeZuiDaHeLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}