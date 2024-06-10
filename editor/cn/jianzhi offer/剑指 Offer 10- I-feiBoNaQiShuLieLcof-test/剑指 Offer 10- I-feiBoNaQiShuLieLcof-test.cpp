// 2022-08-18 00:20:08
#include <gtest/gtest.h>
#include "../../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        static const int mod = 1000000007;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int tmp;
        for (int i = 0; i < n - 1; ++i) {
            tmp = a;
            a = b;
            b = tmp + b;
            b %= mod;
            a %= mod;
        }
        return b;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FeiBoNaQiShuLieLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().feiBoNaQiShuLieLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}