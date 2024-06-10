//
// Created by sj on 2021/10/31.
//

//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int goal;

    int minimumOperations(vector<int> &nums, int start, int goal) {
        this->goal = goal;
        int size = nums.size();
        // map<int, int> ma;
        // set<int> se;
        queue<int> qu;
        int times = 0;
        int dp[1001];
        for (int i = 0; i < 1001; i++) {
            dp[i] = -1;
            // se.insert(i);
        }

        dp[start] = 1;
        qu.push(start);
        // int flag = 1;
        // for (int i = 0; i < nums.size(); ++i) {
        //     if (start + nums[i] <= 1000 && start + nums[i] >= 0){
        //         qu.push(start + nums[i]);
        //         dp[start + nums[i]] = dp[start] + 1;
        //     }
        //     if (start - nums[i] <= 1000 && start - nums[i] >= 0){
        //         qu.push(start - nums[i]);
        //         dp[start - nums[i]] = dp[start] + 1;
        //     }
        //     if ((start ^ nums[i]) <= 1000 && (start ^ nums[i]) >= 0){
        //         qu.push(start ^ nums[i]);
        //         dp[start ^ nums[i]] = dp[start] + 1;
        //     }
        // }
        while (qu.size() > 0) {
            // dp[start]
            start = qu.front();
            qu.pop();
            for (int i = 0; i < nums.size(); ++i) {
                if (start + nums[i] <= 1000 && start + nums[i] >= 0) {
                    if (dp[start + nums[i]] == -1) {
                        // 没访问过
                        qu.push(start + nums[i]);
                        dp[start + nums[i]] = dp[start] + 1;
                    } else if (dp[start + nums[i]] > dp[start] + 1) {
                        qu.push(start + nums[i]);
                        dp[start + nums[i]] = dp[start] + 1;
                    }
                }
                if (start - nums[i] <= 1000 && start - nums[i] >= 0) {
                    if (dp[start - nums[i]] == -1) {
                        // 没访问过
                        qu.push(start - nums[i]);
                        dp[start - nums[i]] = dp[start] + 1;
                    } else if (dp[start - nums[i]] > dp[start] + 1) {
                        qu.push(start - nums[i]);
                        dp[start - nums[i]] = dp[start] + 1;
                    }
                }
                if ((start ^ nums[i]) <= 1000 && (start ^ nums[i]) >= 0) {
                    if (dp[start ^ nums[i]] == -1) {
                        // 没访问过
                        qu.push(start ^ nums[i]);
                        dp[start ^ nums[i]] = dp[start] + 1;
                    } else if (dp[start ^ nums[i]] > dp[start] + 1) {
                        qu.push(start ^ nums[i]);
                        dp[start ^ nums[i]] = dp[start] + 1;
                    }
                }
            }
        }
        // int min_ = dp[start + nums[0]];
        int min_ = -1;
        int flag = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i] ^ goal;
            if ((nums[i] ^ goal) <= 1000 && (nums[i] ^ goal) >= 0 && dp[nums[i] ^ goal] != -1) {
                if (min_ == -1) {
                    min_ = max(min_, dp[nums[i] ^ goal]);
                } else {
                    min_ = min(min_, dp[nums[i] ^ goal]);
                    // flag = 0;
                }
            }
        }
        // if (start <= 1000 && start >= 0 && dp[start] != -1) min_ = dp[start];
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] + goal) <= 1000 && (nums[i] + goal) >= 0 && dp[nums[i] + goal] != -1) {
                if (min_ == -1) {
                    min_ = max(min_, dp[nums[i] + goal]);
                } else min_ = min(min_, dp[nums[i] + goal]);
            }
            if ((-nums[i] + goal) <= 1000 && (-nums[i] + goal) >= 0 && dp[-nums[i] + goal] != -1) {
                if (min_ == -1) {
                    min_ = max(min_, dp[-nums[i] + goal]);
                } else min_ = min(min_, dp[-nums[i] + goal]);
            }
        }


        return min_;
    }
};
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
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> res;
//         vector<int> tmp;
//         ListNode* t = head;
//         int pre = t->val;
//         t = t->next;
//         int index = 1;
//         while(t && t->next){
//             if ((pre < t->val && t->next->val < t->val) || (pre > t->val && t->next > t->val)){
//                 tmp.push_back(index);
//             }
//             pre = t->val;
//             index++;
//             t = t->next;
//         }
//         if (tmp.size() < 2){
//             return {-1, -1};
//         }
//         sort(tmp.begin(), tmp.end());
//         int min_ = abs(tmp[0] - tmp[1]);
//         pre = tmp[1];
//         for (int i = 2; i<tmp.size(); i++) {
//             min_ = min(min_, abs(tmp[i] - pre));
//             pre = tmp[i];
//         }
//         return {min_, abs(tmp[0] - tmp[tmp.size() - 1])};
//
//     }
// };


//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Shopp, Example2) {      // NOLINT
        std::vector<int> nums = {-45, 77, -52, -97, -24, -73, -39, 42, -32, -54, 67};
        int i = 96;
        int j = 23;
        // string s = "**|**|***|";
        // vector<vector<int>> t = {{ 2, 5} , {5, 9}};
        // vector<int> n = {3, 2};
        auto ans = Solution().minimumOperations(nums, i, j);
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
