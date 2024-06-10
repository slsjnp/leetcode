// 2022-01-08 00:11:39
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m - 1;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                low = mid + 1;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            }
        }
        if (high < 0) { // 防止右边界溢出
            return false;
        }
        int s = high;
        for (int i = 0; i < s; ++i) {
            low = 0;
            high = n - 1;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    low = mid + 1;
                } else if (matrix[i][mid] > target) {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SearchA2dMatrixIi, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().searchA2dMatrixIi(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}