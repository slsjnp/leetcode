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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// class Solution {
// public:
//     vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
//         vector<int> ma(n + 2, -1);
//         int boss1 = n;
//         int boss2 = n + 1;
//         for (auto it: restrictions) {
//             if(it[0] != -1){
//
//             }
//         }
//     }
// };
// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         int _size = encodedText.size();
//         int cols = _size / rows;
//         if (_size == 0){
//             return encodedText;
//         }
//         vector<vector<char>> ma(rows, vector<char>(cols, ' '));
//         int ind = 0;
//         for (int i = 0; i < rows; ++i) {
//             for (int j = 0; j < cols; ++j) {
//                 ma[i][j] = encodedText[ind];
//                 ind++;
//             }
//         }
//         string res;
//         for (int i = 0; i < cols; ++i) {
//             ind = i;
//             for (int j = 0; j < rows; ++j) {
//                 if (ind ==cols){
//                     break;
//                 }
//                 res.push_back(ma[j][ind]);
//                 ind++;
//             }
//         }
//         ind = res.size() - 1;
//         while(res[ind] == ' ') ind--;
//         return string(res.begin(), res.begin() + 1 +ind);
//     }
// };
class Solution {
public:
    typedef LeetCode::ListNode ListNode;
    ListNode* tmp;
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int _size = 0;
        tmp = head;
        // 遍历计算长度
        while (tmp != nullptr){
            _size++;
            tmp = tmp->next;
        }
        // 单节点返回
        if (_size == 1){
            return head;
        }
        // 遍历
        tmp = head;
        int i = 2;
        _size--;
        while (_size - i > 0){
            // 偶节点反转
            if ((i & 1) == 0){
                ListNode* hold = tmp;
                hold->next = reverse_n(i);
            }
            // 奇数节点不变
            else{
                int j = i;
                while(j > 0){
                    tmp = tmp->next;
                    j--;
                }
            }
            // 剩余节点数
            _size -= i;
            i++;
        }
        // 最后一组反转
        if ((_size & 1) == 0){
            ListNode* hold = tmp;
            hold->next = reverse_n(_size);
        }
        return head;
    }
    ListNode* reverse_n(int i){
        tmp = tmp->next;
        // 当前头节点
        ListNode* next;
        // 记录尾节点
        ListNode* pre;
        pre = tmp;
        next = tmp;
        tmp = tmp->next;
        i--;
        // 临时变量
        ListNode* now;
        for (int j = 0; j < i; ++j) {
            now = tmp;
            tmp = tmp->next;
            now->next = next;
            next = now;
        }
        pre->next = tmp;
        tmp = pre;
        return next;
    }
};

// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int _size = tickets.size();
//         int times = 0;
//         while(tickets[k] > 0){
//             for (int i = 0; i < _size; ++i) {
//                 if (tickets[i] > 0){
//                     tickets[i]--;
//                     times++;
//                     if (i == k && tickets[i] == 0){
//                         return times;
//                     }
//                 }
//             }
//         }
//         return times;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(NextI12, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        string a = "iveo    eed   l te   olc";
        auto ans = Solution().decodeCiphertext(a, 4);
        decltype(ans) rightAns = "i love leetcode";
        ASSERT_EQ(ans, rightAns);
    }
    // TEST(Shopp, Example2) {      // NOLINT

    // vector<vector<int>> t = {{ 1, 5,3} , {1,5,1}, {6,6,5}};
    // LeetCode::List a;

    // LeetCode::List a{5,2,6,3,9,1,7,3,8,4};
    // auto ans = Solution().reverseEvenLengthGroups(a.head);
    // bool rightAns = LeetCode::is_same_list(a.head, LeetCode::List({5,6,2,3,9,1,4,8,3,7}).head);
    // LeetCode::print_list(ans);
    // ASSERT_EQ(ture, rightAns);
    // }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
