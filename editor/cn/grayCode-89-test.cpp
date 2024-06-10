// 2022-01-08 21:14:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> res;
    // vector<vector<int>>
    unordered_set<int> se;
    unordered_map<int, int> ma;
    map<int, int> ma;

    vector<int> grayCode(int n) {
        dfs(n, 0);
        return res;
    }

    void dfs(int n, int now) {

        for (int i = 0; i <= n; ++i) {
            if (se.count(now ^ 1 << i) == 0) {
                res.push_back(now ^ 1 << i);
                se.insert(now ^ 1 << i);
            }
            if (res.size() == (1 << n and now ^ 1 << i == 0)) {
                return;
            }
            dfs(now);
            now ^= 1 << i;
            res.pop_back();
            se.erase(now ^ 1 << i);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(GrayCode, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().grayCode(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}