
// 2024-03-20 00:03:40
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestCommonPrefix, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().longestCommonPrefix(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
