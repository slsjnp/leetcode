// 2021-10-20 17:35:08
#include <gtest/gtest.h>
#include <vector>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int flag = 0;
        ListNode *head = new ListNode();
        ListNode *ans = head;
        int sum;
        while (l1 and l2) {
            sum = l1->val + l2->val + flag;
            if (sum > 9) {
                head->val = sum % 10;
                flag = 1;
            } else {
                head->val = sum;
                flag = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            if(l1 or l2){
                head->next = new ListNode();
                head = head->next;
            }

        }
        while (l1) {
            sum = l1->val + flag;
            if (sum > 9) {
                head->val = sum % 10;
                flag = 1;
            } else {
                head->val = sum;
                flag = 0;
            }
            l1 = l1->next;
            // l2 = l2->next;
            if(l1){
                head->next = new ListNode();
                head = head->next;
            }

        }
        while (l2) {
            sum = l2->val + flag;
            if (sum > 9) {
                head->val = sum % 10;
                flag = 1;
            } else {
                head->val = sum;
                flag = 0;
            }
            l2 = l2->next;
            // l2 = l2->next;
            if(l2){
                head->next = new ListNode();
                head = head->next;
            }

        }
        if(flag){
            head->next = new ListNode();
            head = head->next;
            head->val = 1;
        }
        // else{
        // delete head;
        // }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(AddTwoNumbers, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().addTwoNumbers(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}