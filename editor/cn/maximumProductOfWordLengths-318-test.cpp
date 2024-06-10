// 2021-11-17 22:02:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int w_size = words.size();
        int flag = (1 << 27) - 1;
        vector<int> st;
        for (int i = 0; i < w_size; ++i) {
            int tmp = 0;
            for (auto it: words[i]) {
                int j = it - 'a';
                tmp |= (1 << j);
            }
            st.emplace_back(tmp);
        }
        int sum = 0;
        for (int i = 0; i < w_size; ++i) {
            int length = words[i].size();
            for (int j = i + 1; j < w_size; ++j) {
                if (((st[j] ^ st[i]) == (st[j] | st[i]))){
                    sum = max(sum, length * (int)words[j].size());
                }
            }
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MaximumProductOfWordLengths, Example1) {      // NOLINT
        std::vector<string> nums = { "abcw","baz","foo","bar","xtfn","abcdef" };
        auto ans = Solution().maxProduct(nums);
        decltype(ans) rightAns = 16;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}