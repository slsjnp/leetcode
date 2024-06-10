// 2022-01-14 21:20:16
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string tmp;
    int m;
    int n;
    string target;
    vector<vector<int>> vis;
    vector<vector<int>> dir = {{0,  1},
                               {1,  0},
                               {0,  -1},
                               {-1, 0}};

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        if (m * n < word.size()) return false;
        target = word;
        unordered_set<char> se;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (se.count(board[i][j]) == 0) {
                    se.insert(board[i][j]);
                }
            }
        }
        for (int i = 0; i < word.size(); ++i) {
            if (se.count(word[i]) == 0) {
                return false;
            }
        }
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (dfs(board, i, j, 1)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int l) {
        if (l == target.size()) {
            return true;
        }
        // for (auto it: dir) {
        for (int k = 0; k < 4; ++k) {
            auto it = dir[k];
            if (k > 0 and i + it[0] >= 0 and i + it[0] < m and j + it[1] >= 0 and j + it[1] < n and
            i + dir[k-1][0] >= 0 and i + dir[k-1][0] < m and j + dir[k-1][1] >= 0 and j + dir[k-1][1] < n and
                board[] vis[i + it[0]][j + it[1]] == 0)
                if (i + it[0] >= 0 and i + it[0] < m and j + it[1] >= 0 and j + it[1] < n and
                    !vis[i + it[0]][j + it[1]] and board[i + it[0]][j + it[1]] == target[l]) {
                    vis[i + it[0]][j + it[1]] = 1;
                    if (dfs(board, i + it[0], j + it[1], l + 1)) return true;
                    vis[i + it[0]][j + it[1]] = 0;
                }
        }
        return false;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(WordSearch, Example1) {      // NOLINT
        std::vector<vector<char>> nums = {{'a', 'a'},
                                          {'A', 'A'}};
        auto ans = Solution().exist(nums, "aaa");
        decltype(ans) rightAns = false;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}