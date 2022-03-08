// 2022-01-13 23:13:50
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int _size = nums.size();
        auto max_ = max_element(nums.begin(), nums.end());
        for (int i = 0; i < _size; ++i) {
            if (nums[i] != *max_ and *max_ < nums[i] * 2){

                return -1;
            }
        }
        return max_ - nums.begin();
        // return *max_;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LargestNumberAtLeastTwiceOfOthers, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().largestNumberAtLeastTwiceOfOthers(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}