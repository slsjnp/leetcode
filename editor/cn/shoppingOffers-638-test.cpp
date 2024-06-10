// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int _size;
    int _spsize;
    vector<int> price;
    vector<vector<int>> special;
    map<vector<int>, int> ma;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price = price;
        this->_size = price.size();
        this->special = special;
        _spsize = special.size();
        int ns = needs.size();

        return dfs(needs);
    }
    int dfs(vector<int> need){
        if (ma.count(need)){
            return ma[need];
        }
        int cost = 0;
        int flag = 1;
        int sum = 0;
        // 计算不买礼包总花费
        for (int j = 0; j < _size; ++j) {
            cost += need[j] * price[j];
        }
        // 买礼包
        for (int i = 0; i < _spsize; ++i) {
            // 能不能买
            for (int j = 0; j < _size; ++j) {
                if (special[i][j] > need[j]){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                // 买一次
                vector<int> tmp= vector<int>(need);
                for (int k = 0; k < _size; ++k) {
                    tmp[k] = need[k] - special[i][k];
                }
                cost = min(cost, special[i][_size] + dfs(tmp));
            }
            flag = 1;
        }
        // 记录最少开支
        ma[need] = cost;
        return cost;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

// void package(){
//     pack[0] = 0;
//     for (int i = 1; i < ns + 1; ++i) {
//         pack[i] = needs[i];
//     }
//     sort(special.begin(), special.end(), cmp);
//
//     for (int i = 1; i < ss; ++i) {
//         // 买礼包
//         int need_min;
//         need_min = pack[0] ? special[i][0] / pack[0] : 0;
//         for (int j = 0; j < special[i].size(); ++j) {
//             if (!pack[j] && special[i][j]){
//                 need_min = 0;
//                 break;
//             }
//             else if (pack[j]){
//                 need_min = min(special[i][j] / pack[i], need_min);
//             }
//         }
//         while(true){
//             cost[i] = min(cost[i - 1] + special[i][ss - 1], cost[i - 1]);
//         }
//
//         // buy none
//     }
// }
// bool cmp(vector<int> a, vector<int> b){
//     int sa = 0, sb = 0;
//     int as = a.size();
//     for (int i = 0; i < as; ++i) {
//         sa += a[i] * price[i];
//         sb += b[i] * price[i];
//     }
//     return sa - a[as - 1] < sb - b[as - 1];
// }

namespace {
    TEST(ShoppingOffers, Example1) {      // NOLINT
        std::vector<int> nums = { 2,5};
        vector<vector<int>> t = {{ 3, 0 ,5} , {1, 2, 10}};
        vector<int> n = {3, 2};
        auto ans = Solution().shoppingOffers(nums, t, n);
        decltype(ans) rightAns = 14;
        ASSERT_EQ(ans, rightAns);
    }
    TEST(ShoppingOffers, Example2) {      // NOLINT
        std::vector<int> nums = { 2,3,4};
        vector<vector<int>> t = {{ 1,1,0,4} , {2,2,1,9}};
        vector<int> n = {1,2, 1};
        auto ans = Solution().shoppingOffers(nums, t, n);
        decltype(ans) rightAns = 11;
        ASSERT_EQ(ans, rightAns);
    }
    TEST(ShoppingOffers, Example3) {      // NOLINT
        std::vector<int> nums = { 6,3,6,9,4,7};
        vector<vector<int>> t = {{1,2,5,3,0,4,29} , {3,1,3,0,2,2,19}};
        vector<int> n = {4,1,5,2,2,4};
        auto ans = Solution().shoppingOffers(nums, t, n);
        decltype(ans) rightAns = 69;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}