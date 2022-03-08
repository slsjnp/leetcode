// 2022-03-05 18:36:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    unordered_set<string> se;
    // string tmp;
    int _size;
    vector<string> generateParenthesis(int n) {
        this->_size = n;
        dfs("()",1);
        return res;
    }
    void dfs(string s, int l){
        if (l == _size){
            // if (se.count(s) == 0){
                se.insert(s);
                res.push_back(s);
            // }
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            string tmp = s.substr(0, i) + "()" + s.substr(i, s.size() - i);
            if (se.count(tmp) == 0){
                se.insert(tmp);
                dfs(s.substr(0, i) + "()" + s.substr(i, s.size() - i), l + 1);
            }

        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(IDBivT, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().IDBivT(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}