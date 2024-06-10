// 2022-03-06 00:49:56
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int _size = words.size();
        vector<int> res(_size, 0);
        for (int i = 0; i < _size; ++i) {
            int tmp = 0;
            for (auto it :words[i]) {
                tmp |= 1 << (it - 'a');
            }
            res[i] = tmp;
        }
        int sum = 0;
        for (int i = 0; i < _size; ++i) {
            for (int j = i + 1; j < _size; ++j) {
                if ((res[i] & res[j]) == 0 and sum < words[i].size() * words[j].size()){
                    sum = words[i].size() * words[j].size();
                }
            }
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(AseY1I, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().aseY1I(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}