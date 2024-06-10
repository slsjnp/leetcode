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
    vector<int> recoverArray(vector<int>& nums) {
        int _size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < _size; ++i) {
            if (nums[0] == nums[i] || nums[i] == nums[i - 1] || (nums[i] - nums[0]) % 2 != 0){
                continue;
            }
            vector<int> vis(_size);
            vector<int> ans;
            int k = (nums[i] - nums[0]) / 2;
            int left = 0;
            int right = i;
            ans.emplace_back(nums[0] + k);
            vis[0] = 1;
            vis[i] = 1;
            for (int j = 1; j < _size / 2; ++j) {
                while(vis[left]){
                    ++left;
                }
                // while (vis[right]){
                //     ++right;
                // }
                while (right < _size and (vis[right] || nums[right] - nums[left] < 2 * k)){
                    ++right;
                }
                if (right == _size || nums[right] - nums[left] > 2 * k) break;
                // if (nums[right] - nums[left] == 2 * k){
                ans.emplace_back(nums[left] + k);
                vis[right] = 1;
                left++;
                // }
            }
            if (ans.size() == _size / 2){
                return ans;
            }
        }
        return {};

    }
};
// class Solution {
// public:
//     vector<long long> getDistances(vector<int>& arr) {
//         int _size = arr.size();
//         vector<long long> res(_size, 0);
//         unordered_map<int, vector<int>> ma;
//         for (int i = 0; i < _size; ++i) {
//             ma[arr[i]].emplace_back(i);
//         }
//         for (auto it : ma) {
//             auto ve = it.second;
//             vector<long long> pre(ve.size(), 0);
//             vector<long long> back(ve.size(), 0);
//             int r = ve.size() - 2;
//             for (int i = 1; i < ve.size(); ++i) {
//                 pre[i] = (long long)pre[i - 1] + (ve[i] - ve[i - 1]) * i;
//                 back[r] = (long long)back[r + 1] + (ve[r + 1] - ve[r]) * i;
//                 r--;
//             }
//
//             for (int i = 0; i < ve.size(); ++i) {
//                 res[ve[i]] = pre[i] + back[i];
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
//         int _size = s.size();
//         int start = 0;
//         vector<int> res;
//         for (int i = 0; i < _size; ++i) {
//             int x = startPos[1];
//             int y = startPos[0];
//             int l = start;
//             int sum = 0;
//             start++;
//             for (int j = l; j < _size; ++j) {
//                 if (s[j] == 'R'){
//                     x++;
//                 }
//                 if (s[j] == 'L'){
//                     x--;
//                 }
//                 if (s[j] == 'U'){
//                     y--;
//                 }
//                 if (s[j] == 'D'){
//                     y++;
//                 }
//                 printf("x: %d, y : %d\n",x, y);
//                 if (x < n and x >= 0 and y < n and y >= 0){
//                     sum++;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             res.push_back(sum);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     bool isSameAfterReversals(int num) {
//         if (num == 0) return true;
//         if (num % 10 == 0){
//             return false;
//         }
//         else return true;
//     }
// };

//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week273, Example2) {      // NOLINT
        std::vector<int> nums = { 98816,98816,98818,98815,98819,98816,98819,98816,98824,98824,98819,98821,98818,98821,98818 };
        auto ans = Solution().getDistances(nums);
        decltype(ans) rightAns = {0 ,1};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
