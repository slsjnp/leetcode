// 2022-01-10 21:55:02
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        int _size = nums.size();
        pre = vector<int> (_size + 1, 0);
        for (int i = 0; i < _size; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RangeSumQueryImmutable, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().rangeSumQueryImmutable(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}