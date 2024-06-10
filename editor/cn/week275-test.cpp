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
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int _size = plantTime.size();
        vector<int> res(_size);
        iota(res.begin(), res.end(), 0);
        sort(res.begin(), res.end(), [&growTime](int a, int b){return growTime[a] > growTime[b];});
        int begin = 0;
        int end = 0;
        for (int i = 0; i < _size; ++i) {
            begin += plantTime[res[i]];
            end = max(end, begin + growTime[res[i]]);
        }
        return end;
    }
};
// class Solution {
// public:
//     int wordCount(vector<string> &startWords, vector<string> &targetWords) {
//         int _size = startWords.size();
//         int t_size = targetWords.size();
//         unordered_map<int, unordered_set<int>> ma;
//         int ans = 0;
//         for (auto it: startWords) {
//             int n = it.size();
//             int t = 0;
//             for (int i = 0; i < n; ++i) {
//                 t |= 1 << (it[i] - 'a');
//             }
//             ma[n].insert(t);
//         }
//         for (auto it: targetWords) {
//             int n = it.size();
//             for (int i = 0; i < n; ++i) {
//                 int t = 0;
//                 for (int j = 0; j < n; ++j) {
//                     if (i != j) {
//                         t |= 1 << (it[j] - 'a');
//                     }
//                 }
//                 if (ma.count(n - 1)) {
//                     if (ma[n - 1].count(t)) {
//                         ans++;
//                         break;
//                     }
//                 }
//
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int _size = nums.size();
//         int sum = 0;
//         vector<int> pre(_size + 1 , 0);
//         for (int i = 0; i < _size; ++i) {
//             pre[i + 1] = pre[i] + nums[i];
//         }
//         sum = pre[_size];
//         int _max = 0;
//         for (int i = sum; i < _size; ++i) {
//             _max = max(_max, pre[i] - pre[i - sum]);
//         }
//         for (int i = 0; i < sum; ++i) {
//             _max = max(_max, pre[i] + pre[_size] - pre[_size - sum + i]);
//         }
//         return sum - _max;
//     }
// };
// class Solution {
// public:
//     bool checkValid(vector<vector<int>>& matrix) {
//         int _size = matrix.size();
//         for (int i = 0; i <_size ; ++i) {
//             unordered_set<int> se;
//             unordered_set<int> row;
//             for (int j = 0; j < _size; ++j) {
//                 if (se.count(matrix[i][j])){
//                     return false;
//                 }
//                 else if(matrix[i][j] <= _size){
//                     se.insert(matrix[i][j]);
//                 }
//                 if (row.count(matrix[j][i])){
//                     return false;
//                 }
//                 else if(matrix[j][i] <= _size){
//                     row.insert(matrix[j][i]);
//                 }
//             }
//             if (se.size() < _size and row.size() < _size) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week275, Example2) {      // NOLINT
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
