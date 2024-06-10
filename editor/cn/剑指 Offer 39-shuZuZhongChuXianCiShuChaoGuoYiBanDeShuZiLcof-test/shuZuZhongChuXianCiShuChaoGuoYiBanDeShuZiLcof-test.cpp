// 2022-08-29 18:48:41
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int _size = nums.size();
        int pre = nums[0];
        int count = 1;
        int flag = 1;
        if (_size == 1) return nums[0];
        for (int i = 1; i < _size; ++i) {
            if (flag){
                if (pre == nums[i]){
                    count++;
                } else{
                    count--;
                    if (count == 0){
                        flag = 0;
                    }
                }
            } else{
                flag = 1;
                count = 1;
                pre = nums[i];
            }
        }
        return pre;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ShuZuZhongChuXianCiShuChaoGuoYiBanDeShuZiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().shuZuZhongChuXianCiShuChaoGuoYiBanDeShuZiLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}