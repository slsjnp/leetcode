// 2022-01-07 13:01:18
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int _size = nums.size();
        int low=0;
        int high=_size - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (target == nums[mid] ){
                high = mid - 1;
            }
            if (target < nums[mid]){
                high = mid - 1;
            }
            if (target > nums[mid]){
                low = mid + 1;
            }
        }
        if (low == _size or nums[low] != target){
            return {-1,-1};
        }
        int start = low;
        high=_size - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (target == nums[mid] ){
                low = mid + 1;
            }
            if (target < nums[mid]){
                high = mid - 1;
            }
            if (target > nums[mid]){
                low = mid + 1;
            }
        }
        return {start, high};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FindFirstAndLastPositionOfElementInSortedArray, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().findFirstAndLastPositionOfElementInSortedArray(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}