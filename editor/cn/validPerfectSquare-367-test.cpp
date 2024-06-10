// 2021-11-04 13:12:24
#include <gtest/gtest.h>
#include "header.h"


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {

        int t = bin_find(num);
        if(num == (uint32_t)t * t){
            return true;
        }
        else return false;

    }
    int bin_find(uint32_t num, int l = 1, int r = (1 << 16) - 1){
        if (l == r){
            return l;
        }
        int mid = (l + r) / 2;
        if ((uint32_t)mid * mid < num){
            return bin_find(num, mid + 1, r);
        }
        else {
            return bin_find(num, l, mid);
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ValidPerfectSquare, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        int nums = 1 << 15 + (1 << 5) + (3 << 4);
        auto ans = Solution().isPerfectSquare(nums);
        decltype(ans) rightAns = true;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    // int nums = 5;
    // auto ans = Solution().isPerfectSquare(nums);
    // return 0;
}