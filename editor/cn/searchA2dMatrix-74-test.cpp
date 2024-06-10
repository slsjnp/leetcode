// 2022-01-07 14:24:00
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m - 1;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if (matrix[mid][0] == target){
                return true;
            }
            else if (matrix[mid][0] < target){
                low = mid + 1;
            }
            else if (matrix[mid][0] > target){
                high = mid - 1;
            }
        }
        printf("%d\n", low);
        // if (low == m){
        //     return false;
        // }
        int s = high;
        low = 0;
        high = n - 1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if (matrix[s][mid] == target){
                return true;
            }
            else if (matrix[s][mid] > target){
                low = mid + 1;
            }
            else if (matrix[s][mid] < target){
                high = mid - 1;
            }
        }
        // if (low == n){
            return false;
        // }
        // else{
        //     return true;
        // }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SearchA2dMatrix, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().searchA2dMatrix(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}