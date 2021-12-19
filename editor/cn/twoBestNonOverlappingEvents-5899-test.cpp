// 2021-10-31 20:05:20
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int _size = events.size();
        sort(events.begin(), events.end());
        map<int, int> ma;
        int sum = 0;
        for (int i = _size - 1; i >= 0 ; --i) {
            if (ma.count(events[i][0])){
                ma[events[i][0]] = max(ma[events[i][0]], events[i][2]);
                sum = ma[events[i][0]];
            }
            else{
                ma[events[i][0]] = max(events[i][2], sum);
                sum = ma[events[i][0]];
            }
        }
        int _max = 0;
        // int ind;
        for (int i = 0; i < _size; ++i) {
            auto ind = ma.upper_bound(events[i][1]);
            if (ind != ma.end()){
                _max = max(_max, events[i][2] + ind->second);
            }
            else{
                _max = max(_max, ma.begin()->second);
            }
        }
        return _max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(TwoBestNonOverlappingEvents, Example1) {      // NOLINT
        std::vector<vector<int>> nums = { {1,3,2}, {4,5,2}, {2,4,3} };
        auto ans = Solution().maxTwoEvents(nums);
        decltype(ans) rightAns = 6;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}