// 2022-01-02 23:54:12
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        int flag = 1;
        int t = n;
        // int ans = t / 2;
        int start = 1;
        int step = 1;
        while (t != 1) {
            if (flag or (t & 1) != 0){
                start += step;
            }
            t /= 2;
            step *= 2;
            flag ^= 1;
        }
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(EliminationGame, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().eliminationGame(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}