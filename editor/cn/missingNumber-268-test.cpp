// 2021-11-06 22:59:57
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int _size = nums.size();
        int sum = 0;
        for (int i = 0; i < _size; ++i) {
            sum ^= i;
            sum ^= nums[i];
        }
        sum ^= _size;
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MissingNumber, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().missingNumber(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}