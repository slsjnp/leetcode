// 2022-01-10 13:35:44
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        unordered_map<char, long long> ma;
        int pre = 0;
        long long sum = 0;
        char c;
        for (int i = 0; i < releaseTimes.size() ; ++i) {
            ma[keysPressed[i]] += releaseTimes[i] - pre;
            pre = releaseTimes[i];
            if (ma[keysPressed[i]] > sum){
                sum = ma[keysPressed[i]];
                c = keysPressed[i];
            }
        }
        return c;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SlowestKey, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().slowestKey(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}