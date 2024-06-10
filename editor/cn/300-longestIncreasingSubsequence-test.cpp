// 2022-03-10 20:03:24
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// class Solution {
// public:
//     int lengthOfLIS(vector<int> &nums) {
//         int _size = nums.size();
//         vector<int> dp;
//         dp.emplace_back(nums[0]);
//         for (int i = 1; i < _size; ++i) {
//             auto up = lower_bound(dp.begin(), dp.end(), nums[i]);
//             if (up == dp.end()) {
//                 dp.emplace_back(nums[i]);
//             } else {
//                 *up = nums[i];
//             }
//         }
//         return dp.size();
//     }
// };
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int _size = nums.size();
        if (_size == 1) return 1;
        int dp[_size];
        // memset(dp, 0, sizeof(dp));
        for (int i = 0; i < _size; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < _size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < _size; ++i) {
            res = max(res, dp[i]);
        }
        return res;
        // vector<int> res(_size, -1);
        // // stack<int> st;
        // map<int, int> ma;
        // for (int i = _size - 1; i >= 0; --i) {
        //     auto it = ma.upper_bound(nums[i]);
        //     if (it != ma.end()){
        //         ma[nums[i]] = 1 + it->second;
        //     }
        //     else{
        //         ma[nums[i]] = 1;
        //     }
        //     // while(!st.empty() && nums[i] > nums[st.top()]){
        //     //     st.pop();
        //     // }
        //     // res[i] = !st.empty() ? st.top(): -1;
        //     // st.push(i);
        // }
        // auto it = ma.upper_bound(-1e6);
        // return it->second;
        // vector<int> vis(_size, 0);
        // int sum = 0;
        // for (int i = _size - 1; i >= 0; --i) {
        //     int now = 1;
        //     int l = res[nums[i]];
        //     while (l != -1){
        //         if (vis[l] != 0){
        //             now += vis[l];
        //             break;
        //         }
        //         now++;
        //         l = res[l];
        //     }
        //     sum = max(now, sum);
        //     vis[i] = now;
        // }

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestIncreasingSubsequence, Example1) {      // NOLINT
        std::vector<int> nums = { 10,9,2,5,3,7,101,18 };
        auto ans = Solution().lengthOfLIS(nums);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}