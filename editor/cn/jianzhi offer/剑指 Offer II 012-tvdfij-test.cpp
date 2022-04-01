// 2022-03-10 16:57:33
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int _size = nums.size();
        vector<int> pre(_size + 1, 0);
        for (int i = 0; i < _size; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        for (int i = 0; i < _size; ++i) {
            if (pre[i] == pre[_size] - pre[i + 1]){
                return i;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Tvdfij, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().tvdfij(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}