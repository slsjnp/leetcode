// 2022-03-18 23:43:22
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)return head;
        ListNode* h = head;
        head = head->next;
        h->next = nullptr;
        if (head == nullptr) return h;
        ListNode* tmp = head;
        head = head->next;
        tmp->next = h;
        h = tmp;
        while(head){
            tmp = head;
            head = head->next;
            tmp->next = h;
            h = tmp;
        }
        return h;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ReverseLinkedList, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().reverseLinkedList(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}