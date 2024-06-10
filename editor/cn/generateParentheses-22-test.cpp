// 2022-01-14 00:14:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    int _size;
    unordered_set<string> se;

    vector<string> generateParenthesis(int n) {
        _size = n;
        dfs(0, "");
        return res;
    }

    void dfs(int l, string ans) {
        if (l == _size and ans.size() == 2 * _size) {
            res.push_back(ans);
            return;
        }
        int n = ans.size();
        for (int i = 0; i < n; ++i) {
            string s = string(ans.begin(), ans.begin() + l) + "()" + string(ans.begin() + l, ans.end());
            if (se.count(s)){
                continue;
            }
            else{
                se.insert(s);
                dfs(l + 1, s);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(GenerateParentheses, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().generateParentheses(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}