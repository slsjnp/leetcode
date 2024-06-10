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
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int _size = fruits.size();
        int sum = 0;
        int flag = 0;
        int l = 0;
        int r = 0;
        vector<int> pos;
        for (int i = 0; fruits[i][0] <= startPos; ++i) {
            if (fruits[i][0] >= startPos - k and fruits[i][0] <= startPos){
                if (flag == 0){
                    l = i;
                    flag = 1;
                }
                sum += fruits[i][1];
                r = fruits[i][0];
            }
            pos.emplace_back(fruits[i][0]);
        }
        int stop = upper_bound(pos.begin(), pos.end(), startPos + k) - pos.begin();
        int now = sum;
        int h = startPos - fruits[i][0];
        int z = r;
        flag = 0;
        for (int i = l + 1; i < _size and fruits[i][0] <= startPos + k; ++i) {
            // h += fruits[i][0] - fruits[i - 1][0];
            // now -= fruits[i - 1][1];
            if (h >= (startPos - fruits[i][0]) + fruits[r][0]) {
                flag = 1;
            }
            // if (i >= z){
            //     flag = 0;
            // }
            while (flag and h >= fruits[r][0]){
                now += fruits[r][1];
                r++;
            }

            sum = max(now, sum);
            now -= fruits[i][1];
            if (flag and i + 1 < stop) h += (fruits[i + 1][0] - fruits[i][0]) * 2;
            else{
                h += fruits[i + 1][0];
            }
        }
        return sum;
    }
};
// class Solution {
// public:
//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
//         int n = fruits.size();
//         vector<int> sum(n);
//         for (int i = 0; i < n; i += 1) {
//             sum[i] = fruits[i][1];
//             if (i) sum[i] += sum[i - 1];
//         }
//         int x = 0;
//         while (x < n and fruits[x][0] < startPos) x += 1;
//         int ans = 0;
//         for (int i = x - 1, s = 0; i >= 0; i -= 1) {
//             if (fruits[i][0] >= startPos - k) {
//                 s += fruits[i][1];
//                 ans = max(ans, s);
//             }
//         }
//         for (int i = x, s = 0; i < n; i += 1) {
//             if (fruits[i][0] <= startPos + k) {
//                 s += fruits[i][1];
//                 ans = max(ans, s);
//             }
//         }
//         for (int i = x, j = 0; i < n; i += 1) {
//             while (j < x and fruits[i][0] - fruits[j][0] + min(fruits[i][0] - startPos, startPos - fruits[j][0]) > k) j += 1;
//             if (j == x) break;
//             int pans = sum[i];
//             if (j) pans -= sum[j - 1];
//             ans = max(ans, pans);
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int _su = 0;
//     int _size;
//     map<int, int> ma;
//     int maxTotalFruits(vector <vector<int>> &fruits, int startPos, int k) {
//         this->_size = fruits.size();
//         for (int i = 0; i < _size; ++i) {
//             ma[fruits[i][0]] = fruits[i][1];
//         }
//         unordered_map<int, int> st;
//         for (int i = 0; i < _size; ++i) {
//             st[fruits[i][0]] = 1;
//         }
//         dfs(startPos, k, 0, st);
//         return _su;
//     }
//
//     void dfs(int start, int t, int _sum, unordered_map<int, int> _st) {
//         auto up = ma.upper_bound(start);
//         if (t < 0 || _st.count(up->first) == 0) {
//             _su = max(_sum, _su);
//             return;
//         }
//         if (up != ma.end()){
//             auto _stat = _st;
//             int k = t - abs(up->first - start);
//             int sum = _sum;
//             if(k < 0) {
//                 _su = max(sum, _su);
//                 return;
//             }
//             printf("k : %d\n", k);
//             printf("now : %d\n", start);
//             printf("next :%d\n", up->first);
//             // printf("flag :%d\n", _stat[up->first]);
//
//             if (_stat.count(up->first)){
//                 sum += up->second;
//                 _stat.erase(up->first);
//                 printf("sum :%d\n", sum);
//             }
//             dfs(up->first, k, sum, _stat);
//             // if (up->first != start) dfs(up->first, k, sum, _stat);
//             // else if(){
//             //     dfs()
//             // }
//         }
//         if (--(--up) != ma.end()){
//             auto _stat = _st;
//             int k = t - abs(up->first - start);
//             int sum = _sum;
//             if(k < 0) {
//                 _su = max(sum, _su);
//                 return;
//             }
//             printf("k : %d\n", k);
//             printf("now : %d\n", start);
//             printf("next :%d\n", up->first);
//             // printf("flag :%d\n", _stat[up->first]);
//
//             if (_stat.count(up->first)){
//                 sum += up->second;
//                 _stat.erase(up->first);
//                 printf("sum :%d\n", sum);
//             }
//             dfs(up->first, k, sum, _stat);
//         }
//         if(--up != ma.begin()){
//             auto _stat = _st;
//             // up--;
//             int k = t - abs(up->first - start);
//             int sum = _sum;
//             if(k < 0) {
//                 _su = max(sum, _su);
//                 return;
//             }
//             printf("k : %d\n", k);
//             printf("now : %d\n", start);
//             printf("next :%d\n", up->first);
//             // printf("flag :%d\n", _stat[up->first]);
//             if (_stat.count(up->first)){
//                 sum += up->second;
//                 _stat.erase(up->first);
//                 printf("sum :%d\n", sum);
//             }
//             dfs(up->first, k, sum, _stat);
//         }
//     }
//
// };

