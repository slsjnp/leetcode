// 2022-01-13 23:28:05
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    vector<string> num2str = {"abc", "def", "ghi", "jlk", "mon", "pqrs", "tuv", "wxyz"};
    string s;
    int _size;

    vector<string> letterCombinations(string digits) {
        s = digits;
        _size = s.size();
        dfs(0, "");
        return res;
    }

    void dfs(int l, string ans) {
        if (_size == l and ans.size() == s.size() and !ans.empty()) {
            res.push_back(ans);
            return;
        }
        // for (int i = l; i < _size; ++i) {
        int idx = s[l] - '0' - 2;
        int n = num2str[idx].size();
        for (int j = 0; j < n; ++j) {
            // if ()
            dfs(l + 1, ans + num2str[idx][j]);
        }
        // }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LetterCombinationsOfAPhoneNumber, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().letterCombinationsOfAPhoneNumber(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}