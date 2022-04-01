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
    vector<int> maximumBobPoints(int numArrows, vector<int> &a) {
        int _size = a.size();
        int now = numArrows;
        // vector<int> dp(_size + 1, 0);
        int dp[_size][now + 1];
        int dis[_size];
        memset(dp, 0, sizeof(dp));
        memset(dis, 0, sizeof(dis));
        vector<int> pre;

        for (int i = 1; i < _size; ++i) {
            for (int j = now; j >= 0; --j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                if(j - a[i] - 1 >= 0) dp[i][j - a[i] - 1] = max(dp[i - 1][j] + i, dp[i][j - a[i] - 1]);
            }
        }
        int sum = 0;
        int idx = 0;
        for (int i = 0; i <= now; ++i) {
            if (dp[_size - 1][i] > sum) {
                sum = dp[_size - 1][i];
                idx = i;
            }
        }
        int res = sum;
        int l = _size - 1;
        while(l > 0){
            int flag = 0;
            for (int i = now; i >= 0; --i) {
                if (now > a[l] && res == l + dp[l - 1][i]){
                    pre.push_back(a[l] + 1);
                    res = dp[l - 1][i];
                    now -= a[l] + 1;
                    flag = 1;
                    break;
                }
            }
            // if (a[l] > now){
            //     l--;
            //     pre.push_back(0);
            //     continue;
            // }
            if (flag == 0){
                pre.push_back(0);
            }
            l--;
        }
        for (int i = pre.size(); i < _size; ++i) {
            pre.push_back(0);
        }
        reverse(pre.begin(), pre.end());
        return pre;
    }
};
// class Solution {
// public:
//     int countCollisions(string nums) {
//         int _size = nums.size();
//         int l = 0;
//         while(nums[l] == 'L'){
//             l++;
//         }
//         int flag = -1;
//         int tim = 0;
//         if (l < _size){
//             if (nums[l] == 'R'){
//                 flag = 1;
//                 tim++;
//             }
//             else{
//                 flag = 0;
//             }
//         }
//         l++;
//         int sum = 0;
//         for (int i = l; i < _size; ++i) {
//             if (nums[i] == 'L'){
//                 if (flag == 1){
//                     sum += tim + 1;
//                 }
//                 else if(flag == 0){
//                     sum += 1;
//                 }
//                 flag = 0;
//                 tim = 0;
//             }
//             else if (nums[i] == 'R'){
//                 flag = 1;
//                 tim++;
//             }
//             else if (nums[i] == 'S'){
//                 if (flag == 1){
//                     sum += tim;
//                 }
//                 flag = 0;
//                 tim = 0;
//             }
//         }
//         return sum;
//     }
// };
// class Solution {
// public:
//     int countHillValley(vector<int> &nums) {
//         int _size = nums.size();
//         int pre = nums[0];
//         int sum = 0;
//         int tim = 1;
//         for (int i = 1; i < _size - 1; ++i) {
//             if (nums[i] == nums[i + 1]) {
//                 // tim++;
//                 continue;
//             }
//             if (nums[i] > pre && nums[i + 1] < nums[i]) {
//                 sum += tim;
//                 tim = 1;
//                 pre = nums[i];
//             } else if (nums[i] < pre && nums[i] < nums[i + 1]) {
//                 sum += tim;
//                 tim = 1;
//                 pre = nums[i];
//             }
//             else{
//                 tim = 1;
//                 pre = nums[i];
//             }
//         }
//         return sum;
//     }
// };


//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week285, Example2) {      // NOLINT
        std::vector<int> nums = {0,0,0,0,0,2,0,5,1,1,0,0};

        // vector<vector<int>> nums = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
        // vector<vector<int>> nums = {{0, 1, 1},
        //                             {2, 1, 1}};
        auto ans = Solution().maximumBobPoints(9, nums);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
