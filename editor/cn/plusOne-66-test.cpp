// 2021-10-21 21:55:20
#include <gtest/gtest.h>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int ind = size - 1;
        // int flag = 0;
        while (ind >= 0 && digits[ind] == 9){
            digits[ind--] = 0;
        }
        if (ind == -1){
            digits.insert(digits.cbegin(), 1);
        }
        else{
            digits[ind]++;
        }
        return digits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(PlusOne, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().plusOne(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}