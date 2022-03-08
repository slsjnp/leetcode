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
    unordered_set<int> se;

    int scoreOfStudents(string s, vector<int> &answers) {

        int pre = s[0] - '0';
        int sum = 0;
        for (int i = 1; i < s.size(); i += 2) {
            if (s[i] == '*'){
                pre *= s[i + 1] - '0';
            }
            else{
                sum += pre;
                pre = s[i + 1] - '0';
            }
        }
        int right = sum + pre;
        // sum += pre;
        dfs(s, 1, s[0] - '0', 0);
        // vector<int> ans;
        int ans = 0;
        for(auto it: se){
            printf("%d ",it);
        }
        for (auto it: answers) {
            if (it == right) {
                ans += 5;
                // ans.push_back(5);
                continue;
            }
            if (se.count(it)) {
                // ans.push_back(2);
                ans += 2;
                // } else {
                // ans.push_back(0);
            }
        }
        return ans;
    }

    void dfs(string &s, int l, int pre, int sum) {
        if (l >= s.size()) {
            if (!se.count(sum + pre)) {
                se.insert(sum + pre);
            }
            return;
        }
        if (s[l] == '*' and l < s.size()) {
            if (pre != 0) {
                pre = pre * (s[l + 1] - '0');
            } else {
                sum *= (s[l + 1] - '0');
            }
            l += 2;
            dfs(s, l + 2, pre, sum);
            dfs(s, l + 2, s[l + 1] - '0', sum);
        }
        if (s[l] == '+'){
            sum += pre;
            dfs(s, l + 2, 0, sum + s[l + 1] - '0');
            dfs(s, l + 2, s[l + 1] - '0', sum);
        }
    }
};

// class Solution {
// public:
//     bool placeWordInCrossword(vector<vector<char>> &board, string word) {
//         int m = board.size(), n = board[0].size();
//         int _size = word.size();
//         vector<string> res;
//         for (int i = 0; i < m; ++i) {
//             int sum = 0;
//             string s;
//             for (int j = 0; j < n; ++j) {
//                 if (board[i][j] != '#') {
//                     sum++;
//                     s += board[i][j];
//                 } else {
//                     if (sum == _size) {
//                         res.push_back(a);
//                     }
//                     s = "";
//                     sum = 0;
//                 }
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             int sum = 0;
//             string s;
//             for (int j = 0; j < m; ++j) {
//                 if (board[j][i] != '#') {
//                     sum++;
//                     s += board[j][i];
//                 } else {
//                     if (sum == _size) {
//                         res.push_back(a);
//                     }
//                     s = "";
//                     sum = 0;
//                 }
//             }
//         }
//         for (auto it: res) {
//             int i = 0;
//             int flag = 1;
//             for (auto itm: it) {
//                 if (itm != ' ' and itm != word[i]){
//                     flag = 0;
//                     break;
//                 }
//                 i++;
//             }
//             if (flag) return true;
//             i = 0, flag = 1;
//             for (int j = 0; j < it.size(); ++j) {
//                 itm = it[it.size() - 1 - j];
//                 if (itm != ' ' and itm != word[i]){
//                     flag = 0;
//                     break;
//                 }
//                 i++;
//             }
//             if (flag) return true;
//         }
//         return false;
//     }
// };
// class Solution {
// public:
//     long long gridGame(vector<vector<int>> &grid) {
//         int n = grid.size(), m = grid[0].size();
//         int sum = 0;
//         vector<int> pre1(m + 1, 0);
//         vector<int> pre2(m + 1, 0);
//         for (int j = 0; j < m; ++j) {
//             LONG_LONG_MAX
//             pre1[j + 1] = pre1[j] + grid[0][j];
//             pre2[j + 1] = pre2[j] + grid[1][j];
//         }
//         int pos = 0;
//         for (int i = 0; i < m; ++i) {
//             if (pre1[m] - pre1[i] < pre2[m] - pre2[i] + grid[0][i]){
//                 pos = i;
//                 break;
//             }
//         }
//         for (int i = 0; i <= pos; ++i) {
//             grid[0][i] = 0;
//         }
//         for (int i = pos; i < m; ++i) {
//             grid[1][i] = 0;
//         }
//
//         for (int j = 0; j < m; ++j) {
//             pre1[j + 1] = pre1[j] + grid[0][j];
//             pre2[j + 1] = pre2[j] + grid[1][j];
//         }
//         pos = 0;
//         for (int i = 0; i < m; ++i) {
//             if (pre1[m] - pre1[i] < pre2[m] - pre2[i] + grid[0][i]){
//                 pos = i;
//                 break;
//             }
//         }
//         return pre1[pos + 1] + pre2[m] - pre2[pos];
//     }
// };
// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int _size = nums.size();
//         int sum = nums[1] - nums[0];
//         for (int i = 0; i < _size; ++i) {
//             for (int j = i + 1; j < _size; ++j) {
//                 // if (nums[j] == nums[i]) continue;
//                 if (sum < nums[j] - nums[i]){
//                     sum = nums[j] - nums[i];
//                 }
//             }
//         }
//         if (sum <= 0){
//             return -1;
//         }
//         return sum;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week260, Example2) {      // NOLINT
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
