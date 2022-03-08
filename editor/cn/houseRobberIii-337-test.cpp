// 2022-03-06 18:04:15
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
    int rob(TreeNode* root) {
        vector<int> res(2);
        res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode* root){
        // 0 拿   1 不拿
        if (!root) return {0, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        return {root->val + left[1] + right[1], max(left[0], left[1]) + max(right[0], right[1])};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(HouseRobberIii, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().houseRobberIii(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}