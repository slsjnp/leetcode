// 2022-03-06 00:54:51
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int _size = numbers.size();
        for (int i = 0; i < _size; ++i) {
            if (i > 0 && numbers[i] == numbers[i - 1]) continue;
            for (int j = _size - 1; j > 0 ; --j) {
                if (i == j){
                    break;
                }
                else{
                    if (numbers[i] + numbers[j] == target){
                        return vector<int> {i, j};
                    }
                }
            }
        }
        return {};

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(KLl5u1, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().kLl5u1(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}