// 2021-11-01 17:45:54
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> se;
        for (auto i: candyType) {
            if (!se.count(i)){
                se.insert(i);
            }
        }
        return min(candyType.size() / 2, se.size());

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DistributeCandies, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().distributeCandies(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}