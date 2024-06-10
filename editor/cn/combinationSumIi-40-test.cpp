// 2022-01-14 15:26:26
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
    int _target;
    int _size;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        _size = candidates.size();
        this->_target = target;
        used = vector<int> (_size, 0);
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return res;
    }

    void dfs(vector<int> &can, int now, int l) {
        if (now == _target) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = l; i < can.size(); ++i) {
            if (can[i] + now <= _target) {
                if (i > 0 and can[i] == can[i-1] and used[i - 1] == 0){
                    l++;
                    continue;
                }
                tmp.emplace_back(can[i]);
                used[i] = 1;
                dfs(can, now + can[i], l + 1);
                tmp.pop_back();
                used[i] = 0;
                l++;
            } else {
                return;
            }
        }
    }
};



//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CombinationSumIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().combinationSumIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}