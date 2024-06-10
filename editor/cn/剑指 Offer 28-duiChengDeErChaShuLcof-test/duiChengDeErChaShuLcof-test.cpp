// 2022-08-23 23:33:49
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
    bool check(TreeNode* p, TreeNode* q){
        if (!p && !q){
            return true;
        }
        if (!p || !q){
            return false;
        }
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DuiChengDeErChaShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().duiChengDeErChaShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}