// 2022-08-17 23:03:39
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)

union task {
    int32_t i;
    struct task_t{
        int8_t lock;
        int8_t pending;
    } a;
    struct test{
        int16_t lock_pending;
        int16_t tail;
    } b;
};

namespace {
    TEST(UncrossedLines, Example2) {      // NOLINT
        task c{};
        c.a.pending = 1;
        printf("%d", c.i);

        // std::vector<int> nums = {  };
        // auto ans = Solution().uncrossedLines(nums);
        // decltype(ans) rightAns = ;
        // ASSERT_EQ(ans, rightAns);
    }


// namespace {
//     TEST(FindTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance, Example1) {      // NOLINT
//         std::vector<int> nums = {  };
//         auto ans = Solution().findTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance(nums);
//         decltype(ans) rightAns = ;
//         ASSERT_EQ(ans, rightAns);
//     }
//
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}