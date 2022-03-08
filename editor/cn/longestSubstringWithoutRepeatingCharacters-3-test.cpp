// 2022-01-22 20:26:49
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestSubstringWithoutRepeatingCharacters, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().longestSubstringWithoutRepeatingCharacters(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}