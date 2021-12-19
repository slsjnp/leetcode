// 2021-11-09 17:27:20
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMinStep(string board, string hand) {
        int b_size = board.length();
        int h_size = hand.length();
        return dfs(board, hand);
    }

    int dfs(string board, string hand, int count = 0) {
        int tmp = count;
        int len = board.length();
        if (board.length() > 2) {
            int pp = board[0];
            int p = board[1];
            do {
                len = board.length();
                for (int i = 2; i < board.length(); ++i) {
                    if (board[i] == p and board[i] == pp) {
                        if (board.length() == 3) {
                            board = "";
                        } else {
                            board = string(board.begin(), board.begin() + i - 2) +
                                    string(board.begin() + i + 1, board.end());
                            // pp = board[0];
                            // p = board[1];
                            break;
                        }
                    } else {
                        pp = p;
                        p = board[i];
                    }
                }
                pp = board[0];
                p = board[1];
            } while (board.length() < len);
        }

        if (board.length() == 0) {
            return count;
        } else if (board.length() <= 2) {
            for (int i = 0; i < hand.length(); ++i) {
                if (hand[i] == board[0]) {
                    board = string(board.begin(), board.begin() + 1) + string(board.begin(), board.begin() + 1) +
                            string(board.begin() + 1, board.end());
                    hand.erase(hand.begin() + i);
                    return dfs(board, hand, count + 1);
                }
            }
        } else {
            for (int i = 1; i < board.length() - 1; ++i) {
                for (int j = 0; j < hand.length(); ++j) {
                    if (board[i] == hand[j]) {
                        // string b = string(board.begin() + i + 1, board.end());
                        string new_board = string(board.begin(), board.begin() + i + 1) + board[i] +
                                           string(board.begin() + i + 1, board.end());
                        string new_hand =
                                string(hand.begin(), hand.begin() + j) + string(hand.begin() + j + 1, hand.end());
                        int a = dfs(new_board, new_hand, count + 1);
                        if (tmp == 0) {
                            tmp = a;
                        }
                        if (a != -1) {
                            tmp = min(tmp, a);
                        }
                        break;
                    }
                }
            }
        }
        return tmp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZumaGame, Example1) {      // NOLINT
        // std::vector<int> nums = {};
        string a = "WWRRBBWW";
        string b = "WRBRW";
        auto ans = Solution().findMinStep(a, b);
        decltype(ans) rightAns = 2;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}