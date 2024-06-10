// 2022-08-23 17:29:27
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* r = head;
        ListNode* l = head;
        for (int i = 0; i < k && r != nullptr; ++i) {
            r = r->next;
        }
        while(r != nullptr){
            l = l->next;
            r = r->next;
        }
        return l;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LianBiaoZhongDaoShuDiKgeJieDianLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().lianBiaoZhongDaoShuDiKgeJieDianLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}