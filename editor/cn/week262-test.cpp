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
    int minimumDifference(vector<int>& nums) {
        int _size = nums.size();
        int n = _size / 2;
        vector<int> s[16], t[16];
        // 处理前n个数， 共2的n次方种情况
        // 0 代表选， 1代表不选
        int sum = 0;
        int bit = 0;
        for (int i = 0; i < 1<<n; ++i) {
            sum = 0;
            for (int h = 0; h < n; ++h) {
                if (i>>h&1){
                    sum += nums[h];
                    bit++;
                }
                else sum -= nums[h];
            }

            s[bit].push_back(sum);
        }

        for (int i = 0; i < 16; ++i) {
            sort(s[i].begin(), s[i].end());
            // 去重并返回最后的下标；
            s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
        }

        int ans = 1e9 + 7;
        bit = 0;
        for (int i = 0; i < 1 << n; ++i) {
            sum = 0;
            for (int h = 0; h < n; ++h) {
                if (i>>h&1){
                    sum += nums[h];
                    bit++;
                }
                else{
                    sum -= nums[h];
                }
            }

            auto a = lower_bound(s[15-bit].begin(), s[15-bit].end(), sum);
            if (a != s[15-bit].end()){
                ans = min(*a, ans);
            }
        }
        return ans;
    }
};
// class StockPrice {
//     map<int,int> m;
//     set<pair<int,int>> s;
// public:
//     StockPrice() {
//         m.clear();
//         s.clear();
//     }
//
//     void update(int timestamp, int price) {
//         if(m.count(timestamp))s.erase(make_pair(m[timestamp],timestamp));
//         s.insert(make_pair(m[timestamp]=price,timestamp));
//     }
//
//     int current() {
//         return m.rbegin()->second;
//     }
//
//     int maximum() {
//         return s.rbegin()->first;
//     }
//
//     int minimum() {
//         return s.begin()->first;
//     }
// };

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// class StockPrice {
// public:
//     struct cmp_max {
//         bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
//             return x.second < y.second;
//         }
//     };
//     struct cmp_min {
//         bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
//             return x.second > y.second;
//         }
//     };
//
//     // pair<int, int> *_max;
//     // pair<int, int> *_min;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_max> _max;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_min> _min;
//     pair<int, int> _new;
//     unordered_map<int, int> ma;
//
//     StockPrice() {
//         // _max.push(pair<int, int>(-1, -1));
//         // _min.push(pair<int, int>(-1, INT_MAX));
//         // _new = pair<int, int>(-1, -1);
//     }
//
//     void update(int timestamp, int price) {
//         if (ma.count(timestamp) and _max.top().first == timestamp){
//             _max.pop();
//         }
//         if (ma.count(timestamp) and _min.top().first == timestamp){
//             _min.pop();
//         }
//         ma[timestamp] = price;
//         _max.push(pair<int, int>(timestamp, price));
//         _min.push(pair<int, int>(timestamp, price));
//         if (timestamp >= _new.first) _new = pair<int, int>(timestamp, price);
//     }
//
//     int current() {
//         return _new.second;
//     }
//
//     int maximum() {
//         auto m = _max.top();
//         while(ma[m.first] != m.second){
//             _max.pop();
//             m = _max.top();
//         }
//         return m.second;
//     }
//
//     int minimum() {
//         auto m = _min.top();
//         while(ma[m.first] != m.second){
//             _min.pop();
//             m = _min.top();
//         }
//         return m.second;
//     }
// };



/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// class Solution {
// public:
//     int minOperations(vector<vector<int>>& grid, int x) {
//         int g_size = grid.size();
//         int i_size = grid[0].size();
//         vector<int> res;
//         for (auto it: grid) {
//             for (auto id: it) {
//                 res.emplace_back(id);
//             }
//         }
//         sort(id.begin(), id.end());
//         int mid = (res.size() - 1) / 2;
//         int resu = 0;
//
//         for (auto it: res) {
//             if ((res[mid] - it) % x != 0){
//                 return -1;
//             }
//             else{
//                 resu += abs(res[mid] - it) / x;
//             }
//         }
//         return resu;
//     }
// };
// class Solution {
// public:
//     vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//         unordered_set<int> se;
//         unordered_set<int> se2;
//         unordered_set<int> se3;
//
//         int _size1 = nums1.size();
//         int _size2 = nums2.size();
//         int _size3 = nums3.size();
//         for (auto it: nums1) {
//             if (se.count(it) == 0){
//                 se.insert(it);
//             }
//         }
//         for (auto it: nums2) {
//             if (se2.count(it) == 0){
//                 se2.insert(it);
//             }
//         }
//         for (auto it: nums3) {
//             if (se3.count(it) == 0){
//                 se3.insert(it);
//             }
//         }
//         unordered_set<int> res;
//         for (auto it: se) {
//             if (se2.count(it) || se3.count(it)){
//                 if (res.count(it) == 0) res.insert(it);
//             }
//         }
//         for (auto it: se2) {
//             if (se.count(it) || se3.count(it)){
//                 if (res.count(it) == 0) res.insert(it);
//             }
//         }
//         vector<int> resu;
//         for (auto it: res) {
//             resu.emplace_back(it);
//         }
//         return resu;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Week262, Example2) {      // NOLINT
        int a = 7, b = 17;
        auto ans = Solution().kMirror(a, b);
        decltype(ans) rightAns = 20379000;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
