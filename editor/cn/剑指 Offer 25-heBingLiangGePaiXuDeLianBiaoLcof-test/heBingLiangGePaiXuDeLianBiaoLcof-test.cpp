// 2022-08-23 17:50:06
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                res->next = l1;
                l1 = l1->next;
            } else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
            // printf("l1->val: %d",l1->val);
        }
        if (l1){
            res->next = l1;
        }
        if (l2){
            res->next = l2;
        }
        return tmp->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(HeBingLiangGePaiXuDeLianBiaoLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().heBingLiangGePaiXuDeLianBiaoLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}