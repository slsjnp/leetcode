// 2022-01-22 16:39:49
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int _size = wordList.size();
        unordered_map<char, string> ma;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(WordLadder, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().wordLadder(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}