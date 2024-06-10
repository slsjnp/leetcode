// 2021-10-30 09:11:59
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int bit[4];
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        int xor_sum = 0;
        vector<int> res(2);
        for (auto i: nums) {
            xor_sum ^= i;
        }
        // 取xor最低一位的1
        // 例如  x （二进制） xxxx10000
        // 取反  x           xxxx01111
        // 取反 + 1 = -x     xxxx10000

        // 防止溢出
        int mask = (xor_sum == INT_MIN ? xor_sum : xor_sum & (-xor_sum));

        for (auto i: nums) {
            if ((i & mask) == 0){
                res[0] ^= i;
            }
            else {
                res[1] ^= i;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SingleNumberIii, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().singleNumberIii(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}