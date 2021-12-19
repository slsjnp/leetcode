// 2021-11-23 16:06:37
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int s_size = s.size();
        int g_size = goal.size();
        if (g_size != s_size) return false;
        int times = 0;
        for (int i = 0; i < s_size; ++i) {
            if (s[i] != goal[i]){
                times++;
            }
        }
        sort(s.begin(), s.end());
        sort(goal.begin(), goal.end());
        if (!times){
            char t = s[0];
            for (int i = 1; i < s_size; ++i) {
                if (s[i] == t){
                    return true;
                }
                else t = s[i];
            }
            return false;
        }
        if (times == 2 && s == goal){
            return true;
        } else{
            return false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BuddyStrings, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().buddyStrings(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}