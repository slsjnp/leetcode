// 2022-08-27 10:20:02
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int target;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        this->target = target;
        if (root == nullptr){
            return {};
        }
        tmp.push_back(root->val);
        dfs(root, root->val);
        return res;
    }
    void dfs(TreeNode* root, int now){
        if (root->left == nullptr && root->right == nullptr){
            if (now == target){
                res.push_back(tmp);
            }
            return;
        }

        if (root->left != nullptr){
            tmp.push_back(root->left->val);
            dfs(root->left, now + root->left->val);
            tmp.pop_back();
        }
        if (root->right != nullptr){
            tmp.push_back(root->right->val);
            dfs(root->right, now + root->right->val);
            tmp.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ErChaShuZhongHeWeiMouYiZhiDeLuJingLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().erChaShuZhongHeWeiMouYiZhiDeLuJingLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}