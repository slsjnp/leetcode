// 2022-01-14 16:40:48
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmp;
    int _size;
    int row = 0;
    // int col = 0;
    vector<vector<string>> solveNQueens(int n) {
        _size = n;
        tmp = vector<string> (n, string(n, '.'));
        dfs(0);
        return res;
    }
    void dfs(int pos){
        int i = pos;
        // int j = pos % n;
        if (i == _size){
            res.emplace_back(tmp);
            return;
        }
        int mask = (~row) & ((1 << _size) - 1);

        for (; mask ; mask &= (mask - 1)) {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(mask & (-mask));
            if (check(i, digit)){
                row ^= digitMask;
                tmp[i][digit] = 'Q';
                dfs(pos + 1);
                row ^= digitMask;
                tmp[i][digit] = '.';
            }
        }
    }
    bool check(int i, int j){
        int m = i, n = j;
        for (;i >= 0 and j >= 0;) {
            if (tmp[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        i = m, j = n;
        for (;i >= 0 and j < _size;) {
            if (tmp[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(NQueens, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().nQueens(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}