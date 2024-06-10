// 2022-08-29 17:34:33
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
class Codec {
public:

    // Encodes a tree to a single string.
    int l = 0;

    string serialize(TreeNode* root) {
        // printf("2222 \n");
        if (root == nullptr){
            return "";
        }
        string tmp;
        queue<TreeNode*> qu;
        qu.push(root);
        tmp += to_string(root->val);

        while(!qu.empty()){
            auto top = qu.front();
            qu.pop();
            if (top->left != nullptr){
                tmp += ',';
                tmp += to_string(top->left->val);
                qu.push(top->left);
            } else if(!qu.empty() || top->right != nullptr){
                tmp += ",null";
            }
            if (top->right != nullptr){
                tmp += ',';
                tmp += to_string(top->right->val);
                qu.push(top->right);
            } else if(!qu.empty()){
                tmp += ",null";
            }
        }
        int l = 0;
        return tmp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // printf("1111 \n");
        int _size = data.size();
        if (_size == 0) return nullptr;
        int val = getValue(data);
        queue<TreeNode *> qu;
        TreeNode* root = new TreeNode(val);
        qu.push(root);

        while(!qu.empty() && l < _size){
            auto top = qu.front();
            qu.pop();
            val = getValue(data);
            if (val != INT_MAX){
                TreeNode* tmp = new TreeNode(val);
                qu.push(tmp);
                top->left = tmp;
            }

            val = getValue(data);
            if (val != INT_MAX){
                TreeNode* tmp = new TreeNode(val);
                qu.push(tmp);
                top->right = tmp;
            }
        }
        return root;
    }

    int getValue(string& data){
        int r = l;
        int _size = data.size();
        while(r < _size && data[r] != ','){
            r++;
        }
        if (data[l] == 'n'){
            l += 5;
            return INT_MAX;
        }

        // string ss("11");
        string ss(data.begin() + l, data.begin() + r);
        int res = (int)stoi(ss, nullptr, 10);
        l = r + 1;
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(XuLieHuaErChaShuLcof, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        std::string s{"1,2,3,null,null,4,5"};
        auto ans = Solution().deserialize(s);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}