// class Solution {
// public:
//     int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
//         int _size = plants.size();
//         int ca = capacityA;
//         int cb = capacityB;
//         int sum = 0;
//         int l = 0;
//         int r = _size - 1;
//         while (l < r){
//             // A
//             if (ca >= plants[l]){
//                 ca -= plants[l];
//                 l++;
//             }
//             else {
//                 sum++;
//                 ca = capacityA - plants[l];
//                 ++l;
//             }
//
//             // B
//             if (cb >= plants[r]){
//                 cb -= plants[r];
//                 --r;
//             }
//             else {
//                 sum++;
//                 cb = capacityB - plants[r];
//                 --r;
//             }
//         }
//         if (l == r){
//             if (ca < plants[l] and cb < plants[l]){
//                 sum++;
//             }
//         }
//         return sum;
//     }
// };
// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int _size = nums.size();
//         // vector<vector<int>> res(_size + 1, vector<int> {INT32_MAX, 0});
//
//         // for (int i = 1; i < _size; ++i) {
//         //     if (nums[i] < res[i - 1][0]){
//         //         res[i][0] = nums[i];
//         //     }else{
//         //         res[i][0] = res[i - 1][0];
//         //     }
//         //     if (nums[i] > res[i - 1][1]){
//         //         res[i][1] = nums[i];
//         //     }else{
//         //         res[i][1] = res[i - 1][1];
//         //     }
//         // }
//         long long sum = 0;
//         long _max = 0;
//         long _min = INT32_MAX;
//         for (int i = 0; i < _size; ++i) {
//             int _max = INT32_MIN;
//             int _min = INT32_MAX;
//             for (int j = i; j < _size; ++j) {
//                 if (nums[j] < _min){
//                     _min = nums[j];
//                 }
//                 if (nums[j] > _max){
//                     _max = nums[j];
//                 }
//                 sum += (_max - _min);
//             }
//         }
//         return sum;
//     }
// };
// class Solution {
// public:
//     int countPoints(string rings) {
//         int _size = rings.size();
//         unordered_map<char, int> ma;
//         for (int i = 0; i < _size; i+=2) {
//             if (ma.count(rings[i+1]) == 0){
//                 if (rings[i] == 'R') ma[rings[i+1]] = 1;
//                 if (rings[i] == 'G') ma[rings[i+1]] = 2;
//                 if (rings[i] == 'B') ma[rings[i+1]] = 4;
//             }
//             else{
//                 if (rings[i] == 'R') ma[rings[i+1]] |= 1;
//                 if (rings[i] == 'G') ma[rings[i+1]] |= 2;
//                 if (rings[i] == 'B') ma[rings[i+1]] |= 4;
//             }
//         }
//         int sum = 0;
//         for (auto it: ma) {
//             if (it.second == 7){
//                 sum++;
//             }
//         }
//         return sum;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week271, Example2
    ) {      // NOLINT
    // std::vector<int> nums = { 10,83,53};
    // string s = "**|**|***|";
    vector <vector<int>> t = {{1, 5, 3},
                              {1, 5, 1},
                              {6, 6, 5}};
    // vector<int> n = {3, 2};
    auto ans = Solution().maxTwoEvents(t);
    decltype(ans)
    rightAns = 8;
    ASSERT_EQ(ans, rightAns
    );
}

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
