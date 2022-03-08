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
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int _size = nums.size();
        // res.push_back(nums[0]);
        // int res_size = res.size();
        vector<int> res = check(nums);
        while (_size != (int)res.size()){
            nums = res;
            _size = nums.size();
            res = check(res);
        }

        return res;
    }
    vector<int> check(vector<int>& nums){
        vector<int> res;
        res.push_back(nums[0]);
        int _size = nums.size();
        for (int i = 1; i < _size; ++i) {
            unordered_set<int> se;
            int now = res.back();
            while (!se.count(nums[i]) && gcd(nums[i], now) > 1){
                se.insert(nums[i]);
                now = max_time(nums[i], now);
                i++;
            }
            res.back() = now;
            // else{
                res.push_back(nums[i]);
            // }
        }
        return res;
    }
    int gcd(int a, int b){
        while (a && b){
            if (a > b) a %= b;
            else b %= a;
        }
        return max(a, b);
    }
    int max_time(int a, int b){
        // long long sum = (long long)a * b;
        // printf("%d %d %d %d\n", a, b, sum, gcd(sum, a) * gcd(sum, b));
        return (a / gcd(b, a) * b);
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
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         TreeNode* root;
//         unordered_map<int ,pair<int, int> > ma;
//         int _size = descriptions.size();
//         vector<int> vis(_size, 0);
//         for (int i = 0; i < _size; ++i) {
//             vis[descriptions[i][1]]++;
//             if (descriptions[i][2] == 1){
//                 if (ma.count(descriptions[i][0]) == 0){
//                     ma[descriptions[i][0]] = pair<int, int>(descriptions[i][1], -1);
//                 }
//                 else{
//                     ma[descriptions[i][0]].first = descriptions[i][1];
//                 }
//             }
//             else{
//                 if (ma.count(descriptions[i][0]) == 0){
//                     ma[descriptions[i][0]] = pair<int, int>(-1, descriptions[i][1]);
//                 }
//                 else{
//                     ma[descriptions[i][0]].second = descriptions[i][1];
//                 }
//             }
//         }
//         for (int i = 0; i < _size; ++i) {
//             if (vis[i] == 0){
//                 root = new TreeNode(ma[i].first);
//                 break;
//             }
//         }
//         queue<TreeNode*> qu;
//         qu.push(root);
//         while(!qu.empty()){
//             auto it = qu.front();
//             qu.pop();
//             if (ma.count(it->val) == 0){
//                 continue;
//             }
//             auto pa = ma[it->val];
//             if (pa.first != -1){
//                 it->left = new TreeNode(pa.first);
//                 qu.push(it->left);
//             }
//             if (pa.second != - 1){
//                 it->right = new TreeNode(pa.second);
//                 qu.push(it->right);
//             }
//         }
//         return root;
//     }
// };
// class Solution {
// public:
//     long long minimalKSum(vector<int> &nums, int k) {
//         long long sum = 0;
//         sort(nums.begin(), nums.end());
//         int _size = nums.size();
//         int times = 0;
//         if(nums[0] > 1){
//             int start = 1;
//             long long tmp = min(nums[0] - 1, k + start - 1);
//             sum += (long long)(start + tmp - times - 1 + start) * (long long)((tmp - times) / 2);
//             if ((tmp - times) % 2 == 1) sum += (long long)start + (tmp - times) / 2;
//             times += tmp;
//         }
//         for (int i = 0; i < _size - 1; ++i) {
//             if (nums[i + 1] - nums[i] > 0) {
//                 int start = nums[i] + 1;
//                 while (start < nums[i + 1] && times < k) {
//                     sum += start;
//                     start++;
//                     times++;
//                 }
//             }
//         }
//         if (times < k) {
//             long long start = nums[_size - 1] + 1;
//             sum += (long long)(start + k - times - 1 + start) * (long long)((k - times) / 2);
//             if ((k - times) % 2 == 1) sum += (long long)start + (k - times) / 2;
//             // while (times < k) {
//             //     sum += start;
//             //     start++;
//             //     times++;
//             // }
//         }
//         return sum;
//     }
// };
//
// [1]
// 1000000000

// class Solution {
// public:
//     vector<string> cellsInRange(string s) {
//         vector<string> res;
//         int _size = s.size();
//         char a,b;
//         string x,y;
//         a = s[0];
//         for (int i = 1; i < _size; ++i) {
//             int sum;
//             string tmp;
//             while(i != ':'){
//                 tmp += s[i];
//                 i++;
//             }
//             x = tmp;
//             tmp = "";
//             i++;
//             b = s[i];
//             i++;
//             while(i < _size){
//                 tmp += s[i];
//                 i++;
//             }
//             y = tmp;
//         }
//         // sscanf(s, "%s:%s",&a,&x,&b,&y);
//
//         for (int j = a-'A'; j <= b-'A'; ++j) {
//             for (int i = stoi(x); i <= stoi(y); ++i) {
//                 res.push_back((char)(j + 'A') + to_string(i));
//             }
//         }
//         return res;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week280, Example2) {      // NOLINT
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
