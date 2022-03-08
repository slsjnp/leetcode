// 2022-02-15 20:28:59
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestNiceSubstring(string s) {
        int _size = s.size();
        vector<vector<int>> p1(26, vector<int>(_size, 0));
        vector<vector<int>> p2(26, vector<int>(_size, 0));
        for (int i = 0; i < _size; ++i) {
            for (int j = 0; j < 26; ++j) {
                p1[j][i + 1] = p1[j][i];
                p2[j][i + 1] = p2[j][i];
            }
            if (s[i] <= 'z' and s[i] >= 'a') {
                p1[s[i] - 'a'][i + 1] = p1[s[i] - 'a'][i] + 1;
            } else {
                p2[s[i] - 'A'][i + 1] = p2[s[i] - 'A'][i] + 1;
            }
        }
        int sum = 0;
        int start = 0;
        for (int i = 0; i < _size; ++i) {
            for (int j = i + 1; j < _size; ++j) {
                int flag = 1;
                for (int k = 0; k < 26; ++k) {
                    if (p2[k][j + 1] - p2[k][i] and p1[k][j + 1] - p1[k][i]){
                        continue;
                    }
                    flag = 0;
                    break;
                }
                if (flag and j - i + 1 > sum){
                    sum = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, sum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestNiceSubstring, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().longestNiceSubstring(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}