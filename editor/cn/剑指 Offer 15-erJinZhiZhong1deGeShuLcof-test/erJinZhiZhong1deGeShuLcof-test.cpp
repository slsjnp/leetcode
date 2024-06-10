// 2022-08-23 10:37:30
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0){
            if (n & 1){
                res++;
            }
            n >>= 1;
        }
        return res;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ErJinZhiZhong1deGeShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().erJinZhiZhong1deGeShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}