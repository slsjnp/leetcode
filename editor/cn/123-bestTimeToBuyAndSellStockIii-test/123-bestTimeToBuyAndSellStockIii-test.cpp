// 2022-08-03 21:27:53
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 错过买卖股票最佳时机，倾家荡产，为了生计，做过粉刷房子的工人，给栅栏涂过色，
// 只有零钱兑换一点食物，无奈还是变为打家劫舍的小偷，通过不同路径来到河边，放下背包，看到青蛙， 原地架锅起火，回想动态规划的一生！
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _size = prices.size();
        vector<int> dp(_size, 0);
        vector<int> redp(_size, 0);

        int min_ = prices[0];
        int max_ = 0;
        for(int i = 0; i < _size; ++i){
            if(min_ > prices[i]){
                min_ = prices[i];
            }
            if (max_ < prices[i] - min_){
                max_ = prices[i] - min_;
            }
            dp[i] = max_;
        }

        max_ = prices[_size - 1];
        int sum = 0;
        for (int i = _size - 1; i >= 0; i--){
            if (max_ < prices[i]){
                max_ = prices[i];
            }
            if (sum < max_ - prices[i]){
                sum = max_ - prices[i];
            }
            redp[i] = sum;
        }
        sum = 0;
        for (int i = 0; i < _size ; ++i){
            sum = max(sum, dp[i] + redp[i]);
        }
        return sum;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BestTimeToBuyAndSellStockIii, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().bestTimeToBuyAndSellStockIii(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}