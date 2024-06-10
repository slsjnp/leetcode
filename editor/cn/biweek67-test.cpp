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
    int sum = 0;

    int maximumDetonation(vector<vector<int>> &bombs) {
        int _size = bombs.size();
        queue<vector<int>> qu;
        map<vector<int>, int> ma;
        map<vector<int>, int> flag;
        for (int i = 0; i < _size; ++i) {
            ma[bombs[i]]++;
        }
        int _sum = 0;
        vector<int> now;
        auto it = ma.begin();
        while (it != ma.end()) {
            _sum = 0;
            flag = ma;
            qu.push(it->first);
            _sum += it->second;
            flag[it->first] = 0;
            // flag.erase(it->first);
            it++;
            while (!qu.empty()) {
                now = qu.front();
                qu.pop();
                for (auto itd: flag) {
                    if (flag[itd.first] == 0) continue;
                    long long a = (long long)abs(now[0] - itd.first[0]) * (long long)abs(now[0] - itd.first[0]);
                    long long b = (long long)abs(now[1] - itd.first[1]) * (long long)abs(now[1] - itd.first[1]);
                    long long c = (long long)now[2] * (long long)now[2];
                    // printf("now: %d,itd: %d,flag: %d, a: %d, b: %d, c: %d\n",now[0], itd.first[0], flag.size(),a,b,c);
                    if ((a + b) <= c) {
                        _sum += itd.second;
                        qu.push(itd.first);
                        flag[itd.first] = 0;
                        // flag.erase(itd.first);
                    }
                }
            }
            sum = max(sum, _sum);
        }
        return sum;
    }
};
// class Solution {
// public:
//     int sum = 0;
//     int maximumDetonation(vector<vector<int>> &bombs) {
//         int _size = bombs.size();
//         unordered_map<int, vector<int>> ma;
//         auto is_connect = [&](vector<int> a, vector<int> b) -> bool{
//             long long x = (long long)(a[0] - b[0]) * (a[0] - b[0]);
//             long long y = (long long)(a[1] - b[1]) * (a[1] - b[1]);
//             long long r = (long long)(a[2] * a[2]);
//             return x + y <= r;
//         };
//         for (int i = 0; i < _size; ++i) {
//             for (int j = 0; j < _size; ++j) {
//                 if (i != j and is_connect(bombs[i], bombs[j])){
//                     // if (ma.count(i) == 0){
//                     //     ma[i] = vector<int> {j};
//                     // }
//                     // else ma[i].emplace_back(j);
//                     ma[i].emplace_back(j);
//                 }
//             }
//         }
//
//         for (int i = 0; i < _size; ++i) {
//             queue<vector<int>> qu;
//             vector<int> flag(n, 0);
//             qu.push(i);
//             int _sum = 0;
//             while (!qu.empty()){
//                 for(auto it : ma[qu.front()]){
//                     if (flag[it] == 0){
//                         _sum++;
//                         flag[it] = 1;
//                         qu.push(it);
//                     }
//                 }
//                 qu.pop();
//             }
//             sum = max(sum, _sum);
//         }
//
//
//         return sum;
//     }
// };





// class Solution {
// public:
//     vector<int> goodDaysToRobBank(vector<int> &security, int time) {
//         int _size = security.size();
//         set<int> down;
//         set<int> up;
//         int r = _size - 1;
//         int pre = security[0] - 1;
//         int post = security[r] - 1;
//         int t1 = 0;
//         int t2 = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (pre >= security[i]) {
//                 t1++;
//
//             } else {
//                 t1 = 0;
//             }
//             if (t1 >= time) {
//                 down.insert(i);
//             }
//             pre = security[i];
//             if (post >= security[r]) {
//                 t2++;
//
//             } else {
//                 t2 = 0;
//             }
//             if (t2 >= time) {
//                 up.insert(r);
//             }
//             post = security[r];
//             r--;
//         }
//         vector<int> res;
//         for (auto it: up) {
//             if (down.count(it)) {
//                 res.emplace_back(it);
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//
//         int _size = nums.size();
//         vector<int> tmp = nums;
//         sort(nums.begin(), nums.end());
//         vector<int> t(nums.end() - k, nums.end());
//         vector<int> res;
//         unordered_map<int, int> ma;
//         for (int i = 0; i < t.size(); ++i) {
//             ma[t[i]]++;
//         }
//         for (int i = 0; i < _size; ++i) {
//             if (ma[tmp[i]] != 0){
//                 res.emplace_back(tmp[i]);
//             }
//         }
//         return res;
//     }
// };

//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(biweek67, Example2) {      // NOLINT
        // std::vector<int> nums = { 10,83,53};
        // string s = "**|**|***|";
        vector<vector<int>> t = {{1, 5, 3},
                                 {1, 5, 1},
                                 {6, 6, 5}};
        // int a = 6;
        // vector<int> n = {3, 2};
        auto ans = Robot(6, 3);
        ans.move(2);
        ans.move(2);
        ans.move(2);
        ans.move(1);
        ans.move(4);
        int c = 0;
        decltype(c) rightAns = 8;
        ASSERT_EQ(c, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
