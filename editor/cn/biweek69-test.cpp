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
    int h;
    int w;
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();
        this->h = stampHeight;
        this->w = stampWidth;
        int pre[m + 1][n + 1];
        int sum[m + 1][n + 1];
        int vis[m + 1][n + 1];
        memset(pre, 0, sizeof(pre));
        memset(sum, 0, sizeof(sum));
        memset(vis, 0, sizeof(vis));
        // vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        // vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        // vis = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + grid[i][j];
            }
        }

        for (int i = 0; i <= m - h; ++i) {
            for (int j = 0; j <= n - w; ++j) {
                if (pre[i + h][j + w] - pre[i + h][j] - pre[i][j + w] + pre[i][j] == 0) {
                    vis[i][j] += 1;
                    vis[i + h][j] += -1;
                    vis[i][j + w] += -1;
                    vis[i + h][j + w] += 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + vis[i][j];
                if (sum[i + 1][j + 1] + grid[i][j] == 0){
                    return false;
                }
                // printf("%d ",sum[i + 1][j + 1]);
            }
            // printf("\n");
        }
        return true;
    }
};



// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     int longestPalindrome(vector<string> &words) {
//         int _size = words.size();
//         int ans = 0;
//         int flag = 1;
//         unordered_map<string, int> ma;
//         for (int i = 0; i < _size; ++i) {
//             ma[words[i]]++;
//         }
//         for (int i = 0; i < _size; ++i) {
//             if(words[i][0] == words[i][1] and ma[words[i]] >= 2){
//                 ans += 4;
//                 flag = 1;
//                 ma[words[i]] -= 2;
//
//             }
//             if (words[i][0] == words[i][1]) {
//                 continue;
//             }
//             string re = words[i];
//             std::reverse(re.begin(), re.end());
//             if (ma.count(re) and ma[re] > 0 and ma[words[i]]) {
//                 ma[re]--;
//                 ma[words[i]]--;
//                 ans += 4;
//                 flag = 1;
//             }
//         }
//         for (int i = 0; i < _size; ++i) {
//
//             if (words[i][0] == words[i][1] and flag and ma[words[i]] > 0) {
//                 ans += 2;
//                 flag = 0;
//                 // ma[re]--;
//                 ma[words[i]]--;
//             }
//
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         int _size = 0;
//         ListNode* t = head;
//         while(t != nullptr){
//             _size++;
//             t = t->next;
//         }
//         vector<int> res(_size / 2, 0);
//         int i = 0;
//         t = head;
//         while(t != nullptr){
//             if (i > _size / 2){
//                 res[_size + 1 - i] = t->val;
//             }
//             else{
//                 res[i] = t->val;
//             }
//             t = t->next;
//         }
//         int ans = 0;
//         for (auto it: res) {
//             ans = max(ans, it);
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     string capitalizeTitle(string title) {
//         int _size = title.size();
//         string ans;
//         int flag = 1;
//         for (int i = 0; i < _size; ++i) {
//             int len = 0;
//             while(i < _size and title[i] != ' '){
//                 len++;
//                 i++;
//             }
//             i -= len;
//             if (flag and len > 2){
//                 ans += toupper(title[i]);
//                 flag = 0;
//             }
//             else {
//                 ans += tolower(title[i]);
//             }
//             if (title[i] == ' '){
//                 flag = 1;
//             }
//         }
//         return ans;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(biweek69, Example1) {      // NOLINT
        // std::vector<int> nums = {};
        // vector<vector<int>> nums = {{0},{0},{0},{0},{1},{1},{0},{0},{1}};
        // vector<vector<int>> nums = {{0,0,1,1},{0,0,1,1}};
        vector<vector<int>> nums = {{1, 0, 0, 0},
                                    {1, 0, 0, 0},
                                    {1, 0, 0, 0},
                                    {1, 0, 0, 0},
                                    {1, 0, 0, 0}};
        // vector<vector<int>> nums = {{1,1,1,1,1,0},{1,0,0,1,0,0},{1,1,0,1,1,0},{1,0,0,1,0,0},{1,0,1,0,1,0},{1,1,1,0,1,1},{0,0,1,0,0,0},{0,0,1,1,0,0}};
        auto ans = Solution().possibleToStamp(nums, 4, 3);
        decltype(ans) rightAns = true;
        ASSERT_EQ(ans, rightAns);
    }

    // TEST(biweek69, Example2) {      // NOLINT
    //     // std::vector<int> nums = { 10,83,53};
    //     // string s = "**|**|***|";
    //     vector<vector<int>> t = {{1, 5, 3},
    //                              {1, 5, 1},
    //                              {6, 6, 5}};
    //     // int a = 6;
    //     // vector<int> n = {3, 2};
    //     auto ans = Robot(6, 3);
    //     ans.move(2);
    //     ans.move(2);
    //     ans.move(2);
    //     ans.move(1);
    //     ans.move(4);
    //     int c = 0;
    //     decltype(c) rightAns = 8;
    //     ASSERT_EQ(c, rightAns);
    // }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
