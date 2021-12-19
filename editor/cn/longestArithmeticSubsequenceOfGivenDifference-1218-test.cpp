// 2021-11-05 00:50:10
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int _size = arr.size();
        // 数值  长度
        map<int, int> ma;
        for (int i = 0; i < _size; ++i) {
            if (ma.count(arr[i] - difference)) {
                ma[arr[i]] = ma[arr[i] - difference] + 1;
            } else {
                ma[arr[i]] = 1;
            }
        }
        int _max = 0;
        for (auto i: ma) {
            if (_max < i.second) {
                _max = i.second;
            }
        }
        return _max;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestArithmeticSubsequenceOfGivenDifference, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().longestArithmeticSubsequenceOfGivenDifference(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}