// 2022-01-19 21:27:22
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
    vector<TreeNode*> generateTrees(int n) {
        if (!n){
            return {nullptr};
        }
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int l, int r){
        // flag == 1 , r => right;
        if (l > r){
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> leftTrees = dfs(l, i - 1);
            vector<TreeNode*> rightTrees = dfs(i + 1, r);

            for (auto& left: leftTrees) {
                for (auto& right: rightTrees) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(UniqueBinarySearchTreesIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().uniqueBinarySearchTreesIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}