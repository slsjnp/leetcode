// 2021-12-30 18:57:48
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
    bool dfs(TreeNode* p, TreeNode* q){
        if (p == nullptr and q == nullptr){
            return true;
        }
        if (p == nullptr or q == nullptr){
            return false;
        }
        if (p->val != q->val){
            return false;
        }
        return dfs(p->left, q->left) and dfs(p->right, q->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SameTree, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().sameTree(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}