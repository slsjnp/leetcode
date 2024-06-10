// 2021-10-20 08:56:52
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ve;
        for (auto f : grid) {
            for (auto s: f) {
                ve.push_back(s);
            }
        }
        sort(ve.begin(), ve.end());
        int mid = ve[ve.size()/2];
        int sum = 0;
        for (int i = 0; i < ve.size(); ++i) {
            if (abs(ve[i] - mid) % x != 0){
                return -1;
            }
            else{
                sum += abs(ve[i] - mid) / x;
            }
        }
        return sum;
        // int size = grid.size();
        // if (size * grid[0].size() == 1)return 0;
        // int i_min = grid[0][0];
        // int i_max = grid[0][0];
        // for (auto s: grid) {
        //     for (auto item: s) {
        //         if (item < i_min){
        //             i_min = item;
        //         }
        //         if (item > i_max){
        //             i_max = item;
        //         }
        //     }
        // }
        // if ((i_max-i_min) % x != 0){
        //     return -1;
        // }
        // int sum=0;
        // int flag = 0;
        // // int mean = x * ((i_max - i_min) / x / 2 + 1);
        // for (auto s: grid) {
        //     for (auto item: s) {
        //         if (i_max - item > item - i_min){
        //             sum += (i_max - item);
        //             flag++;
        //         }
        //         else{
        //             sum += (item - i_min);
        //             flag--;
        //         }
        //         // sum += max(item - i_min, i_max - item);
        //         // sum += abs(item - mean);
        //     }
        // }
        // sum -= (2 * (i_max - i_min));
        // if (flag < 0){
        //     flag = 1 - flag;
        // }
        // else if (flag > 0){
        //     flag = flag + 1;
        // }
        // sum -= abs(flag * x);
        // return sum / x;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumOperationsToMakeAUniValueGrid, Example1) {      // NOLINT
        std::vector<vector<int>> nums = {{529,529,989}, {989,529,345}, {989,805,69}};
        int k = 92;
        auto ans = Solution().minOperations(nums, k);
        decltype(ans) rightAns = 12;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}