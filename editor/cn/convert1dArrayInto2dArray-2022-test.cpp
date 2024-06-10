// 2022-01-01 23:41:34
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int _size = original.size();
        if (_size != m * n){
            return {};
        }
        vector<vector<int>> res(m, vector<int> (n));
        int k = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = original[k++];
            }
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Convert1dArrayInto2dArray, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().convert1dArrayInto2dArray(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}