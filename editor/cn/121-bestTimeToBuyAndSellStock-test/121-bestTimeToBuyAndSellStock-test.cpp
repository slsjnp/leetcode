// 2022-08-03 18:37:16
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int _size = prices.size();
        vector<int> dp(_size + 1, 0);
        int min_ = prices[0];
        int max_ = 0;
        for (int i = 1; i < _size; ++i) {
            if (min_ > prices[i]) {
                min_ = prices[i];
            }
            if (prices[i] - min_ > max_) {
                max_ = prices[i] - min_;
            }
        }
        return max_;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BestTimeToBuyAndSellStock, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().bestTimeToBuyAndSellStock(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}