// 2022-02-19 23:00:58
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> pancakeSort(vector<int> &arr) {
        int _size = arr.size();
        vector<int> res;
        int dp[_size];
        memset(dp, 0, sizeof(dp));
        int l = 0;
        int add = 1;
        int now_size = _size - 1;
        vector<int> tmp = arr;
        for (int i = 0; i < _size; ++i) {
            // 找到最大值以及，当前最大值的下标
            int max_ = 0;
            int pos = 0;
            for (int j = 0; j < _size; ++j) {
                if (max_ < tmp[j]){
                    max_ = tmp[j];
                    pos = j;
                }
            }
            res.push_back(pos);
            l = 0
            for (int j = pos; j < _size; ++j) {
                tmp[l] = arr[j];
                l++;
            }
            for (int j = 0; j < pos; ++j) {

            }
            if (add == 1){
                l = now_size;
                now_size--;
            }
            else{
                l = 0;
            }
            add *= -1;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(PancakeSorting, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().pancakeSorting(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}