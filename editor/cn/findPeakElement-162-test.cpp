// 2022-01-08 18:14:51
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int _size = nums.size();
        // int low = 0;
        // int high = _size - 1;
        int mid ;
        int l = 0, r = _size - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FindPeakElement, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().findPeakElement(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}