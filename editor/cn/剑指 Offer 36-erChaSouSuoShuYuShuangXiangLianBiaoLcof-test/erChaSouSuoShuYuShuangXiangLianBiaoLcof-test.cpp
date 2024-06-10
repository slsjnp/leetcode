// 2022-08-27 23:01:51
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) return nullptr;
        vector<Node *> res;
        stack<Node *> st;
        // st.push(root);
        Node *tmp = root;
        while (!st.empty() || tmp != nullptr) {
            while (tmp != nullptr) {
                st.push(tmp);
                tmp = tmp->left;
            }
            tmp = st.top();
            st.pop();
            res.push_back(tmp);
            tmp = tmp->right;
        }
        tmp = res.back();
        for (auto &it: res) {
            // printf("%d ", it->val);
            tmp->right = it;
            it->left = tmp;
            tmp = it;
        }
        // Node* h = new Node();
        // h->right = res[0];
        return res[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ErChaSouSuoShuYuShuangXiangLianBiaoLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().erChaSouSuoShuYuShuangXiangLianBiaoLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}