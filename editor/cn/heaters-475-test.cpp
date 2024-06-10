// 2021-12-20 23:01:23
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int sum = INT_MIN;
        int h_size = houses.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < h_size; ++i) {
            auto up = upper_bound(heaters.begin(), heaters.end(), houses[i]);
            // printf("up: %d, house: %d, sum : %d\n",*up, houses[i], sum);
            if (up != heaters.end()) {
                if (up == heaters.begin()){
                    sum = max(sum, *up - houses[i]);
                    // printf("33333333333");
                }
                else{
                    sum = max(sum, min(abs((*up) - houses[i]), abs(*(--up) - houses[i])));
                }
            }
            else{
                // printf("444444444444");
                sum = max(sum, abs(*(--up) - houses[i]));
            }
        }
        return sum;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(Heaters, Example1) {      // NOLINT
        std::vector<int> nums = {1,2,3};
        vector<int> a = {2};
        auto ans = Solution().findRadius(nums, a);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}