// 2022-01-08 20:07:59
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int _size = intervals.size();
        unordered_map<int, int> ma;
        for (int i = 0; i < _size; ++i) {
            ma[intervals[i][0]] = i;
        }
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){return a[0] < b[0];})
        vector<int> res(_size,-1);
        for (int i = 0; i < _size; ++i) {
            int low = 0;
            int high = _size - 1;
            int mid;
            while (low <= high){
                mid = low + (high - low) / 2;
                if (intervals[mid][0] == intervals[i][1]){
                    high = mid - 1;
                }
                else if(intervals[mid][0] > intervals[i][1]){
                    high = mid - 1;
                }
                else if(intervals[mid][0] < intervals[i][1]){
                    low = mid + 1;
                }
            }
            if (low == _size or intervals[low][0] != intervals[i][1]){
                res[ma[intervals[i][0]]] = -1;
            }
            else res[ma[intervals[i][0]]] = ma[intervals[low][0]];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FindRightInterval, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().findRightInterval(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}