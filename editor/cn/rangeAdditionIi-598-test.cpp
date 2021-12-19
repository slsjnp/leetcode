// 2021-11-07 22:39:20
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int _size = ops.size();
        if (!_size){
            return m * n;
        }
        int a_min = ops[0][0], b_min = ops[0][1];

        for (int i = 1; i < _size; ++i) {
            a_min = min(a_min, ops[i][0]);
            b_min = min(b_min, ops[i][1]);
        }
        return a_min * b_min;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RangeAdditionIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().rangeAdditionIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}