// 2022-03-10 18:35:17
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        int _size = s.size();
        int res = 0;
        for (int i = 0; i < 2 * _size - 1; ++i) {
            int l = i / 2;
            int r = i / 2 + i % 2;
            while (l >= 0 && r < _size && s[l] == s[r]){
                --l;
                ++r;
                ++res;
            }
        }
        // bool dp[_size][_size];
        // memset(dp, 0, sizeof(dp));
        // for (int i = _size - 1; i >= 0; --i) {
        //     dp[i][i] = true;
        //     for (int j = i; j < _size; ++j) {
        //         dp[i][j] = (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]));
        //         if (dp[i][j]) res++;
        //     }
        // }
        return res;
    }
    // int countSubstrings(string s) {
    //     int _size = s.size();
    //     bool dp[_size][_size];
    //     int res = 0;
    //     memset(dp, 0, sizeof(dp));
    //     for (int i = _size - 1; i >= 0; --i) {
    //         dp[i][i] = true;
    //         for (int j = i; j < _size; ++j) {
    //             dp[i][j] = (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]));
    //             if (dp[i][j]) res++;
    //         }
    //     }
    //     return res;
    // }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(A7VOhD, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().a7VOhD(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}