//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"
#include<cstdio>
#include<cstdlib>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> res;

    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        struct cmp {
            bool operator()(const vector<int> &a, const vector<int> &b) const {
                return a[2] < b[2];
            }
        };
        unordered_set<int> se;
        sort(meetings.begin(), meetings.end(), cmp());
        int flag = 0;
        res = vector<int>(n, -1);
        res[firstPerson] = 0;
        int i = 0;
        for (auto it: meetings) {
            if (flag or it[0] == 0 or it[1] == 0 or res[it[0]] != -1 or res[it[1]] != -1) {
                flag = 1;
                if (se.count(it[0]) == 0) {
                    se.insert(it[0]);
                }
                if (se.count(it[1]) == 0) {
                    se.insert(it[0]);
                }
            } else {
                continue;
            }
            // res[it[0]] = 0;
            // res[it[1]] = 0;
            // if (se.count(it[0]));
            if (it[0] > it[1]) {
                swap(it[0], it[1]);
            }
            i = it[1];
            if (res[i] == -1) {
                res[i] = it[0];
            } else {
                if (((find_root(i) != -1) and res[it[0]] == -1) or find_root(i) < res[it[0]]) {
                    res[it[0]] = find_root(i);
                } else {
                    res[i] = res[it[0]];
                }
            }
            flag = 0;
        }
        vector<int> ans;
        flag = 0;
        ans.emplace_back(0);
        for (i = 1; i < n; ++i) {
            // int a = find_root(i);
            if (find_root(i) == flag) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }

    int find_root(int i) {
        if (res[i] == i or res[i] == -1) {
            res[i] = -1;
            return i;
        }
        // while (res[i] != -1){
        int t = find_root(res[i]);
        res[i] = t;
        // }
        return t;
    }
};
// class Solution {
// public:
//     int minimumDeletions(vector<int>& nums) {
//         if (nums.size() == 1){
//             return 1;
//         }
//         int res = 0;
//         int n = nums.size();
//         int _max = nums[0];
//         int ima = 0;
//         int _min = nums[0];
//         int imi = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] > _max){
//                 _max = nums[i];
//                 ima = i;
//             }
//             if (nums[i] < _min){
//                 _min = nums[i];
//                 imi = i;
//             }
//         }
//         int flag = -1;
//         int a = nums.size();
//         if (abs(a / 2.0 - ima) - abs(a / 2.0 - imi) < 0){
//             if (imi > a / 2.0){
//                 res += n - imi;
//                 flag = 1;
//             }
//             else{
//                 res += imi + 1;
//                 flag = 0;
//             }
//             // n = n - imi;
//             int t;
//             if (flag) t = n - (n - imi);
//             else t = n - imi - 1;
//             if ((t - 0.1) / 2.0 < ima){
//                 res += n - ima;
//                 if (flag){
//                     res -= n - imi;
//                 }
//             }
//             else{
//                 res += ima + 1;
//                 if (flag == 0){
//                     res -= imi + 1;
//                 }
//             }
//         }
//         else{
//             if (ima > a / 2.0){
//                 res += n - ima;
//                 flag = 1;
//             }
//             else{
//                 res += ima + 1;
//                 flag = 0;
//             }
//             int t;
//             if (flag) t = n - (n - ima);
//             else t = n - ima - 1;
//
//             if ((t - 0.1) / 2.0 < imi){
//                 res += n - imi;
//                 if (flag){
//                     res -= n - ima;
//                 }
//             }
//             else{
//                 res += imi + 1;
//                 if (flag == 0){
//                     res -= ima + 1;
//                 }
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<int> getAverages(vector<int>& nums, int k) {
//         if (k == 0) return nums;
//         if (nums.size() < 2 * k + 1) return vector<int> (nums.size(), -1);
//         vector<int> res;
//         long long sum = 0;
//         for (int i = 0; i < k; ++i) {
//             res.emplace_back(-1);
//             sum += nums[i];
//         }
//         for (int i = k; i < 2 * k; ++i) {
//             sum += nums[i];
//         }
//         int i = k;
//         for (; i < nums.size() - k; ++i) {
//             sum += nums[i + k];
//             res.emplace_back(sum / (2 * k + 1));
//             sum -= nums[i - k];
//         }
//         for (; i < nums.size(); ++i) {
//             res.emplace_back(-1);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         int flag = 0;
//         int sum = 0;
//         vector<int> res;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (target > nums[i]){
//                 sum++;
//             }
//             if (nums[i] == target){
//                 flag++;
//             }
//         }
//         if (flag){
//             for (int i = 0; i < flag; ++i) {
//                 res.push_back(sum);
//                 sum++;
//             }
//             return res;
//         }
//         else{
//             return res;
//         }
//     }
// };

// class Solution {
// public:
//     int countWords(vector<string>& words1, vector<string>& words2) {
//         unordered_map<string, int> se;
//         unordered_map<string, int> se2;
//         vector<string> res;
//         for (auto it: words1) {
//             se[it]++;
//         }
//         for (auto it: words2) {
//             se2[it]++;
//         }
//         for (auto it: words1) {
//             if (se[it] == 1 && se2[it] == 1){
//                 res.emplace_back(it);
//             }
//         }
//         return res;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Week269, Example2) {      // NOLINT
        // int a = 7, b = 17;
        // vector<int> a = {2,10,7,5,4,1,8,6};
        // int b = 3;
        ifstream ifs("../build-in/input.txt", ios::in);
        string s;
        int a = 12;
        vector<vector<int>> b = {{10, 8,  6},
                                 {9,  5,  11},
                                 {0,  5,  18},
                                 {4,  5,  13},
                                 {11, 6,  17},
                                 {0,  11, 10},
                                 {10, 11, 7},
                                 {5,  8,  3},
                                 {7,  6,  16},
                                 {3,  6,  10},
                                 {3,  11, 1},
                                 {8,  3,  2},
                                 {5,  0,  7},
                                 {3,  8,  20},
                                 {11, 0,  20},
                                 {8,  3,  4},
                                 {1,  9,  4},
                                 {10, 7,  11},
                                 {8,  10, 18}};
        std::tuple<int, vector<int>, vector<vector<int>>> tu;
        // for (auto &it: tu) {
        if (getline(ifs, s)) {
            a = stoi(s);
        }
        if (getline(ifs, s)) {
            // replace(s.begin(), s.end(), '[', '{');
            // replace(s.begin(), s.end(), ']', '}');

            // b = stoi(s);
        }
        // }
        auto ans = Solution().findAllPeople(a, b, 9);
        decltype(ans) rightAns = {0};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
