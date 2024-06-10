// 2022-01-07 18:17:38
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int _size = nums.size();
        int ans;
        int low = 0;
        int high = _size - 1;
        int mid;
        // int pre = nums[0];
        // res.push_back(nums[0]);
        while (low < high and nums[0] == nums[high]) high--; // 恢复二分性
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            if (target < nums[0]) {
                // 右侧
                if (nums[mid] < target or nums[mid] > nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (nums[mid] > target or nums[mid] < nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SearchInRotatedSortedArrayIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().searchInRotatedSortedArrayIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}