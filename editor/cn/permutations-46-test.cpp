// 2022-01-14 16:10:56
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    // set<vector<int>> se;
    int _size;
    vector<int> used;

    vector<vector<int>> permute(vector<int> &nums) {
        _size = nums.size();
        used = vector<int> (_size, 0);
        dfs(nums, -1);
        return res;
    }


    void dfs(vector<int> &can, int l) {
        if (tmp.size() == _size) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < can.size(); ++i) {
            // if (i != l) {
            if (!used[i]){
                used[i] = 1;
                tmp.emplace_back(can[i]);
                dfs(can, i);
                tmp.pop_back();
                used[i] = 0;
                // l++;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Permutations, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().permutations(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}