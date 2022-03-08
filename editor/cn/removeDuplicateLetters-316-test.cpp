// 2022-01-25 00:24:15
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> ma;
        string res;
        vector<char> st;
        int vis[26];
        memset(vis, 0,sizeof(vis));
        int _size = s.size();
        for (int i = 0; i < _size; ++i) {
            ma[s[i]]++;
        }
        int ma_size = ma.size();
        int l = 0;
        while(l < _size){
            if (vis[s[l] - 'a']){
                ma[s[l]]--;
                l++;
                continue;
            }
            while(!st.empty() and ma[st.back()] > 1 and st.back() > s[l]){
                ma[st.back()]--;
                vis[st.back() - 'a'] = 0;
                st.pop_back();
            }

            vis[s[l] - 'a'] = 1;
            st.push_back(s[l]);
            // printf("%d", (int)st.size());
            l++;
        }
        for (int i = 0; i < st.size(); ++i) {
            res.push_back(st[i]);
        }
        return res;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RemoveDuplicateLetters, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().removeDuplicateLetters(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}