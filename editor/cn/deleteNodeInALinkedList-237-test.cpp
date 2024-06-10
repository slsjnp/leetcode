// 2021-11-02 00:13:48
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *t = node;
        t = t->next;
        node->val = t->val;
        node->next = t->next;
        // free(t);
        delete t;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DeleteNodeInALinkedList, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().deleteNodeInALinkedList(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}