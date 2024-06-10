// 2022-08-23 11:47:59
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int _size = nums.size();
        int l = 0;
        int r = _size - 1;
        while(l < r){
            while(l < r && nums[l] & 1){
                l++;
            }
            while(l < r && (nums[r] & 1) == 0){
                r--;
            }
            if (l < r){
                swap(nums[l], nums[r]);
            } else{
                break;
            }
            // l++;
            // r--;
        }

        return nums;

    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DiaoZhengShuZuShunXuShiQiShuWeiYuOuShuQianMianLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().diaoZhengShuZuShunXuShiQiShuWeiYuOuShuQianMianLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}