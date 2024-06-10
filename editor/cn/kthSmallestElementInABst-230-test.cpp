// 2021-10-17 22:48:41
#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    int kthSmallest(TreeNode* root, int k) {
        // 目的 找到第k小
        int ks = 0;
        // 遍历这个树
        TreeNode* t = root;
        // 中序遍历
            //递归
            //非递归
                // 栈 + 算法
        stack<TreeNode *> st;
        int target = 0;
        while (t != nullptr || !st.empty()){
            if (t != nullptr){
                st.push(t);
                t = t->left;
                continue;
            }
            // t为空节点
            t = st.top();
            st.pop();
            // visit
            target++;
            if(target == k){
                ks = t->val;
                break;
            }
            // 指向右
            t = t->right;
        }
        return ks;




            // 判断父节点有没有左孩子，若有，而且没被访问，则指针指向父节点的左孩子,

            // 若左孩子已被访问过，则判断父节点没有右孩子，若有，则访问右孩子，然后指针指向上一个父节点

            // 若父节点没有左孩子，则访问该节点

            //判断父节点没有右孩子，若有，则访问右孩子，然后指针指向上一个父节点

            //若父节点没有右孩子，指针直接指向该节点的上一个父节点

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(KthSmallestElementInABst, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().kthSmallestElementInABst(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}












// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> st;
//         int n=0;
//         TreeNode* t = root;
//         // st.push(root);
//         // t = st.top();
//         // if (t->left != nullptr){
//         //     t = t->left;
//         // }
//         int res=0;
//         while (t != nullptr || st.size()>0) {
//             //  左不为空则 压自己，指向左
//             if (t != nullptr){
//                 st.push(t);
//                 t = t->left;
//             }
//             else {
//                 t = st.top();
//                 st.pop();
//                 n++;
//                 if (n == k){
//                     res = t->val;
//                     break;
//                 }
//                 // st.push(t->right);
//                 t = t->right;
//             }
//         }; // 错在没有考虑出口情况， 栈空但还
//
//         return res;
//     }
// };
