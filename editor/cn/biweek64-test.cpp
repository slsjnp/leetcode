//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         vector<pair<int, int>> ve;
//         vector<int> res;
//         int sum = 0;
//         int flag = 1;
//         for (int i = 0; i < s.length(); ++i) {
//             if (s[i] == '*'){
//                 sum++;
//             }
//             else {
//                 ve.
//                 ve.push_back(pair<int, int>(i, sum));
//                 sum = 0;
//             }
//         }
//         for (auto i : queries) {
//             int l , r = 0;
//             flag = 1;
//             sum = 0;
//             for (int j = 0; j < ve.size(); ++j) {
//                 if (flag && ve[j].first >= i[0]){
//                     l = j;
//                     flag = 0;
//                 }
//                 if (ve[j].first <= i[1]){
//                     r = j;
//                     // break;
//                 }
//             }
//             if (!flag && r > l){
//                 for (int k = l + 1; k <= r; ++k) {
//                     sum += ve[k].second;
//                 }
//             }
//             res.push_back(sum);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     string kthDistinct(vector<string>& arr, int k) {
//         int _size = arr.size();
//         unordered_map<string, int> ma;
//         for (auto i: arr) {
//             if (ma.count(i)){
//                 ma[i]++;
//             }
//             else{
//                 ma[i] = 1;
//             }
//         }
//         int flag = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (ma[arr[i]] == 1){
//                 flag++;
//             }
//             if (flag == k){
//                 return arr[i];
//             }
//         }
//         return string("");
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> events;
//     int _size;
//     int maxTwoEvents(vector<vector<int>>& events) {
//         _size = events.size();
//         int n = 3;
//         this->events = events;
//         sort(events.begin(), events.end(), cmp);
//         int sum = 0;
//         // unordered_set<int> se;
//         for (int i = 0; i < _size; ++i) {
//             // canjia 1
//             // if (se.count(i)){
//             //     break;
//             // }
//             int a = find(events[i][2], i, _size);
//             for (int j = a + 1; j < _size; ++j) {
//                 // canjia 2
//                 // 0 begin
//                 // 1 end
//                 // 2 value
//                 // 判断不重叠
//                 // if (se.count(j)){
//                 //     break;
//                 // }
//                 if (events[i][0] < events[j][0]){
//                     if (events[i][1] < events[j][0]){
//                         sum = max(sum, events[i][2] + events[j][2]);
//                         // se.insert(j);
//                         break;
//                     }
//                 }
//                 else if (events[j][1] < events[i][0]){
//                     sum = max(sum, events[i][2] + events[j][2]);
//                     // se.insert(j);
//                     break;
//                 }
//             }
//         }
//         for (int i = 0; i < _size; ++i) {
//             sum = max(sum, events[i][2]);
//         }
//         return sum;
//     }
//     static bool cmp(vector<int> a, vector<int> b){
//         if (a[0] == b[0]){
//             return a[2] > b[2];
//         }
//         return a[0] < b[0];
//     }
//     int find(int value, int r, int l){
//         int mid = (l + r) / 2;
//         if (l == r){
//             return l;
//         }
//         int ind;
//         if (events[mid][0] > value){
//             ind = find(value, l, mid);
//         }
//         else{
//             ind = find(value, mid, r);
//         }
//         return ind;
//     }
//
// };
class Solution {
public:
    vector<vector<int>> events;
    int _size;
    int maxTwoEvents(vector<vector<int>>& events) {
        _size = events.size();
        int n = 3;
        this->events = events;
        sort(events.begin(), events.end(), cmp);
        int sum = 0;
        for (int i = 0; i < _size; ++i) {
            sum = max(sum, events[i][2]);
        }
        // unordered_set<int> se;
        for (int i = 0; i < _size; ++i) {
            // canjia 1
            // if (se.count(i)){
            //     break;
            // }
            // int a = find(events[i][2], i, _size);
            // int a = events.upper_bound(events.begin)
            for (int j = i + 1; j < _size; ++j) {
                // canjia 2
                // 0 begin
                // 1 end
                // 2 value
                // 判断不重叠
                // if (se.count(j)){
                //     break;
                // }

                if ((events[i][0] < events[j][0] && events[i][1] < events[j][0]) || (events[i][0] > events[j][0] && events[j][1] < events[i][0])){
                    sum = max(sum, events[i][2] + events[j][2]);
                    break;
                }
                else if (events[i][2] + events[j][2] < sum){
                    break;
                }
            }
        }

        return sum;
    }
    static bool cmp(vector<int> a, vector<int> b){
        // if (a[0] == b[0]){
        //     return a[2] > b[2];
        // }
        // return a[0] < b[0];
        return a[2] > b[2];
    }
    int find(int value, int r, int l){
        int mid = (l + r) / 2;
        if (l == r){
            return l;
        }
        int ind;
        if (events[mid][0] > value){
            ind = find(value, l, mid);
        }
        else{
            ind = find(value, mid, r);
        }
        return ind;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Shoppin, Example2) {      // NOLINT
        // std::vector<int> nums = { 10,83,53};
        // string s = "**|**|***|";
        vector<vector<int>> t = {{ 1, 5,3} , {1,5,1}, {6,6,5}};
        // vector<int> n = {3, 2};
        auto ans = Solution().maxTwoEvents(t);
        decltype(ans) rightAns = 8;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
