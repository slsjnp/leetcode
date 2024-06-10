// 2021-11-12 23:25:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        int sum = n * (n + 1) / 2;
        vector<int> pre_sum(n + 1);
        pre_sum[0] = 0;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + i;
        }
        int ind = 0;
        int l = sum / 2;
        while (ind != n){
            ind = lower_bound(pre_sum.begin() + ind, pre_sum.end(), l) - pre_sum.begin();
            if (ind >= n){
                break;
            }
            res += ind;
            sum = pre_sum[n] - pre_sum[ind];
            l = pre_sum[ind] + sum / 2;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(GuessNumberHigherOrLowerIi, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        int n = 6;
        auto ans = Solution().getMoneyAmount(n);
        decltype(ans) rightAns = 16;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}