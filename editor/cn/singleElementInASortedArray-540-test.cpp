// 2022-02-14 12:38:06
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int sum = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     sum ^= nums[i];
        // }
        int _size = nums.size();
        int l = 0, h = nums.size() - 1;
        int mid;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if ((mid + 1 < _size and nums[mid] != nums[mid + 1]) and (mid - 1 >= 0 and nums[mid - 1] != nums[mid])){
                return nums[mid];
            }
            else if ((mid - 1 >= 0 and nums[mid] == nums[mid - 1] and mid % 2 == 0) or (mid + 1 < _size and nums[mid] == nums[mid + 1] and mid % 2 == 1)){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return nums[l - 1];
    }

    int xore(vector<int> &nums, int l, int r) {
        assert(r < nums.size());
        int sum = 0;
        for (int i = l; i < r; ++i) {
            sum ^= nums[i];
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SingleElementInASortedArray, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().singleElementInASortedArray(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}