// 2022-01-14 14:19:37
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    set<vector<int>> se;
    int _target;
    int _size;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        _size = candidates.size();
        this->_target = target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return res;
    }

    void dfs(vector<int> &can, int now, int l) {
        if (now == _target) {
            // sort(tmp.begin(), tmp.end());
            // if (se.count(tmp) == 0) {
            res.emplace_back(tmp);
            // se.insert(tmp);
            return;
            // }
        }
        for (int i = l; i < can.size(); ++i) {
            if (can[i] + now <= _target) {
                tmp.emplace_back(can[i]);
                dfs(can, now + can[i], l);
                tmp.pop_back();
                l++;
            } else {
                return;
            }
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CombinationSum, Example1) {      // NOLINT
        std::vector<int> nums = {2, 3, 5};
        auto ans = Solution().combinationSum(nums, 8);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}