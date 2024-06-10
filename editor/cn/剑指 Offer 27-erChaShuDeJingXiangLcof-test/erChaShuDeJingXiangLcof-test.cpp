// 2022-08-23 22:40:29
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* mirrorTree(TreeNode* root) {
//         if (root == nullptr) {
//             return nullptr;
//         }
//         TreeNode* left = mirrorTree(root->left);
//         TreeNode* right = mirrorTree(root->right);
//         root->left = right;
//         root->right = left;
//         return root;
//     }
// };

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        vector<vector<TreeNode *>> res;
        queue<pair<TreeNode *, int>> qu;
        qu.push(pair<TreeNode *, int>{root, 0});
        int level = 0;
        vector<TreeNode*> tmp_ve;
        while (!qu.empty()) {
            TreeNode *tmp = qu.front().first;
            int l = qu.front().second;
            qu.pop();
            if (l > level){
                res.push_back(tmp_ve);
                tmp_ve = vector<TreeNode* > {tmp};
                level = l;
            } else{
                tmp_ve.push_back(tmp);
            }
            if (tmp != nullptr) {
                qu.push(pair<TreeNode *, int>{tmp->left, l+1});
            }
            if (tmp != nullptr) {
                qu.push(pair<TreeNode *, int>{tmp->right, l + 1});
            }
        }
        for (auto& it: res){
            int l = 0;
            int r = it.size() - 1;
            while(l < r){
                swap_(it[l], it[r]);
                l++;
                r--;
            }
        }
        return root;
    }
    void swap_(TreeNode* a, TreeNode* b){
        TreeNode* tmp = new TreeNode(0);
        tmp->val = a->val;
        tmp->left = a->left;
        tmp->right = a->right;
        a->val = b->val;
        a->left = b->left;
        a->right = b->right;
        b->val = tmp->val;
        b->left = tmp->left;
        b->right = tmp->right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ErChaShuDeJingXiangLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().erChaShuDeJingXiangLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}