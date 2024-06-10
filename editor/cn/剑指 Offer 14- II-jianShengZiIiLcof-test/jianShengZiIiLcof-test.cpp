// 2022-08-22 23:31:42
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static const int mod = 1000000007;
    int cuttingRope(int n) {

        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int)pow_(3, quotient);
        } else if (remainder == 1) {
            return (int) (pow_(3, quotient - 1) * 4 % mod);
        } else {
            return (int) (pow_(3, quotient) * 2 % mod);
        }
    }

    long pow_(int i, int p){
        long tmp = i;
        long result = 1;
        while (p > 0){
            if (p & 1){
                result = tmp * result % mod;
            }
            tmp = tmp * tmp % mod;
            p /= 2;

        }
        return result % mod;
    }


    // int remainder(x, a, p) {
    //     int rem = 1;
    //     while (a > 0) {
    //         if (a % 2) {
    //             rem = (rem * x) % p;
    //             x = x * x % p;
    //             a //= 2
    //         }
    //     }
    //     return rem;
    // }

};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(JianShengZiIiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().jianShengZiIiLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}