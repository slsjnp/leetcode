// 2022-01-14 22:25:04
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> used;
    vector<vector<int>> ans;
    vector<int> tmp;
    int _size;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // vector<int> res(n);
        _size = nums.size();
        // sum = k;
        used = vector<int> (_size, 0);
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& res, int l){
        // if (tmp.size() + (_size - l + 1) < sum) {
        //     return;
        // }
        ans.emplace_back(tmp);
        for (int i = l; i < _size; ++i) {
            if (i > 0 and res[i] == res[i - 1] and used[i - 1] == 0){
                continue;
            }
            used[i] = 1;
            tmp.emplace_back(res[i]);
            dfs(res, i + 1);
            tmp.pop_back();
            used[i] = 0;
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SubsetsIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().subsetsIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}