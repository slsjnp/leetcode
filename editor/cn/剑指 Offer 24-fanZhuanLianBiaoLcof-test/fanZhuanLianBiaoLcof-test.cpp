// 2022-08-23 17:33:35
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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = head;
        if (tmp == nullptr) return nullptr;
        ListNode* l = tmp->next;
        if (l == nullptr){
            return tmp;
        }
        ListNode* r = l->next;
        if (r == nullptr){
            l->next = tmp;
            tmp->next = nullptr;
        }
        tmp->next = nullptr;
        while(r != nullptr){
            l->next = tmp;
            tmp = l;
            l = r;
            r = r->next;
        }
        l->next = tmp;
        return l;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FanZhuanLianBiaoLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().fanZhuanLianBiaoLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}