// 2021-12-19 21:45:38
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int sum = 0;
        int _size = arr.size();
        for (int i = 0; i < k; ++i) {
            vector<int> dp;
            vector<int> tmp;
            for (int j = i; j < _size; j+=k) {
                tmp.emplace_back(arr[j]);
            }
            for (int t = 0; t < tmp.size(); ++t) {
                auto up = upper_bound(dp.begin(), dp.end(), tmp[t]);
                if (up == dp.end()){
                    dp.emplace_back(tmp[t]);
                }
                else{
                    *up = tmp[t];
                }
            }
            sum += dp.size();
        }
        return _size - sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumOperationsToMakeTheArrayKIncreasing, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().minimumOperationsToMakeTheArrayKIncreasing(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}