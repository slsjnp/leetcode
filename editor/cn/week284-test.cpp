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
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        int _size = edges.size();
        vector<vector<pair<int,int>>> gra(n), rgra(n);
        for (auto &it: edges) {
            gra[it[0]].push_back({it[1], it[2]});
            rgra[it[1]].push_back({it[0], it[2]});
        }
        auto v1 = dijkstra(gra, n, src1);
        auto v2 = dijkstra(gra, n, src2);
        auto v3 = dijkstra(rgra, n, dest);
        // }
        long long sum = LONG_LONG_MAX;
        for (int i = 0; i < n; ++i) {
            // if (v3[i] != LONG_LONG_MAX and v1[i] != LONG_LONG_MAX and v2[i] != LONG_LONG_MAX){
            sum = min(sum, v1[i] + v2[i] + v3[i]);
            // }
        }
        if (sum == LONG_LONG_MAX) return -1;
        return sum;
    }
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &edges, int _size, int n){
        vector<long long> res(_size, LONG_LONG_MAX);
        res[n] = 0;
        // queue<int> qu;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> qu;
        qu.push({0 ,n});
        while(!qu.empty()){

            auto [now_dis, i] = qu.top();
            // int t = qu.front();
            qu.pop();
            if(now_dis > res[i]){
                continue;
            }
            for (auto & [to, weight]: edges[i]) {
                if (now_dis + weight < res[to]){
                    res[to] = now_dis + weight;
                    qu.emplace(res[to], to);
                }
            }
            // for (int i = 0; i < edges[t].size(); ++i) {
            //     auto tmp = edges[t][i];
            //     int idx = tmp.first, it = tmp.second;
            //     if (it == INT_MAX){
            //         continue;
            //     }
            //     if (res[t] + it < res[idx]){
            //         qu.push(idx);
            //         res[idx] = res[t] + it;
            //     }
            // }
        }
        return res;
    }

};
// class Solution {
// public:
//     long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
//         int _size = edges.size();
//         vector<vector<pair<int,int>>> gra(n), rgra(n);
//         // vector<pair<int, int>>
//         vector<int> vec(n, INT_MAX);
//         for (auto it: edges) {
//             // gra[it[0]][it[1]] = min(it[2], gra[it[0]][it[1]]);
//             gra[it[0]].push_back({it[1], it[2]});
//             rgra[it[1]].push_back({it[0], it[2]});
//         }
//         auto v1 = dijkstra(gra, n, src1);
//         auto v2 = dijkstra(gra, n, src2);
//         auto v3 = dijkstra(rgra, n, dest);
//         // for (int i = 0; i < n; ++i) {
//         //     printf("%lld ", v3[i]);
//         // }
//         long long sum = LONG_LONG_MAX;
//         for (int i = 0; i < n; ++i) {
//             if (v3[i] != LONG_LONG_MAX and v1[i] != LONG_LONG_MAX and v2[i] != LONG_LONG_MAX){
//                 sum = min(sum, v1[i] + v2[i] + v3[i]);
//             }
//         }
//         return sum;
//     }
//     vector<long long> dijkstra(vector<vector<pair<int, int>>> &edges, int _size, int n){
//         vector<long long> res(_size, LONG_LONG_MAX);
//         res[n] = 0;
//         queue<int> qu;
//         qu.push(n);
//         while(!qu.empty()){
//             int t = qu.front();
//             qu.pop();
//             if (edges[t].size() == 0){
//                 continue;
//             }
//             for (int i = 0; i < edges[t].size(); ++i) {
//                 auto tmp = edges[t][i];
//                 int idx = tmp.first, it = tmp.second;
//                 if (it == INT_MAX){
//                     continue;
//                 }
//                 if (res[t] + it < res[idx]){
//                     qu.push(idx);
//                     res[idx] = res[t] + it;
//                 }
//             }
//         }
//         return res;
//     }
//
// };

// class Solution {
// public:
//     int maximumTop(vector<int>& nums, int k) {
//         int _size = nums.size();
//         if (_size == 1) {
//             if (k & 1){
//                 return -1;
//             }
//             else{
//                 return nums[0];
//             }
//         }
//         if (k == 0) return nums[0];
//         if (k <= 1 && _size > k) return nums[k];
//         else if (k <= 1) return -1;
//         // if (k == 2 && _size > k) return max(nums[0], nums[2]);
//         // else if(k == 2) return nums[0];
//         auto it = max_element(nums.begin(), nums.begin() + min(k - 1, _size));
//
//         if (k < _size){
//             return max(*it, nums[k]);
//         }
//         else{
//             return *it;
//         }
//     }
// };

// class Solution {
// public:
//     int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
//         sort(dig.begin(), dig.end());
//         int a_size = artifacts.size();
//         int d_size = dig.size();
//         vector<vector<int>> pre(n + 1, vector<int> (n + 1, 0));
//         vector<vector<int>> res(n + 1, vector<int> (n + 1, 0));
//         for(auto it: dig){
//             res[it[0]][it[1]] = 1;
//         }
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + res[i][j];
//             }
//         }
//         int ans = 0;
//         for(auto it: artifacts){
//             int r1 = it[0], c1 = it[1], r2 = it[2], c2 = it[3];
//             if (r2 == r1 && c1 == c2){
//                 ans++;
//                 continue;
//             }
//             // int t = pre[r2 + 1][c2 + 1] + pre[r1][c1] - pre[r2][c1] - pre[r1][c2];
//             // printf("%d\n", t);
//             if (pre[r2 + 1][c2 + 1] + pre[r1][c1] - pre[r2 + 1][c1] - pre[r1][c2 + 1] >= max(1, (r2 - r1)) * max(1, (c2 - c1))){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
//         int _size = nums.size();
//         vector<int> res;
//         unordered_set<int> se;
//         for (int i = 0; i < _size; ++i) {
//             if (nums[i] == key){
//                 int l = min(0, i - k - 1);
//                 int r = min(_size - 1, i + k + 1);
//                 for (int j = l; j < r; ++j) {
//                     if (se.count(j) == 0){
//                         se.insert(j);
//                     }
//                 }
//             }
//         }
//         for(auto it : se){
//             res.push_back(it);
//         }
//         return res;
//     }
// };


//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week284, Example2) {      // NOLINT
        // std::vector<int> nums = {98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821,
        //                          98818, 98821, 98818};

        // vector<vector<int>> nums = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
        vector<vector<int>> nums = {{0,1,1},{2,1,1}};
        auto ans = Solution().minimumWeight(3, nums, 0, 1, 2);
        decltype(ans) rightAns = 9;
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
