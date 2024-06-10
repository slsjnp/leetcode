// 2022-01-04 18:31:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int _size = nums.size();
        int low=0;
        int high=_size -1;
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
        // printf("%d\n",INT_MAX);
        return low;
    }
};
// class Solution {
// public:
//     int searchInsert(vector<int> &nums, int target) {
//         int _size = nums.size();
//         int r = _size - 1; //
//         int l = 0;
//         int mid;
//         while (l <= r) {  //
//             mid = l + (r - l) / 2;
//             if (nums[mid] == target) {
//                 r = mid - 1;  //
//             } else if (nums[mid] > target) {
//                 r = mid - 1; //
//             } else if (nums[mid] < target) {
//                 l = mid + 1;
//             }
//         }
//         return l;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SearchInsertPosition, Example1) {      // NOLINT
        std::vector<int> nums = {1,3,5,5,5,5,5,5,5,6};
        auto ans = Solution().searchInsert(nums, 5);
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}