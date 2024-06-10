// 2022-01-21 22:43:53
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
    void recoverTree(TreeNode *root) {
        stack<TreeNode *> st;
        TreeNode *t = root;
        // int pre = INT_MIN;

        TreeNode *tmp = root;
        while (tmp->left) {
            tmp = tmp->left;
        }
        // int pre = tmp->left;
        TreeNode *pre = tmp;

        vector<TreeNode *> res;
        int flag = 0;
        while (t != nullptr or !st.empty()) {
            while (t != nullptr) {
                st.push(t);
                t = t->left;
            }
            t = st.top();
            st.pop();
            if (flag) {
                if (t->val <= pre->val) {
                    // return false;
                    res.push_back(pre);
                    res.push_back(t);
                    // int _t = t->val;
                    // t->val = pre->val;
                    // pre->val = _t;
                }
            }
            flag = 1;
            pre = t;
            // if (t->left and t->left->val >= t->val) return false;
            // if (t->right and t->right->val <= t->val) return false;
            t = t->right;
        }
        // res[0] // pre
        // res[1] // now
        // res[2] // pre
        // res[3] // next
        for (int j = 3; j > 0; ++j) {
            for (int i = 1; i < 4; ++i) {
                if (res[i]->val > res[i + 1]->val) {
                    swap(res[i]->val, res[i + 1]->val);
                }
            }
        }
        // return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RecoverBinarySearchTree, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().recoverBinarySearchTree(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}