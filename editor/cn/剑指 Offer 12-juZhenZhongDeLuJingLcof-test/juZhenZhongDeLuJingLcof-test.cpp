// 2022-08-22 22:28:56
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int** vis;
    string tmp;
    vector<vector<char>> board;
    int m, n;
    string word;
    vector<vector<int>> dis {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<pair<int, int>> candidate;
        this->word = word;
        vis = (int **)malloc(sizeof(int *) * m);
        for (int i = 0; i < m; ++i) {
            vis[i] = (int *) malloc(sizeof(int) * n);
            for (int j = 0; j < n; ++j) {
                vis[i][j] = 0;
                if (board[i][j] == word[0]){
                    candidate.emplace_back(pair<int, int>{i, j});
                }
            }
        }
        this->board = board;
        int candidate_size = candidate.size();
        for (int i = 0; i < candidate_size; ++i) {
            vis[candidate[i].first][candidate[i].second] = 1;
            if (exist_find(candidate[i])){
                return true;
            }
            vis[candidate[i].first][candidate[i].second] = 0;
        }
        return false;
    }
    bool exist_find(pair<int, int> xy, int l = 1){
        int x = xy.first;
        int y = xy.second;
        if (l == word.size()){
            return true;
        }
        for(auto& offset: dis){
            int xx = offset[0] + x;
            int yy = offset[1] + y;
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && vis[xx][yy] != 1 && board[xx][yy] == word[l]){
                vis[xx][yy] = 1;
                if (exist_find(pair<int, int>{xx, yy}, l + 1)){
                    return true;
                }
                vis[xx][yy] = 0;
            }
        }
        return false;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(JuZhenZhongDeLuJingLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().juZhenZhongDeLuJingLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}