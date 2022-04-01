// 2022-03-11 11:51:11
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxLength(vector<int> &n1, vector<int> &n2, int l, int r, int len){
        int res = 0;
        int now = 0;
        for (int i = 0; i < len; ++i) {
            if (n1[l + i] == n2[r + i]){
                now++;
            }
            else{
                now = 0;
            }
            res = max(res, now);
        }
        return res;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int len = min(m, n - i);
            if (sum >= len) break;
            int maxLen = maxLength(nums1, nums2, 0, i, len);
            sum = max(sum, maxLen);
        }
        for (int i = 0; i < m; ++i) {
            int len = min(n, m - i);
            if (sum >= len) break;
            int maxLen = maxLength(nums1, nums2, i, 0, len);
            sum = max(sum, maxLen);
        }
        return sum;
        // int dp[m][n];
        // memset(dp, 0, sizeof(dp));
        // for (int i = 0; i < m; ++i) {
        //     if(nums1[i] == nums2[0]) dp[i][0] = 1;
        //     sum = max(sum, dp[i][0]);
        // }
        // for (int i = 0; i < n; ++i) {
        //     if (nums2[i] == nums1[0]) dp[0][i] = 1;
        //     sum = max(sum, dp[0][i]);
        // }
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         if (nums1[i] == nums2[j]){
        //             dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        //         }
        //         sum = max(sum, dp[i][j]);
        //     }
        // }
        // return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MaximumLengthOfRepeatedSubarray, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().maximumLengthOfRepeatedSubarray(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}