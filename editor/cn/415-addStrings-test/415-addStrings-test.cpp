// 2022-08-18 10:10:32
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        int _size_n1 = num1.size();
        int _size_n2 = num2.size();
        int i1 = _size_n1 - 1;
        int i2 = _size_n2 - 1;
        string res;
        int flag = 0;
        int j = 0;
        for (int i = 0; i < _size_n1 && i < _size_n2; ++i) {
            if (num1[i1 - i] - '0' + num2[i2 - i] - '0' + flag > 9) {
                res += (num1[i1 - i] - '0' + num2[i2 - i] - '0' + flag) % 10 + '0';
                flag = 1;
            } else {
                res += num1[i1 - i] - '0' + num2[i2 - i] - '0' + flag + '0';
                flag = 0;
            }
            j = i;
        }
        printf("%d ", j);

        for (int i = i1 - j - 1; i >= 0; --i) {
            if (flag + num1[i] - '0' > 9) {
                res += (flag + num1[i] - '0') % 10 + '0';
                flag = 1;
            } else {
                res += flag + num1[i];
                flag = 0;
            }
            printf("%d ", j);

        }
        for (int i = i2 - j - 1; i >= 0; --i) {
            if (flag + num2[i] - '0' > 9) {
                res += (flag + num2[i] - '0') % 10 + '0';
                flag = 1;
            } else {
                res += flag + num2[i];
                flag = 0;
            }
            printf("%d ", j);
        }

        if (flag){
            res += '1';
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    string str_to_binaryStr(string s){

    }

};


//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(AddStrings, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().addStrings(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}