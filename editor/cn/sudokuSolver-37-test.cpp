// 2022-01-14 00:43:52
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // vector<vector<char>> res;
    vector<pair<int, int>> spaces;
    int row[9];
    int col[9];
    int block[3][3];
    int _size;

    void solveSudoku(vector<vector<char>> &board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        // res = board;
        _size = board.size();
        for (int i = 0; i < _size; ++i) {
            for (int j = 0; j < _size; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                } else {
                    int digit = board[i][j] - '0' - 1;
                    filp(i, j, digit);
                }
            }
        }
        dfs(board, 0);
        // board = res;
    }
    void filp(int i, int j, int digit) {
        row[i] ^= 1 << digit;
        col[j] ^= 1 << digit;
        block[i / 3][j / 3] ^= 1 << digit;
    }

    bool dfs(vector<vector<char>>& res, int pos) {
        auto[i, j] = spaces[pos];

        if (pos == spaces.size()) {
            return true;
        }
        int mask = ~(row[i] | col[j] | block[i / 3][j / 3]) & 0x1ff;
        for (; mask; mask &=(mask - 1)) {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask); // __builtin_ctz 返回数值末尾0的个数
            res[i][j] = digit + '0' + 1;
            // if (((row[i] | col[j] | block[i / 3][j / 3]) & (1 << digit)) == 0) {
            filp(i, j, digit);
            if (dfs(res, pos + 1)) return true;
            filp(i, j, digit);
            res[i][j] = '.';
            // }
        }
        return false;
    }
};
// class Solution {
// public:
//     vector<vector<char>> res;
//     vector<pair<int, int>> spaces;
//     int row[9];
//     int col[9];
//     int block[3][3];
//     int _size;
//
//     void solveSudoku(vector<vector<char>> &board) {
//         memset(row, 0, sizeof(row));
//         memset(col, 0, sizeof(col));
//         memset(block, 0, sizeof(block));
//         res = board;
//         _size = board.size();
//         for (int i = 0; i < _size; ++i) {
//             for (int j = 0; j < _size; ++j) {
//                 if (board[i][j] == '.') {
//                     spaces.emplace_back(i, j);
//                 } else {
//                     int digit = board[i][j] - '0' - 1;
//                     filp(i, j, digit);
//                 }
//             }
//         }
//         dfs(0);
//         board = res;
//     }
//     void filp(int i, int j, int digit) {
//         row[i] ^= 1 << digit;
//         col[j] ^= 1 << digit;
//         block[i / 3][j / 3] ^= 1 << digit;
//     }
//
//     bool dfs(int pos) {
//         auto[i, j] = spaces[pos];
//
//         if (pos == spaces.size()) {
//             return true;
//         }
//         int mask = ~(row[i] | col[j] | block[i / 3][j / 3]) & 0x1ff;
//         for (; mask; mask &=(mask - 1)) {
//             int digitMask = mask & (-mask);
//             int digit = __builtin_ctz(digitMask) // __builtin_ctz 返回数值末尾0的个数
//             res[i][j] = digit + '0' + 1;
//             // if (((row[i] | col[j] | block[i / 3][j / 3]) & (1 << digit)) == 0) {
//                 filp(i, j, digit);
//                 if (dfs(pos + 1)) return true;
//                 filp(i, j, digit);
//                 res[i][j] = '.';
//             // }
//         }
//         return false;
//     }
// };




//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SudokuSolver, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().sudokuSolver(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}