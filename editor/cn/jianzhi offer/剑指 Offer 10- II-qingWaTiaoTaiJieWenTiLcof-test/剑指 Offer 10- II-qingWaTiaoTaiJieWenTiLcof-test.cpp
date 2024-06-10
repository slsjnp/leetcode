// 2022-08-18 00:26:36
#include <gtest/gtest.h>
#include "../../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numWays(int n) {
        int a[n + 1];
        memset(a, 0, sizeof(a));
        if (n == 0) return 1;
        if (n <= 2) return n;
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= n; ++i) {
            a[i] = a[i - 1] + a[i - 2];
            a[i] %= 1000000007;
        }
        return a[n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(QingWaTiaoTaiJieWenTiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().qingWaTiaoTaiJieWenTiLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}