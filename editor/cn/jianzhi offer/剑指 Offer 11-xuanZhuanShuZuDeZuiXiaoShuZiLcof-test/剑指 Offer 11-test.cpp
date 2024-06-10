// 2022-08-22 20:51:17
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
        if (numbers[l] < numbers[r]) return numbers[0];
        while(l < r){
            mid = l + (r - l) / 2;
            // 只要右边比中间大， 那右边一定是有序数组
            if (numbers[mid] < numbers[r]) {
                r = mid;
            } else if(numbers[mid] > numbers[r]){
                l = mid + 1;
            } else {
                // 去重
                r--;
            }
            // printf("%d ",mid);
        }
        // printf("%d ",r);
        return numbers[r];
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