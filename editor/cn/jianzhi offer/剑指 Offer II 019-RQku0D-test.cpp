// 2022-03-10 17:53:08
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validPalindrome(string s) {
        int _size = s.size();
        int l = 0, r = _size - 1;
        int flag = 1;
        bool res1, res2;
        while (l < r) {
            if (s[l] != s[r]) {
                if (l + 1 <= r && s[l + 1] == s[r]) {
                    res1 = isPalindrome(s.substr(l + 2, r - l - 2));
                }
                if (l <= r - 1 && s[l] == s[r + 1]) {
                    res2 = isPalindrome(s.substr(l + 1, r - l - 2));
                }
                return res1 || res2;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        int _size = s.size();
        int l = 0, r = _size - 1;
        while (l < r) {
            // while (l < r && !check(s, l)){
            //     l++;
            // }
            // while (l < r && !check(s, r)){
            //     r--;
            // }
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RQku0D, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().RQku0D(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}