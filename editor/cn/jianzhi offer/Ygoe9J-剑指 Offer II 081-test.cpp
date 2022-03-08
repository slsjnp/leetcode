// 2022-03-05 17:46:10
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    int target;
    int _size;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        this._size = c.size();
        this->target = target;
        sort(c.begin(), c.end());
        dfs(c, 0, 0)
        return res;
    }
    void dfs(vector<int>& c, int l, int sum){
        if (l >= _size || sum > target){
            return;
        }
        if (sum == target){
            res.push_back(tmp);
        }

        for (int i = l; i < _size; ++i) {
            if (sum + c[i] <= target){
                tmp.push_back(c[i]);
                dfs(c, i, sum + c[i]);
                tmp.pop_back();
            }
            else{
                return;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Ygoe9J, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().Ygoe9J(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}