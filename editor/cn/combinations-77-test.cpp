// 2022-01-14 21:02:32
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum;
    int _size;
    vector<vector<int>> combine(int n, int k) {
        vector<int> res(n);
        _size = n;
        sum = k;
        iota(res.begin(), res.end(), 1);
        dfs(res, 0);
        return ans;
    }
    void dfs(vector<int>& res, int l){
        if (tmp.size() + (_size - l + 1) < sum) {
            return;
        }
        if (tmp.size() == sum){
            ans.emplace_back(tmp);
            return;
        }
        for (int i = l; i < _size; ++i) {
            tmp.emplace_back(res[i]);
            dfs(res, i + 1);
            tmp.pop_back();
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Combinations, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().combinations(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}