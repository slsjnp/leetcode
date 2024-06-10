// 2022-08-24 21:49:28
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return {};
        queue<TreeNode* >qu;
        qu.push(root);
        while (!qu.empty()){
            auto top = qu.front();
            qu.pop();
            res.push_back(top->val);
            if (top->left != nullptr){
                qu.push(top->left);
            }
            if (top->right != nullptr){
                qu.push(top->right);
            }
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CongShangDaoXiaDaYinErChaShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().congShangDaoXiaDaYinErChaShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}