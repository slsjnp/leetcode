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
    long long maxRunTime(int n, vector<int>& batteries) {
        int _size = batteries.size();
        priority_queue<int, vector<int> > pq;
        for (int i = 0; i < _size; ++i) {
            pq.push(batteries[i]);
        }
        deque<int> dq;
        int ans = 0;
        while (pq.size() > 0 and pq.top() != 0){
            int sum = 0;
            while (pq.size() > 0 and pq.top() > 0 and sum < n){
                int t = pq.top();
                if(t > 0) dq.push_back(t);
                pq.pop();
                sum++;
            }
            if (sum < n){
                break;
            }
            if(!dq.empty() and !pq.empty()){
                int b;
                b = pq.top() == dq.back() or dq.back() == 1 ? 1 : dq.back() - pq.top();
                // if(pq.top() == 0) b = dq.back();
                while(!dq.empty()){
                    pq.push(dq.front() - b);
                    dq.pop_front();
                }
                ans += b;
            }
            else{
                ans += 1;
            }
            printf("%d ",ans);
        }
        return ans;
    }
};

// class Solution {
// public:
//     long long ans = 0;
//     vector<int> res;
//     vector<int> tmp;
//     int _size;
//     map<int, long long> ma;
//     long long dp[200005];
//
//     long long mostPoints(vector<vector<int>> &questions) {
//         _size = questions.size();
//         long long dp[_size];
//         memset(dp, 0, sizeof(dp));
//         for (int i = _size; i >= 0; --i) {
//             // if (i + questions[i][1] + 1 > _size) dp[i] = questions[i][0];
//             dp[i] = max(dp[i + questions[i][1] + 1] + questions[i][0], dp[i + 1]);
//         }
//         // dfs(questions, 0, 0);
//         return dp[0];
//     }
//
//     int dfs(vector<vector<int>> &ques, int l, long long now) {
//         if (l >= _size) {
//             // res.push_back(now);
//             // for (int i = 0; i < tmp.size(); ++i) {
//             //     printf("%d ", tmp[i]);
//             // }
//             ans = max(ans, now);
//             ma[l] = 0;
//             return 0;
//         }
//         if (ma.count(l)) {
//             ans = max(ans, ma[l]);
//             return ma[l];
//         }
//         long long max_ = 0;
//         auto r = ma.lower_bound(l);
//         for (int i = l; i < r - ma.begin(); ++i) {
//             // tmp.push_back(i);
//             ma[i] = dfs(ques, i + ques[i][1] + 1, now + ques[i][0]) + ques[i][0];
//             max_ = max(ma[i], max_);
//             // else ma[l] = dfs(ques, i + ques[i][1] + 1, now + ques[i][0]);
//             // tmp.pop_back();
//         }
//         ma[l] = max(max_, ma[r]);
//         return ma[l];
//     }
// };


// class Solution {
// public:
//     int minMoves(int target, int maxDoubles) {
//         int ans = 0;
//         int pp = 0;
//         while(target != 1){
//             if (pp == maxDoubles){
//                 ans += maxDoubles - 1;
//                 break;
//             }
//             if (target % 2 == 0) {
//                 target /= 2;
//                 ans++;
//                 pp++;
//             }
//             else{
//                 target -= 1;
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<string> divideString(string s, int k, char fill) {
//         int _size = s.size();
//         vector<string> res;
//
//         for (int i = 0; i < _size; i += k) {
//             if (i + 3 < _size){
//                 string tmp = string(s.begin() + i, s.begin() + i + 3);
//                 res.emplace_back(tmp);
//             }
//             else{
//                 string tmp = string(s.begin() + i, s.end());
//                 while (tmp.size() != k){
//                     tmp += fill;
//                 }
//                 res.emplace_back(tmp);
//             }
//
//         }
//         return res;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week276, Example2) {      // NOLINT
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
