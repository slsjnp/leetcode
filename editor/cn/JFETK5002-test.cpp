// 2021-11-18 11:33:52
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string::iterator it;
    string res;
    string addBinary(string a, string b) {
        string res = "";
        int a_size = a.size();
        int b_size = b.size();
        int i = 0, j = 0;
        int flag = 0;
        int tmp = 0;
        int it, jt;
        while (i < a_size || j < b_size || flag) {
            it = a_size - 1 - i >= 0 ? a[a_size - 1 - i] - '0': 0;
            jt = b_size - 1 - j >= 0 ? b[b_size - 1 - j] - '0': 0;
            tmp = it + jt + flag;
            if (tmp > 1){
                flag = 1;
            }
            else {
                flag = 0;
            }
            res.push_back((tmp & 1) + '0');
            i++;
            j++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(JFETK5, Example1) {      // NOLINT
        // std::vector<int> nums = {};
        string a = "10011";
        string b = "11111111111";
        auto ans = Solution().addBinary(a, b);
        decltype(ans) rightAns = "10000001111";
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}