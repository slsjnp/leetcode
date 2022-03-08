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
    unordered_map<int, vector<int>> ma;
    int time;
    int n;
    int change;
    int flag = 0;
    int vaild = 0;
    // unordered_set<int> se;
    vector<int> arr;

    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
        this->time = time;
        this->n = n;
        this->change = change;
        // vector<int> vis(n + 1, 0);
        unordered_map<int ,vector<int>> vis;
        for (auto it: edges) {
            ma[it[0]].push_back(it[1]);
            ma[it[1]].push_back(it[0]);
        }
        int min_;
        deque<pair<int, int>> qu;
        qu.push_back(pair<int, int>(1, 0));
        se.insert(1);
        int now_d, now_t;
        while (!qu.empty()) {
            auto [now_d, now_t] = qu.front();
            if (now_d == n) {
                min_ = now_t;
                if(arr.size() > 0 and arr[arr.size() - 1] != now_t) break;
                arr.emplace_back(now_t);
            }
            qu.pop_front();
            vector<int> tmp = ma[now_d];
            for (int i = 0; i < tmp.size() and vaild != change + time; ++i) {
                if (vis.count(tmp[i]) and vis[tmp[i]].size() > 1){
                    continue;
                }
                if (now_t / change % 2 == 0) {
                    if (vis[tmp[i]].size() == 1 and now_t + time == vis[tmp[i]][0]){
                        continue;
                    }
                    vis[tmp[i]].push_back(now_t + time);
                    qu.push_back(pair<int, int>(tmp[i], now_t + time));
                } else {
                    if (vis[tmp[i]].size() == 1 and now_t + time + change - now_t % change == vis[tmp[i]][0]){
                        continue;
                    }
                    vis[tmp[i]].push_back(now_t + time + change - now_t % change);
                    qu.push_back(pair<int, int>(tmp[i], now_t + time + change - now_t % change));
                }
            }
        }
        return min_;
    }
};



// class Solution {
// public:
//     vector<vector<int>> res;
//     int _size;
//     vector<int> tmp;
//     int countMaxOrSubsets(vector<int>& nums) {
//         int sum = 0;
//         _size = nums.size();
//         int ans = 0;
//         for (int i = 0; i < _size; ++i) {
//             sum |= nums[i];
//         }
//         dfs(nums, 0);
//         for (auto it: res) {
//             int t = 0;
//             for (int i = 0; i < it.size(); ++i) {
//                 t |= it[i];
//                 if (t == sum){
//                     ans++;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
//     void dfs(vector<int>& nums, int l){
//         res.push_back(tmp);
//         if (l == _size){
//             return;
//         }
//         for (int i = l; i < _size; ++i) {
//             tmp.push_back(nums[i]);
//             dfs(nums, i + 1);
//             tmp.pop_back();
//         }
//     }
// };
// class Bank {
// public:
//     vector<long long> res;
//     int _size;
//     Bank(vector<long long>& balance) {
//         _size = balance.size();
//         res = balance;
//     }
//
//     bool transfer(int account1, int account2, long long money) {
//         if (account1 > _size or account2 > _size){
//             return false;
//         }
//         if (res[account1 - 1] - money < 0){
//             return false;
//         }
//         else {
//             res[account1 - 1] -= money;
//             res[account2 - 1] += money;
//         }
//         return true;
//     }
//
//     bool deposit(int account, long long money) {
//         if (account > _size){
//             return false;
//         }
//         else {
//             res[account - 1] += money;
//         }
//         return true;
//     }
//
//     bool withdraw(int account, long long money) {
//         if (account > _size){
//             return false;
//         }
//         else if (res[account - 1] - money >= 0){
//             res[account - 1] -= money;
//         }
//         else{
//             return false;
//         }
//         return true;
//     }
// };

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// class Solution {
// public:
//     bool areNumbersAscending(string s) {
//         int _size = s.size();
//         int pre = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (s[i] >= '0' and s[i] <= '9'){
//                 int k = i + 1;
//                 int tmp = s[i] - 0;
//                 while (k < _size and s[k] >= '0' and s[k] <= '9'){
//                     tmp = tmp * 10 + s[k] - '0';
//                     k++;
//                 }
//                 if (tmp < pre){
//                     return false;
//                 }
//                 pre = tmp;
//                 i += k;
//             }
//         }
//         return true;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week263, Example2) {      // NOLINT
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
