// 2022-08-23 10:47:57
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        bool flag = n > 0;
        double res = 1;
        long nn = n;
        if (n < 0) nn = -1ll * n;
        while (nn > 0){
            if (nn & 1){
                res *= x;
            }
            x *= x;
            nn /= 2;
        }
        if (flag){
            return res;
        } else{
            return 1 / res;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ShuZhiDeZhengShuCiFangLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().shuZhiDeZhengShuCiFangLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}