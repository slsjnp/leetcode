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
    map<int, vector<int>> ma;

    vector<vector<int>> ans;
    void dfs(int sn){
        vector<int>& e = ma[sn];
        while(!e.empty()){
            int fn = e.back();
            e.pop_back();
            dfs(fn);
            ans.emplace_back(vector<int>{sn, fn});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int, int> deg;
        for (auto& it: pairs) {
            ma[it[0]].emplace_back(it[1]);
            deg[it[0]]++;
            deg[it[1]]--;
        }
        vector<int> _start;
        vector<int> _end;
        for (auto& it: deg) {
            if (it.second == 1){
                dfs(it.first);
            }
            // else if (it[0] + it[1] == -1){
            // _end = it;
            // }
        }
        if (ans.empty()){
            dfs(deg.begin()->first);
            // 半欧拉图
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<int> s1;
//     vector<int> s2;
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         s1 = find_path(root, startValue);
//         s2 = find_path(root, destValue);
//         int _min = min(s1.size(), s2.size());
//         for(auto it: s2){
//             printf("%d", it);
//         }
//         printf("\n");
//         // 找到最后一个不同
//         int t = 0;
//         for (int i = 0; i < _min; ++i) {
//             if (s1[i] == s2[i]){
//                 t++;
//             } else{
//                 break;
//             }
//         }
//
//         string res;
//         for (int i = 0; i< s1.size() - t; i++){
//             res += "U";
//         }
//         printf("%s", res.c_str());
//
//         TreeNode* h = root;
//         for (int i = 1; i < t; ++i) {
//             if (h->left != nullptr and h->left->val == s2[i]){
//                 h = h->left;
//             }
//             else {
//                 h = h->right;
//             }
//         }
//         printf("%d", t);
//         for (int i = t; i < s2.size(); ++i) {
//             if (h->left != nullptr and h->left->val == s2[i]){
//                 res += "L";
//                 h = h->left;
//             }
//             else {
//                 res += "R";
//                 h = h->right;
//             }
//         }
//         return res;
//
//
//         // 反转路径，遍历第二组
//     }
//     vector<int> find_path(TreeNode* root, int start){
//         vector<int> res(100000, -1);
//         unordered_map<int, int> ma;
//         stack<TreeNode*> st;
//         TreeNode* t = root;
//         int i = 0;
//         int flag = 0;
//         while(t != nullptr or st.size() > 0){
//             while (t != nullptr){
//                 res[i] = t->val;
//                 // for(auto it: res){
//                 //     printf("%d", it);
//                 // }
//                 // printf("\n");
//
//                 ma[t->val] = i;
//                 if (t->val == start){
//                     flag = 1;
//                     break;
//                 }
//                 i++;
//
//                 st.push(t);
//                 t = t->left;
//             }
//             if (flag){
//                 break;
//             }
//             t = st.top();
//             st.pop();
//             i = ma[t->val];
//             t = t->right;
//             if (t != nullptr) i++;
//         }
//         return vector<int> (res.begin(), res.begin() + i + 1);
//     }
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         int _size = 0;
//         ListNode* h = head;
//         while (h != nullptr){
//             _size++;
//             h = h->next;
//         }
//         int n = _size / 2;
//         if (n == 0){
//             ListNode* t = head;
//             h = t->next;
//             free(t);
//             return h;
//         }
//         else{
//             n--;
//             h = head;
//             while(n != 0){
//                 h = h->next;
//                 n--;
//             }
//             ListNode* t = h->next;
//             h->next = t->next;
//             free(t);
//             return head;
//         }
//     }
// };
// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int> &digits) {
//         int _size = digits.size();
//         vector<int> res;
//         for (int i = 0; i < digits.size(); ++i) {
//             if ((digits[i] & 1) == 0) {
//                 for (int j = 0; j < _size; ++j) {
//                     if (i != j && digits[j] != 0) {
//                         for (int k = 0; k < _size; ++k) {
//                             if (k != i and k != j) {
//                                 res.emplace_back(digits[j] * 100 + digits[k] * 10 + digits[i]);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         sort(res.begin(), res.end());
//         if (res.size() > 0) {
//             vector<int> ans;
//             int pre = res[0];
//             ans.emplace_back(pre);
//             for (auto it:res) {
//                 if (it != pre) {
//                     ans.emplace_back(it);
//                     pre = it;
//                 }
//             }
//             return ans;
//         }
//         return res;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Week270, Example2) {      // NOLINT
        // int a = 7, b = 17;
        // vector<int> a = {2,10,7,5,4,1,8,6};
        // int b = 3;
        string s;
        int a = 12;
        vector<vector<int>> b =;
        std::tuple<int, vector<int>, vector<vector<int>>> tu;
        auto ans = Solution().findAllPeople(a, b, 9);
        decltype(ans) rightAns = {0};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
