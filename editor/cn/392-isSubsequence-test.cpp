// 2022-03-11 19:20:08
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int _size = t.size();
        // memset(ma, 0, sizeof(ma));
        // for (int i = 0; i < s.size(); ++i) {
        //     ma[s[i] - 'a']--;
        // }
        int l = 0, r = 0;
        while (l < s.size() && r < _size){
            if (t[r] == s[l]){
                l++;
            }
            r++;
        }
        if (l == s.size()){
            return true;
        }
        else return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(IsSubsequence, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().isSubsequence(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}