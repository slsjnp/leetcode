// 2022-01-07 13:07:13
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        long long mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if (mid * mid == x){
                return mid;
            }
            if (mid * mid < x){
                low = mid + 1;
            }
            else if(mid * mid > x){
                high = mid - 1;
            }
        }
        return low - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Sqrtx, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().sqrtx(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}