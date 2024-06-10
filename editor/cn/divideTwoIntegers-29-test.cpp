// 2022-01-07 19:15:34
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if (divisor == -1 and dividend == INT_MIN){
            return INT_MAX;
        }
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        int flag;
        if (((dividend < 0) ^ (divisor < 0)) != 0){
            flag = 1;
        }else flag = 0;
        // 把所有数转变成负数求解， 这样不会溢出

        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor: divisor;
        while (dividend <= divisor){ // 这里不要写成 dividend <= 0 ，这样会多循环一次造成溢出
            int step = 1;
            int tmp = divisor;
            while (dividend - tmp <= tmp){ // 这里也不要写成 tmp + tmp >= dividend ，也会造成溢出，死循环
                tmp += tmp;
                step <<= 1;
            }
            ans += step;
            dividend -= tmp;
        }
        // ans--;
        return flag ? -ans: ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DivideTwoIntegers, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().divideTwoIntegers(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}