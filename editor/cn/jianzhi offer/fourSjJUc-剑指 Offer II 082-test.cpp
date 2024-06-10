// 2022-03-05 17:57:34
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    // vector<int> vis;
    int target;
    int _size;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        this->_size = candidates.size();
        // vis = vector<int> (this->_size, 0);
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return res;
    }
    void dfs(vector<int>& c, int l, int sum){
        if (l > _size || sum > target){
            return;
        }
        if (sum == target){
            res.push_back(tmp);
            return;
        }
        for (int i = l; i < _size; ++i) {
            // if (i > 0 && c[i] == c[i - 1] && vis[i - 1] == 0){
            //     continue;
            // }
            if (i - 1 >= l && c[i - 1] == c[i]) continue;
            if (sum + c[i] <= target){
                tmp.push_back(c[i]);
                // vis[i] = 1;
                dfs(c, i + 1, sum + c[i]);
                tmp.pop_back();
                // vis[i] = 0;
            }
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FourSjJUc, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().fourSjJUc(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}