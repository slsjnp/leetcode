// 2022-03-05 17:40:02
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int > res(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            int mask = i;
            int sum = 0;
            for (; mask > 0 ; mask &= mask-1) {
                sum++;
            }
            res[i]= sum;
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(W3tCBm, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().w3tCBm(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}