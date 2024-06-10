//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
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
class DiscountSystem {
public:
    DiscountSystem() {

    }

    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {

    }

    void removeActivity(int actId) {

    }

    int consume(int userId, int cost) {

    }
};

/**
 * Your DiscountSystem object will be instantiated and called as such:
 * DiscountSystem* obj = new DiscountSystem();
 * obj->addActivity(actId,priceLimit,discount,number,userLimit);
 * obj->removeActivity(actId);
 * int param_3 = obj->consume(userId,cost);
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *mid = head;
//         ListNode *r = head;
//         // 找中点
//         while(r != nullptr){
//             mid = mid->next;
//             r = r->next;
//             if (r) r = r->next;
//         }
//         printf(mid->val);
//         // 反转链表
//         r = new ListNode(mid->val);
//         mid = mid->next;
//         ListNode* tmp(0);
//         while(mid){
//             tmp = mid;
//             mid = mid->next;
//             tmp->next = r;
//             r = tmp;
//         }
//
//         // 判断是否符合
//         mid = r;
//         int flag = 1;
//         while (mid && head){
//
//             if (mid->val != head->val){
//                 if (!flag) return false;
//                 flag = 0;
//                 if (mid->next && mid->next->val == head->val){
//                     mid = mid->next;
//                 }
//                 else if (head->next && mid->val == head->next->val){
//                     head = head->next;
//                 }
//                 else{
//                     printf("%d %d ", head->val, mid->val);
//                     return false;
//                 }
//             }
//
//             mid = mid->next;
//             head = head->next;
//         }
//         return true;
//     }
// };




//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week284v1, Example2) {      // NOLINT
        // std::vector<int> nums = {98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821,
        //                          98818, 98821, 98818};

        // vector<vector<int>> nums = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
        vector<vector<int>> nums = {{0,1,1},{2,1,1}};
        auto ans = Solution().minimumWeight(3, nums, 0, 1, 2);
        decltype(ans) rightAns = 9;
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
