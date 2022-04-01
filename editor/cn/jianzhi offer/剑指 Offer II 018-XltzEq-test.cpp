// 2022-03-10 17:42:15
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
        int _size = s.size();
        int l = 0, r = _size - 1;
        while (l < r){
            while (l < r && !check(s, l)){
                l++;
            }
            while (l < r && !check(s, r)){
                r--;
            }
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool check(string &s, int l){
        if ((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z')){
            s[l] = tolower(s[l]);
            return true;
        }
        if (s[l] >= '0' && s[l] <= '9'){
            return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(XltzEq, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().XltzEq(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}