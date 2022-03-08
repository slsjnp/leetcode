// 2022-01-18 23:40:37
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        int _size = timePoints.size();
        vector<int> res;
        for (int i = 0; i < _size; ++i) {
            int h = stoi(string(timePoints[i].begin(), timePoints[i].begin() + 2));
            int m = stoi(string(timePoints[i].begin() + 3, timePoints[i].end()));
            if (h < 12) {
                res.push_back(24 * 60 + h * 60 + m);
            }
            res.push_back(h * 60 + m);
        }
        sort(res.begin(), res.end());
        int pre = res[0];
        int min_ = INT_MAX;
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] - pre < min_) {
                min_ = res[i] - pre;
            }
            pre = res[i];
        }
        return min_;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumTimeDifference, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().minimumTimeDifference(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}