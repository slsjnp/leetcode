// 2022-02-15 11:40:39
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> mmax, nmax;
        for (int i = 0; i < n; ++i) {
            mmax.push_back(std::min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin());
        }
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            int max_ = 0;
            int pos = 0;
            for (int j = 0; j < n; ++j) {
                // max_ = max(max_, matrix[j][i]);
                if (max_ < matrix[j][i]) {
                    max_ = matrix[j][i];
                    pos = j;
                }
            }
            // nmax.push_back(pos);
            if (i == mmax[pos]) {
                res.push_back(matrix[pos][i]);
            }
        }

        return res;

    }

};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LuckyNumbersInAMatrix, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().luckyNumbersInAMatrix(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}