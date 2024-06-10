// 2022-01-07 20:44:58
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int _size = nums.size();
        int ans;
        int low = 0;
        int high = _size - 1;
        int mid;
        while (low <= high){
            mid = low + (high - low) / 2;
            if (nums[mid] >= nums[0]){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if (low == _size or nums[low] > nums[0]){
            return nums[0];
        }
        else{
            return nums[low];
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FindMinimumInRotatedSortedArray, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().findMinimumInRotatedSortedArray(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}