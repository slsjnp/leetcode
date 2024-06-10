// 2022-08-18 00:31:42
#include <gtest/gtest.h>
#include "../../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int _size = numbers.size();
        int l = 0;
        int r = _size - 1;
        int mid;
        while(l <= r){
            mid = l + ((r - l) >> 1);
            if (numbers[mid] > numbers[r]){
                l = mid + 1;
            } else if (numbers[mid] < numbers[0]){
                r = mid;
            } else{
                r--;
            }
        }
        return numbers[l];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(XuanZhuanShuZuDeZuiXiaoShuZiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().xuanZhuanShuZuDeZuiXiaoShuZiLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}