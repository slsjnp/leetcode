// 2022-03-09 22:30:45
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int _size = nums.size();
        // vector<int> pre(_size + 1 , 0);
        unordered_map<int, int> ma;
        int sum = 0;
        int pre = 0;
        ma[0] = -1;
        for (int i = 0; i < _size; ++i) {
            // pre += nums[i];
            if (nums[i] == 1) pre++;
            else pre--;
            if (ma.count(pre)){
                sum = max(sum, i - ma[pre]);
            }
            else{
                ma[pre] = i;
            }
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(A1NYOS, Example1) {      // NOLINT
        std::vector<int> nums = { 0 };
        auto ans = Solution().findMaxLength(nums);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}