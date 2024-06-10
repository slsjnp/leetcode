// 2022-08-23 10:55:07
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res((int)pow(10, n) - 1);
        iota(res.begin(),res.end(), 1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DaYinCong1daoZuiDaDeNweiShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().daYinCong1daoZuiDaDeNweiShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}