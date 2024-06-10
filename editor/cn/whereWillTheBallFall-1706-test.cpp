// 2022-02-24 22:53:11
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int l = 0;
            int c = i;
            int flag = grid[l][c];
            while (l < m and ((grid[l][c] == 1 and n > c + 1 and c >= 0 and grid[l][c] == grid[l][c + 1]) or
                             (grid[l][c] == -1 and c > 0 and c < n and grid[l][c] == grid[l][c - 1]))) {
                // printf("%d %d\n", l, c);
                c += grid[l][c];
                flag =
                l++;
            }
            // printf("d dn");
            if (l == m) {
                res.push_back(c);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(WhereWillTheBallFall, Example1) {      // NOLINT
        std::vector<vector<int>> nums = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
        auto ans = Solution().findBall(nums);
        decltype(ans) rightAns ={1};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}