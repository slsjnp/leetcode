// 2022-01-24 23:55:16
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int _size = num.size();
        int l = 0;
        vector<char> st;
        int rm = 0;
        // string res;
        while (l < _size) {
            while (!st.empty() and st.back() > num[l] and rm < k) {
                st.pop_back();
                rm++;
            }
            st.push_back(num[l]);
            l++;
        }
        for (; k > rm; rm++) {
            st.pop_back();
        }
        string ans;
        for (int i = 0; i < k; ++i) {
            if (st[i] == '0' and ans.size() == 0) {
                continue;
            } else {
                ans.push_back(st[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RemoveKDigits, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().removeKDigits(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}