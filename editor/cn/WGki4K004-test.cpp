// 2021-11-23 17:52:05
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // uint32_t bi = 0;
        int _size = nums.size();
        int bi[32];
        memset(bi, 0, sizeof(bi));
        for (int i = 0; i < _size; ++i) {
            for (int j = 0; j < 32; ++j) {
                bi[j] += (nums[i] >> j) & 1;
            }
        }
        int sum = 0;
        long t = 1;
        for (int i = 0; i < 32; ++i) {
            sum += bi[i] % 3 * t;
            t *= 2;
        }
        return sum;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(WGki4K, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().WGki4K(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}