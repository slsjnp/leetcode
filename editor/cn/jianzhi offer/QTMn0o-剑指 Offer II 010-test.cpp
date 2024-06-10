// 2022-03-09 21:47:17
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int _size = nums.size();
        // vector<int> pre(_size + 1, 0);
        unordered_map<int ,int> ma;
        int pre = 0;
        int sum = 0;
        ma[0] = 1;
        for (int i = 0; i < _size; ++i) {
            pre += nums[i];
            if (ma.count(pre - k)){
                sum += ma[pre - k];
            }
            ma[pre]++;
        }
        // for (int i = 0; i < _size; ++i) {
        //     if (ma.count(k - pre)){
        //         sum += ma[k - pre];
        //     }
        //     pre += nums[i];
            // for (int j = i + 1; j <= _size; ++j) {
            //     if (pre[j] - pre[i] == k) sum++;
            // }
        // }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(QTMn0o, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().QTMn0o(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}