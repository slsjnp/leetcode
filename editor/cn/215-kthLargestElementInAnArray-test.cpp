// 2022-03-18 23:57:31
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int _size = nums.size();
        qsort(nums, 0, _size - 1, _size - k);
        return nums[_size - k];
    }

    int qsort(vector<int> &nums, int l, int r, int k) {
        int start = l;
        int end = r;
        if (l == r) return l;
        int len = r - l;
        int idx = random() % len + l;
        swap(nums[idx], nums[l]);
        int now = nums[l];
        while(l < r){
            while (l < r && nums[r] > now) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= now) l++;
            nums[r] = nums[l];
        }
        nums[l] = now;
        if (l == k){
            return l;
        }
        else if (l < k){
            return qsort(nums, l + 1, end, k);
        }
        else if (l > k){
            return qsort(nums, start, l - 1, k);
        }
        return 0;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(KthLargestElementInAnArray, Example1) {      // NOLINT
        std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
        auto ans = Solution().findKthLargest(nums, 4);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}