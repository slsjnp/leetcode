// 2021-10-18 00:16:24
#include <gtest/gtest.h>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findComplement(int num) {
        int v = 0;
        int tmp = num;
        while ( tmp > 0){
            tmp >>= 1;
            v = (v << 1) + 1;
        }
        return num ^ v;

    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(NumberComplement, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().numberComplement(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}