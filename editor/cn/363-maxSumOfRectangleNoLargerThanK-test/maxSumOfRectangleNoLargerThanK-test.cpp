// 2022-08-27 09:24:59
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MaxSumOfRectangleNoLargerThanK, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().maxSumOfRectangleNoLargerThanK(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}