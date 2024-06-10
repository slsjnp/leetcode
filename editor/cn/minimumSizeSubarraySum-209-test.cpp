// 2021-11-01 14:07:48
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n + 1);
        int min;
        int sum = 0;
        tmp[0] = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            tmp[i + 1] = sum;
        }
        int ind = lower_bound(tmp.begin(), tmp.end(), target) - tmp.begin();
        if (ind == n + 1){
            return 0;
        }
        int len = ind;
        while(ind <= n){
            if (tmp[ind] - tmp[ind - len + 1] >= target){
                len--;
            }
            else {
                ind++;
            }
        }
        return len;




    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumSizeSubarraySum, Example1) {      // NOLINT
        std::vector<int> nums = {2,3,1,2,4,3 };
        int target = 7;
        auto ans = Solution().minSubArrayLen(target, nums);
        decltype(ans) rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}