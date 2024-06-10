// 2022-08-24 22:16:48
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        vector<int> tmp;
        if (root == nullptr) return {};
        queue<pair<TreeNode *, int >> qu;
        int level = 0;
        qu.push(pair<TreeNode *, int>{root, 0});
        while (!qu.empty()) {
            auto top = qu.front();
            qu.pop();
            auto node = top.first;
            int l = top.second;
            if (l != level) {
                result.push_back(tmp);
                tmp = vector<int>{node->val};
                level++;
            } else {
                tmp.push_back(node->val);
            }
            if (node->left != nullptr) {
                qu.push(pair<TreeNode *, int>{node->left, l + 1});
            }
            if (node->right != nullptr) {
                qu.push(pair<TreeNode *, int>{node->right, l + 1});
            }
        }
        if (!tmp.empty()){
            result.push_back(tmp);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CongShangDaoXiaDaYinErChaShuIiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().congShangDaoXiaDaYinErChaShuIiLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}