// 2021-11-07 23:57:03
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int _size = quantities.size();
        float sum = 0;
        for (int i = 0; i < _size; ++i) {
            sum += quantities[i];
        }
        int _max = 1;
        int top = n * ceil(sum / n);
        for (int i = 0; i < _size; ++i) {
            if (quantities[i] /   > quantities[i] / sum){
                _max = max(_max, (int)ceil(quantities[i] / (sum / n)));
            }
        }
        return _max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimizedMaximumOfProductsDistributedToAnyStore, Example1) {      // NOLINT
        int a = 6;
        std::vector<int> nums = { 11, 6 };
        auto ans = Solution().minimizedMaximum(a, nums);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}