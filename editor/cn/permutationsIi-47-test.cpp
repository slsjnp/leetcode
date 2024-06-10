// 2022-01-14 16:28:02
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    // set<vector<int>> se;
    vector<int> used;
    int _size;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        _size = nums.size();
        used = vector<int>(_size, 0);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0);
        return res;
    }

    void dfs(vector<int> &can, int now, int l) {
        if (tmp.size() == _size) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < can.size(); ++i) {
            if (i > 0 and can[i] == can[i - 1] and used[i - 1] == 0) {
                continue;
            }
            if (!used[i]){
                tmp.emplace_back(can[i]);
                used[i] = 1;
                dfs(can, now + can[i], i);
                tmp.pop_back();
                used[i] = 0;
            }
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(PermutationsIi, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().permutationsIi(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}