// 2021-12-18 18:12:33
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sum = 0;
    int m_size;
    int n_size;

    int countBattleships(vector<vector<char>> &board) {
        this->m_size = board.size();
        this->n_size = board[0].size();
        vector<uint64_t> bit(8, 0);
        int num;
        // for (int i = 0; i < n_size; ++i) {
        //
        // }
        int pre = 0;
        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < n_size; ++j) {
                num = j / 32;
                if ((bit[num] >> (j % 32) & 1) == 0) {
                    if (board[i][j] == 'X') {
                        // printf("%d", pre);
                        if (!pre) {
                            pre = 1;
                            bit[num] |= 1 << (j % 32);
                        }
                        else{
                            pre++;
                            num = (j - 1) / 32;
                            bit[num] |= 1 << (j - 1) % 32;
                            bit[num] ^= 1 << (j - 1) % 32;
                        }
                    }
                    else{
                        if (pre > 1){
                            sum++;
                        }
                        pre=0;
                    }
                } else {
                    if (board[i][j] == '.') {
                        if (pre > 1) {
                            sum += 1;
                        }
                        pre = 0;
                        sum += 1;
                        bit[num] ^= 1 << (j % 32);
                    }
                    else{
                        if (pre > 1){
                            sum++;
                        }
                        pre = 0;
                    }
                }
            }
            if (pre > 1){
                sum++;
            }
            pre=0;
            printf("bit : %d\n", bit[0]);

            printf("sum : %d\n", sum);
        }
        for (int i = 0; i < 200; ++i) {
            // num = 0;
            // if (i >= 64) {
            num = i / 32;
            // }
            if ((bit[num] >> (i % 32) & 1) == 1){
                sum++;
            }
        }
        if (pre > 1){
            sum++;
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BattleshipsInABoard, Example1) {      // NOLINT
        // std::vector<int> nums = {};
        vector<vector<char>> nums = {{'X','.','.','X','.','.','.','.','.','.'},{'.','.','X','.','X','.','X','X','X','X'}};
        auto ans = Solution().countBattleships(nums);
        decltype(ans) rightAns =5;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}