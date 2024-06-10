// 2022-01-19 21:21:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int _size = nums.size();
        unordered_map<int, int> ma;
        for (int i = 0; i < _size; ++i) {
            if (ma.count(nums[i]) == 0){
                ma[nums[i]] = i;
            }
            else{
                if (abs(i - ma[nums[i]]) <= k){
                    return true;
                }
                else ma[nums[i]] = i;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ContainsDuplicateIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().containsDuplicateIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}