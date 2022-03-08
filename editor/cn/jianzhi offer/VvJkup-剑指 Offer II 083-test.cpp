// 2022-03-05 19:13:51
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<int> vis;
    int _size;

    vector<vector<int>> permute(vector<int> &nums) {
        this->_size = nums.size();
        vis = vector<int>(this->_size, 0);
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&](int l) {
            if (l == _size) {
                res.push_back(tmp);
                return;
            }
            for (int i = 0; i < _size; ++i) {
                if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == 0) continue;
                if (vis[i] == 0) {
                    vis[i] = 1;
                    tmp.push_back(nums[i]);
                    dfs(l + 1);
                    vis[i] = 0;
                    tmp.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }

    // void dfs(vector<int> &nums, int l) {
    //     if (l == _size) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = 0; i < _size; ++i) {
    //         if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == 0) continue;
    //         if (vis[i] == 0) {
    //             vis[i] = 1;
    //             tmp.push_back(nums[i]);
    //             dfs(nums, l + 1);
    //             vis[i] = 0;
    //             tmp.pop_back();
    //         }
    //     }
    // }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(VvJkup, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().VvJkup(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}