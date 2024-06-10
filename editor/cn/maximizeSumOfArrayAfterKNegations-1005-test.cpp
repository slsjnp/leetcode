// 2021-12-03 23:47:23
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct cmp {
    bool operator()(int &a, int &b) const {
        return a > b;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, cmp> p2;
        int sum = 0;
        for (auto it: nums) {
            p2.push(it);
            sum += it;
        }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            sum -= 2 * p2.top();
            // printf("sum: %d\n", sum);
            t = p2.top();
            p2.pop();
            p2.push(-t);
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MaximizeSumOfArrayAfterKNegations, Example1) {      // NOLINT
        std::vector<int> nums = {-2, 9, 9, 8, 4};
        auto ans = Solution().largestSumAfterKNegations(nums, 5);
        decltype(ans) rightAns = 5;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}