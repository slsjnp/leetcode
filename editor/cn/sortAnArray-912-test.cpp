// 2021-11-01 14:23:34
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        quick_sort(nums, 0, nums.size());
        return nums;
    }
    void quick_sort(vector<int>& nums, int lr, int rr){
        if (lr == rr) return ;
        int l = lr, r = rr - 1;
        int ran = rand() % (rr - lr) + lr;
        swap(nums[ran], nums[r]);
        int comp = nums[r];
        while(l < r){
            while (l < r and comp >= nums[l]) l++;
            if (l < r) nums[r--] = nums[l];
            while (l < r and comp <= nums[r]) r--;
            if (l < r) nums[l++] = nums[r];
        }
        nums[l] = comp;
        quick_sort(nums, lr, l);
        quick_sort(nums, l + 1, rr);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SortAnArray, Example1) {      // NOLINT
        std::vector<int> nums = { 5,2,3,1 };
        auto ans = Solution().sortArray(nums);
        decltype(ans) rightAns = {1, 2, 3, 5};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}