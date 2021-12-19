// 2021-11-18 11:33:58
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int a, int b) {
        if (b == 1){
            return a;
        }
        if (b == -1){
            if (a == INT_MIN){
                return INT_MAX;
            }
        }
        uint32_t pa, pb;
        pa = abs(a);
        pb = abs(b);
        // 找到商的每一位
        int times = 0;
        int tmp;
        while (pa >= pb){
            tmp = 1;
            uint64_t ta = pa, tb = pb;
            while (ta >= (tb << 1)){
                tb <<= 1;
                tmp <<= 1;
            }
            pa -= tb;
            times += tmp;
        }
        return (a > 0) ^ (b > 0) ? -times : times;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Xoh6Oh, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().xoh6Oh(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}