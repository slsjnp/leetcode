// 2022-01-11 22:23:57
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
class Solution {
public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
        int _size = blocked.size();
        unordered_set<vector<int>, VectorHash> se;
        for (int i = 0; i < _size; ++i) {
            se.insert(blocked[i]);
        }
        deque<vector<int>> qu;
        qu.push_back(source);
        int i = 0;
        while (!qu.empty()) {
            auto it = qu.front();
            printf("size :%d\n",qu.size());
            qu.pop_front();
            i++;
            if (it[0] == target[0] and it[1] == target[1] or i > 200) {
                return true;
            }

            for (auto t: vector<vector<int>> {{0, 1}, {1, 0},{ 0, -1 }, { -1, 0 }}) {
                int x = it[0] + t[0];
                int y = it[1] + t[1];
                printf("x: %d , y: %d\n", x, y);
                if (x < 1000000 and x >= 0 and y < 1000000 and y >= 0 and se.count(vector<int> {x, y}) == 0){
                    qu.push_back(vector<int> {x, y});
                    se.insert(vector<int> {x, y});
                }
            }
        }
        return false;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(EscapeALargeMaze, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().escapeALargeMaze(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}