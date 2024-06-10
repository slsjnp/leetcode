// 2021-10-20 08:41:42
#include <gtest/gtest.h>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int tmp = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < tmp){
                tmp = nums[i];
            }
        }
        int sum=0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] - tmp;
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MinimumMovesToEqualArrayElements, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().minimumMovesToEqualArrayElements(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}