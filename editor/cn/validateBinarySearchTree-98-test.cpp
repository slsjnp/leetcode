// 2022-01-21 14:10:04
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* t = root;
        // int pre = INT_MIN;

        TreeNode* tmp = root;
        while(tmp->left){
            tmp = tmp->left;
        }
        int pre = tmp->val;
        // vector<TreeNode*> res;
        int flag = 0;
        while(t != nullptr or !st.empty()){
            while(t != nullptr){
                st.push(t);
                t = t->left;
            }
            t = st.top();
            st.pop();
            if (flag){
                if (t->val <= pre){
                    return false;
                }
            }
            flag = 1;

            pre = t->val;
            // if (t->left and t->left->val >= t->val) return false;
            // if (t->right and t->right->val <= t->val) return false;
            t = t->right;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ValidateBinarySearchTree, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().validateBinarySearchTree(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}