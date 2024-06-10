// 2022-12-05 11:33:17
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = 0x3f3f3f3f;
        int min_ = *min_element(baseCosts.begin(), baseCosts.end());
        if (min_ > target){
            return min_;
        }
        vector<bool> dp(target + 5);
        int res = 2 * target - min_;

        // 初始化
        for (auto& it: baseCosts) {
            if (it < target){
                dp[it] = true;
            } else{
                // 最小代价函数
                res = min(res, it);
            }
        }

        // 取值范围类似bfs扩散。
        for (auto& it: toppingCosts) {
            for (int count = 0; count < 2; ++count) {
                for (int i = target; i >= 0; --i) {
                    if (dp[i] && i + it > target){
                        // 若值有效，则取最小代价函数
                        res = min(res, i + it);
                    }
                    if (i - it > 0){
                        // 倒序更新
                        dp[i] = dp[i] | dp[i - it];
                    }
                }
            }
        }

        for (int i = 0; i <= res - target; ++i) {
            if (dp[target - i]){
                return target - i;
            }
        }
        return res;
    }
    // int res = INT_MAX;
    // int sum = 0;
    // int target;
    // int _size;
    // int m;
    // vector<int> top;
    // int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    //     _size = baseCosts.size();
    //     m = toppingCosts.size();
    //     this->target = target;
    //     top = toppingCosts;
    //     for (int i = 0; i < _size; ++i) {
    //         dfs(0, baseCosts[i]);
    //     }
    //     return sum;
    // }
    // void dfs(int l, int now){
    //     if (res > abs(now - target)){
    //         res = abs(now - target);
    //         sum = now;
    //     } else if (res == abs(now - target)){
    //         sum = min(sum, now);
    //     }
    //     if(l < m && now < target){
    //         dfs(l + 1, now);
    //         dfs(l + 1, now + top[l]);
    //         dfs(l + 1, now + top[l] * 2);
    //     }
    // }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ClosestDessertCost, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().closestDessertCost(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}