// 2022-03-10 09:54:02
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        int _size = s.size();
        unordered_map<char, int> ma, mb;
        for (auto it: t) {
            mb[it]++;
        }
        int l = 0, r = 0;
        int res = 0;
        int target = mb.size();
        int sum = _size + 1;
        string ans = "";
        while (r < _size) {
            char c = s[r];
            ma[c]++;
            if (mb.count(c) && ma[c] == mb[c]) {
                res++;
            }
            r++;

            c = s[l];
            while (l < r && mb.count(c) == 0 || (mb.count(c) && ma[c] > mb[c])) {
                ma[c]--;
                l++;
                c = s[l];
            }
            if (res == target) {
                if (sum > r - l) {
                    sum = r - l;
                    ans = s.substr(l, r - l);
                }
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumWindowSubstring, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().minimumWindowSubstring(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}