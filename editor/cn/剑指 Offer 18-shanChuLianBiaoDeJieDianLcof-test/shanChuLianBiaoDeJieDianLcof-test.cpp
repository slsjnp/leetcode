// 2022-08-23 11:07:05
#include <gtest/gtest.h>
#include "../header.h"

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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* res = head;
        if (head->val == val){
            return head->next;
        }
        while(head->next != nullptr){
            if (head->next->val == val){
                head->next = head->next->next;
                return res;
            }
            head = head->next;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ShanChuLianBiaoDeJieDianLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().shanChuLianBiaoDeJieDianLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}