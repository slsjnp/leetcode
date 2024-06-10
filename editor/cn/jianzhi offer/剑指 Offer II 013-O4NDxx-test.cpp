// 2022-03-10 17:05:13
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        pre = vector<vector<int>> (m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + matrix[i][j];
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         pre[j + 1][i] = pre[j][i] + matrix[j][i];
        //     }
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2 + 1][col2 + 1] + pre[row1][col1] - pre[row2 + 1][col1] - pre[row1][col2 + 1];

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(O4NDxx, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().O4NDxx(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}