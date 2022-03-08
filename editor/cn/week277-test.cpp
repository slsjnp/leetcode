//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dp;
    int max_;
    int n;

    int maximumGood(vector<vector<int>> &statements) {
        // int m = statements.size();
        n = statements.size();
        dp = vector<int>(n, 1);
        // int dp[n];
        // memset(dp, 1, sizeof(dp));
        dfs(statements, 0);
        return max_;

    }

    void dfs(vector<vector<int>> &st, int l) {
        if (l == n) {
            int sum = 0;

            int flag = 1;
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < n; ++i) {
                    if (!dp[i] and st[l][i] == 1 or dp[i] and st[l][i] == 0) {
                        flag = 0;
                        dp[l] = 0;
                        // break;
                        return;
                    }
                    sum++;
                }
            }
            max_ = max(sum, max_);
            return;
        }
        // if (dp[l] == 0){
        //     dfs(st, l + 1);
        //     return;
        // }
        dp[l] = 0;
        dfs(st, l + 1);
        dp[l] = 1;
        dfs(st, l + 1);


        // if (flag) {
        //     for (int i = 0; i < n; ++i) {
        //         if (st[l][i] == 0) {
        //             dp[i] = 0;
        //         }
        //     }
        //     dfs(st, l + 1);
        // }
    }
};
// class Solution {
// public:
//     vector<int> findLonely(vector<int>& nums) {
//         int _size = nums.size();
//         unordered_map<int, int> ma;
//         vector<int> res;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < _size; ++i) {
//             ma[nums[i]]++;
//             int flag = 1;
//             if (i > 0 and (nums[i] - 1 == nums[i - 1] or nums[i] + 1 == nums[i - 1] or nums[i] == nums[i - 1])){
//                 flag = 0;
//             }
//             if (i + 1 < _size and (nums[i] + 1 == nums[i + 1] or nums[i] - 1 == nums[i + 1] or nums[i] == nums[i + 1])){
//                 flag = 0;
//             }
//             if (flag){
//                 res.emplace_back(nums[i]);
//             }
//         }
//         // vector<int> ans;
//         // for (int i = 0; i < res.size(); ++i) {
//         //     if (ma[res[i]] == 1){
//         //         ans.emplace_back(res[i]);
//         //     }
//         // }
//         return res;
//     }
// };

// class Solution {
// public:
//     int countElements(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int sum = 0;
//         if (nums.size() == 1){
//             return 0;
//         }
//
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[0] != nums[i] and nums[nums.size() - 1] != nums[i]) sum++;
//         }
//         // if (nums[0] != nums[1]) sum++;
//         // if (nums[nums.size() - 1] != nums[nums.size() - 2]) sum++;
//         return sum;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week276, Example2) {      // NOLINT
        std::vector<int> nums = {98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821,
                                 98818, 98821, 98818};
        auto ans = Solution().getDistances(nums);
        decltype(ans) rightAns = {0, 1};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
