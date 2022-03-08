// 2022-01-15 13:45:24
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isUgly(int n) {
        while (n != 1){
            int t = n;
            if (n % 2 == 0) n /= 2;
            if (n % 3 == 0) n /= 3;
            if (n % 5 == 0) n /= 5;
            if  (t == n){
                return false;
            }
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(UglyNumber, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().uglyNumber(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}