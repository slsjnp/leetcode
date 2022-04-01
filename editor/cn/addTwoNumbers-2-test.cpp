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
        ListNode *res = new ListNode();
        ListNode *head = res;
        int tmp;
        int flag = 0;
        while(l1 || l2){
            if (l1 && l2){
                tmp = l1->val + l2->val + flag;
                if (tmp > 9) flag = 1;
                else flag = 0;
                res->next = new ListNode(tmp % 10);
                res = res->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1){
                tmp = l1->val + flag;
                if (tmp > 9) flag = 1;
                else flag = 0;
                res->next = new ListNode(tmp % 10);
                res = res->next;
                l1 = l1->next;
            }
            else if (l2){
                tmp = l2->val + flag;
                if (tmp > 9) flag = 1;
                else flag = 0;
                res->next = new ListNode(tmp % 10);
                res = res->next;
                l2 = l2->next;
            }
        }
        if (flag){
            res->next = new ListNode(1);
        }
        return head->next;
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