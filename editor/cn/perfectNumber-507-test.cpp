// 2021-12-31 13:25:45
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0){
                sum += (i + num / i);
            }
        }
        if (num == 1) return false;
        // printf("%d", sum);
        return sum + 1 == num;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(PerfectNumber, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().perfectNumber(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}