// 2021-12-31 15:25:10
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int _size = nums.size();
        map<int, vector<int>> ma;
        for (int i = 0; i < _size; ++i) {
            ma[nums[i]].push_back(i);
        }
        int sum = 0;
        for (int i = 0; i < _size; ++i) {
            for (int j = i + 1; j < _size; ++j) {
                for (int k = j + 1; k < _size; ++k) {
                    int tmp = nums[i] + nums[j] + nums[k];
                    auto it = upper_bound(ma[tmp].begin(), ma[tmp].end(), k);
                    if (ma.count(tmp)){
                        sum += (int)(ma[tmp].end() - it);
                    }
                }
            }
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CountSpecialQuadruplets, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().countSpecialQuadruplets(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}