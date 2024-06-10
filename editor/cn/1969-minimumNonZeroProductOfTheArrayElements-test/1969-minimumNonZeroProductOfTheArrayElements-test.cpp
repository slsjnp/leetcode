
// 2024-03-20 00:02:51
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minNonZeroProduct(int p) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumNonZeroProductOfTheArrayElements, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().minimumNonZeroProductOfTheArrayElements(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
