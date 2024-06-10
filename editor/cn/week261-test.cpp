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
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int _size = s.size();
        stack<char> st;
        string ss;
        int r = _size - 1;
        while(r--){
            while(!st.empty() and s[st.top()] < s[r]){
                st.pop();
            }
            ss[r] = st.empty() ? -1: st.top();
            st.push(r);
        }
        for (int i = 0; i < ; ++i) {

        }

    }
};
// class Solution {
// public:
//     /*
//      * 规则：
//      * a 胜利条件：
//      *          a 先手 ，并让B触发整除3规则
//      * b 胜利条件：
//      *          让A 触发整除规则
//      *          移除所有棋子
//      *
//      *          1 后只能跟 1，3
//      *          2 后只能跟 2，3
//      *
//      *          3 可以在开局后 任何条件使用， 作用为反转
//      *          把最小的耗尽就能分胜负
//      *          min （ 1 + 3， 2）； min（1， 2 + 3）；
//      *
//      */
//     bool stoneGameIX(vector<int>& stones) {
//         int _size = stones.size();
//         int sum = 0;
//         unordered_map<int ,int> ma;
//         for (auto &it: stones) {
//             sum += it;
//             it %= 3;
//             ma[it]++;
//         }
//         if (ma[1] == ma[2] and ma[1] == 0){
//             return false;
//         }
//         if(ma[1] == ma[2]) {
//             if (ma[0] % 2 == 0) return true;
//             else return false;
//         }
//         if ((ma[1] + ma[0] == ma[2] or ma[1] == ma[0] + ma[2]) and ma[1] != ma[2]){
//             return false;
//         }
//         if (abs(ma[1] - ma[2]) > 1){
//             if (ma[0] % 2 == 0){
//                 return false;
//             }
//             else return true;
//         }
//         return false;
//         // else if (ma[0] % 2 == 0){
//         //     return false;
//         // }
//         // else{
//         //     return true;
//         // }
//         // if ((ma[1] + ma[2]) % 2 == 0){
//         //     return true;
//         // }
//     }
// };
// class Solution {
// public:
//     vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//         int _size = rolls.size();
//         int sum = mean * (_size + n);
//         for (int i = 0; i < _size; ++i) {
//             sum -= rolls[i];
//         }
//         if (sum / n > 6 or (sum / n == 6 and sum % n != 0)){
//             return {};
//         }
//         else if (sum < n){
//             return {};
//         }
//         else if (sum % n == 0){
//             return vector<int> (n, sum / n);
//         }
//         vector<int> res;
//         for (int i = n; i > 0; --i) {
//             for (int j = 6; j >= 1; --j) {
//                 if (i == 1){
//                     if (sum > 6){
//                         return {};
//                     }
//                     res.push_back(sum);
//                     return res;
//                 }
//                 if ((sum - j) / (i-1) >= 1){
//                     res.push_back(j);
//                     sum -= j;
//                     break;
//                 }
//
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     int minimumMoves(string s) {
//         int _size = s.size();
//         int flag = 0;
//         int ans = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (s[i] == 'x'){
//                 s[i] = 'O';
//                 while(i + 1 < _size and flag < 3){
//                     s[i + 1] = 'O';
//                     flag++;
//                     i++;
//                 }
//                 flag = 0;
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week261, Example2) {      // NOLINT
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
