// 2022-01-22 01:23:13
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nums;
    int start, goal;
    int minimumOperations(vector<int> &nums, int start, int goal) {
        this->nums = nums;
        this->start = start;
        this->goal = goal;
        int _size = nums.size();
        int ans = bfs();
        return ans;
    }

    int bfs() {
        unordered_map<int, int> m1, m2;
        m1[start] = 0;
        m2[goal] = 0;
        queue<int> q1, q2;
        q1.push(start);
        q2.push(goal);

        while (!q1.empty() and !q2.empty()) {
            int t = -1;
            if (q1.size() < q2.size()) {
                t = update(q1, m1, m2);
            }
            else{
                t = update(q2, m2, m1);
            }
            if(t != -1) return t;
        }
        return -1;
    }

    int update(queue<int> &q, unordered_map<int, int> &now, unordered_map<int, int> &target){
        int t = q.front();
        q.pop();
        int step = now[t];
        for (int x: nums) {
            for (int v: {x + t, t - x, t ^ x }) {
                if (v == 594){
                    int a = 0;
                }
                if (target.count(v)){
                    printf("%d %d",v,step);
                    return step + 1 + target[v];
                }
                else if(v <= 1000 and v >= 0 and !now.count(v)){
                    q.push(v);
                    now[v] = step + 1;
                }
            }
        }
        return -1;
    }
};

// int minimumOperations(vector<int>& nums, int start, int goal) {
//     int _size = nums.size();
//     queue<int> qu;
//     qu.push(start);
//     int dp[1005];
//     memset(dp, -1, sizeof(dp));
//     dp[start] = 0;
//     int now;
//     while(!qu.empty()){
//         now = qu.front();
//         int step = dp[now];
//         qu.pop();
//         for (int x: nums) {
//             for (int v: {now + x, now - x, now ^ x}) {
//                 // printf("%d ", dp[now]);
//                 if (v == goal) {
//                     return step + 1;
//                 }
//                 else if (v <= 1000 and v >=0 and dp[v] == -1){
//                     // if (v <= 1000 and v >=0 and (step + 1 < dp[v] or dp[v] == -1)){
//                     qu.push(v);
//                     dp[v] = step + 1;
//                 }
//             }
//         }
//     }
//     return -1;
// }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumOperationsToConvertNumber, Example1) {      // NOLINT
        std::vector<int> nums = {27,21,89,-37,23,-46,-82,-57,-23,-38,74,-35,-32,53,11,-62,9,-77,-25,-12,-50,33,-52,-10,-72,-16,50,-51,63,10,60,-94,15,65,20,-34,22,-41,-39,-30,-11,35,-63,-55,99,48,-92,-66,1};
        auto ans = Solution().minimumOperations(nums, 92, 720);
        decltype(ans) rightAns = 8;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}