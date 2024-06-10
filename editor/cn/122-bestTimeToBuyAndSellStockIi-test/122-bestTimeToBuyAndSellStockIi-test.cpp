// 2022-08-03 20:51:03
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _size = prices.size();
        int dp[_size][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < _size ; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return max(dp[_size - 1][0], dp[_size - 1][1] + prices[_size - 1]);

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BestTimeToBuyAndSellStockIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().bestTimeToBuyAndSellStockIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}