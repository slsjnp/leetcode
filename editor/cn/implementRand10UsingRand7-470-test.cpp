// 2021-11-01 17:53:47
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    // int rand10() {
    //     int row, col, idx;
    //     do {
    //         row = rand7();
    //         col = rand7();
    //         idx = col + (row - 1) * 7;
    //     } while (idx > 40);
    //     return 1 + (idx - 1) % 10;
    // }
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = row + (col - 1) * 7;
        } while (idx > 40);
        return idx % 10 + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ImplementRand10UsingRand7, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().implementRand10UsingRand7(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}