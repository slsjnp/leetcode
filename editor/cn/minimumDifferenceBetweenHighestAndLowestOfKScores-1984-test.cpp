// 2022-02-11 17:26:48
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumDifferenceBetweenHighestAndLowestOfKScores, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().minimumDifferenceBetweenHighestAndLowestOfKScores(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}