// 2022-06-06 00:01:25
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmp;
    string s;
    string tmp_s;
    vector<vector<string>> partition(string s) {
        int _size = s.size();
        this->s = s;
        dfs(0, "");
        return res;
    }

    void dfs(int l, string ss){
        if (l == s.size()){
            // printf("%s\n", ss.c_str());
            if (check()){
                res.push_back(tmp);
            }
            return;
        }
        string now_s = ss;
        for (int i = l; i < s.size(); ++i) {
            now_s += s[i];
            if (ispal(now_s)){
                tmp.push_back(now_s);
                dfs(i+1, "");
                tmp.pop_back();
            }
        }
    }

    bool check(){
        for (auto it: tmp) {
            if (!ispal(it)){
                return false;
            }
        }
        return true;
    }

    bool ispal(string ss){
        int _size = ss.size();
        if (_size == 0) return false;
        for (int i = 0; i < ss.size() / 2; ++i) {
            if (ss[i] != ss[_size - i - 1]){
                return false;
            }
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(PalindromePartitioning, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().partition("aab");
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}