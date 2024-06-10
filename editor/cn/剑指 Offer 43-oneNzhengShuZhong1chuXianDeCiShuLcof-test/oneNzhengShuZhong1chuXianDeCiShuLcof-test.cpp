// 2022-09-01 21:00:37
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        long long dig = 1;
        int h = n / 10;
        int cur = n % 10;
        int l = 0;

        while(h != 0 || cur != 0){
            if (cur == 0){
                res += h * dig;
            } else if(cur == 1){
                res += h * dig + l + 1;
            } else{
                res += (h + 1) * dig;
            }
            l += cur * dig;
            cur = h % 10;
            dig *= 10;
            h /= 10;
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(OneNzhengShuZhong1chuXianDeCiShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().oneNzhengShuZhong1chuXianDeCiShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}