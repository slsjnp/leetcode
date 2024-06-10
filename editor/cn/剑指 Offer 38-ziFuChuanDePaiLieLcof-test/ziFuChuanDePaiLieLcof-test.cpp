// 2022-08-29 18:39:17
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    string tmp;
    string s;
    int _size;
    unordered_set<string> se;
    vector<int> vis;
    vector<string> permutation(string s) {
        this->s = s;
        _size = s.size();
        vis.resize(_size);
        dfs("");
        return res;
    }
    void dfs(string ss){
        if (ss.size() == _size){
            if (se.count(ss) == 0){
                se.insert(ss);
                res.push_back(ss);
            }
            return ;
        }

        for (int i = 0; i < _size; ++i) {
            if (vis[i] == 0){
                vis[i] = 1;
                dfs(ss + s[i]);
                vis[i] = 0;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZiFuChuanDePaiLieLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().ziFuChuanDePaiLieLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}