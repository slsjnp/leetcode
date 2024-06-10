
// 2024-03-20 00:05:49
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RemoveDuplicatesFromSortedArray, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().removeDuplicatesFromSortedArray(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
