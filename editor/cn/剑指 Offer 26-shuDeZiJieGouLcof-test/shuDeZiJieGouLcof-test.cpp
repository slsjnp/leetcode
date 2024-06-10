// 2022-08-23 18:30:44
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        TreeNode* root = A;
        if (B == nullptr) return false;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* tmp = qu.front();
            qu.pop();
            if (tmp->val == B->val && check(tmp, B)){
                return true;
            }
            if (tmp->left != nullptr){
                qu.push(tmp->left);
            }
            if (tmp->right != nullptr){
                qu.push(tmp->right);
            }
        }
        return false;
    }
    bool check(TreeNode* a, TreeNode* b){
        if (b != nullptr && a != nullptr && a->val == b->val){
            return check(a->left, b->left) & check(a->right, b->right);
        }
        if (b == nullptr) return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ShuDeZiJieGouLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().shuDeZiJieGouLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}