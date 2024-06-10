// 2022-08-17 23:05:15
#include <gtest/gtest.h>
#include "../../header.h"

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
class Solution {
public:
    unordered_map<int, int > ma;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int _size = preorder.size();

        for (int i = 0; i < _size; ++i) {
            ma[inorder[i]] = i;
        }
        return build_tree(preorder, 0, 0, _size - 1);
    }
    TreeNode* build_tree(vector<int>& preorder, int root, int in_l, int in_r){
        if (in_l > in_r) {
            return nullptr;
        }
        int pre_index = ma[preorder[root]];
        TreeNode* node = new TreeNode(preorder[root]);
        node->left = build_tree(preorder, root + 1, in_l, pre_index - 1);
        node->right = build_tree(preorder, root + pre_index - in_l + 1, pre_index + 1, in_r);
        return node;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZhongJianErChaShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().zhongJianErChaShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}