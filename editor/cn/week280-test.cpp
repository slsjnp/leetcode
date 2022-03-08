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
    vector<vector<int>> res;
    int s_size;
    int sum = 0;
    vector<int> vis;
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // 每个篮子最多有俩个数
        res = vector<vector<int>> (numSlots, vector<int> (2, -1));
        vis = vector<int> (nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= s_size){
                for (auto& it: res[nums[i]]) {
                    if (it == -1) {
                        it = nums[i];
                        vis[i] = 1;
                    }

                }
            }
        }
        this->s_size = numSlots;
        dfs(nums, 0);
        return sum;
    }
    void dfs(vector<int>& nums, int l){
        if (l >= nums.size()){
            int tmp = 0;
            for (int i = 0 ; i < res.size(); i++) {
                for(auto it: res[i]){
                    if (it != -1){
                        tmp += it & (i + 1);
                    }
                }
            }
            // printf("1\n");
            sum = max(sum, tmp);
        }
        for (int i = l; i < nums.size(); ++i) {
            if (vis[i]){
                continue;
            }
            for (int j = min(nums[i], (int)res.size()), t = 8; j > 0; j ^= t, t >>= 1) {
                // if ((nums[i] & (j + 1)) == 0){
                //     continue;
                // }
                for (auto& it: res[j]) {
                    if (it == -1){
                        it = nums[i];
                        dfs(nums, i + 1);
                        it = -1;
                    }
                }
            }
        }
    }
};


// class Solution {
// public:
//     long long minimumRemoval(vector<int> &beans) {
//         // 1. 最大值减值 最小值
//         // 2. 最小值减为0 =》 产生新的最小值
//         // 3. 遇到重复值
//         long long res = 0;
//         sort(beans.begin(), beans.end());
//         int _size = beans.size();
//         long long sum = 0;
//         for (auto it: beans) {
//             sum += it;
//         }
//         // 前一个没减的值
//         long long pre = sum - beans[0] * (_size - 0);
//         long long ans = pre;
//         for (int i = 1; i < _size; ++i) {
//             // 减完后 是否更小
//             // if (pre > res + sum - beans[i - 1] - beans[i] * (_size - (i + 1))){
//             // 上一个豆该减为0
//             sum -= beans[i - 1];
//             res += beans[i - 1];
//             pre = res + sum - beans[i] * (_size - i);
//             ans = min(ans, pre);
//             // }
//             // else {
//             //     return res;
//             // }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int minimumOperations(vector<int>& nums) {
//         unordered_map<int ,int> m1;
//         unordered_map<int ,int> m2;
//         int _size = nums.size();
//         for (int i = 0; i < _size; ++i) {
//             if (i % 2 == 0){
//                 m1[nums[i]]++;
//             }
//             else{
//                 m2[nums[i]]++;
//             }
//         }
//
//         int max_ = 0;
//         int key = 0;
//         for (auto it: m1) {
//             if (it.second > max_){
//                 max_ = it.second;
//                 key = it.first;
//             }
//         }
//         int max1_ = 0;
//         int key1 = 0;
//         for (auto it: m2) {
//             if (it.first != key and it.second > max_){
//                 max1_ = it.second;
//                 key1 = it.first;
//             }
//         }
//         int res = _size - (max_ + max1_);
//
//         max_ = 0;
//         key = 0;
//         for (auto it: m2) {
//             if (it.second > max_){
//                 max_ = it.second;
//                 key = it.first;
//             }
//         }
//         int max1_ = 0;
//         int key1 = 0;
//         for (auto it: m1) {
//             if (it.first != key and it.second > max_){
//                 max1_ = it.second;
//                 key1 = it.first;
//             }
//         }
//         res = max(res, _size - (max_ + max1_));
//         return res;
//
//     }
// };
// class Solution {
// public:
//     int countOperations(int num1, int num2) {
//         int sum = 0;
//         while( num1 == 0 or num2 == 0){
//             sum++;
//             if (num1 > num2){
//                 num1 -= num2l
//             }
//             else{
//                 num2 -= num1;
//             }
//         }
//         return sum;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week280, Example2) {      // NOLINT
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
