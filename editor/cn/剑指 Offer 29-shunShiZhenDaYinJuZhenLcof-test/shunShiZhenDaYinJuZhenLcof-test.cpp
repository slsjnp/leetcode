// 2022-08-24 00:01:12
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<int> res;
        enum dir {right = 0, up, left, down};
        if (m == 1) return matrix[0];
        vector<int> dis = {0, n, 0, m};
        int _size = m * n;
        int x = 0, y = 0;
        int now_dir = right;
        for (int i = 0; i < _size; ++i) {
            res.emplace_back(matrix[y][x]);
            // printf("x: %d, y:%d", y, x);
            switch (now_dir) {
                case right:{
                    if (x + 1 < dis[1]){
                        x++;
                    } else if (y + 1 < dis[3]){
                        dis[2]++;
                        y++;
                        now_dir = up;
                    } else{
                        break;
                    }
                    break;
                }
                case up:{
                    if (y + 1 < dis[3]){
                        y++;
                    } else if (x - 1 >= dis[0]){
                        dis[1]--;
                        x--;
                        now_dir = left;
                    } else{
                        break;
                    }
                    break;
                }
                case left:{
                    if (x - 1 >= dis[0]){
                        x--;
                    } else if (y - 1 >= dis[2]){
                        y--;
                        dis[3]--;
                        now_dir = down;
                    } else{
                        break;
                    }
                    break;
                }
                case down: {
                    if (y - 1 >= dis[2]){
                        y--;
                    } else if (x + 1 <= dis[1]){
                        x++;
                        dis[0]++;
                        now_dir = right;
                    } else{
                        break;
                    }
                    break;
                }
                default :{
                    break;
                }
            }
        }
        return res;

    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ShunShiZhenDaYinJuZhenLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().shunShiZhenDaYinJuZhenLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}