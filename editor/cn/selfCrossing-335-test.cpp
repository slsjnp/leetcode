// 2021-10-29 15:02:21
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<pair<int, int>> xy_map;
    vector<int> check;
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if (n < 4) return false;

        int i = 2;

        // 一直向外卷
        while (i < n && distance[i] > distance[i - 2]) i++;
        // 如果走完了，直接就可以返回不相交
        if (i == n) return false;

        // 如果向外卷转成了向内卷，i-1的长度减i-3的长度
        if (distance[i] >= distance[i - 2] - (i < 4 ? 0 : distance[i - 4])) {
            distance[i - 1] -=  i < 3 ? 0 : distance[i - 3];
        }

        // 一直向内卷，注意i先加1，这样正好跟i-1的位置相比较，相当于内卷从i-1的位置开始的
        for (++i; i < n && distance[i] < distance[i - 2]; i++);

        // 如果 i 能走完就不会相交，相反，走不完就相交了
        return i != n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SelfCrossing, Example1) {      // NOLINT
        std::vector<int> nums = {1,2,2,3,4};
        auto ans = Solution().isSelfCrossing(nums);
        decltype(ans) rightAns = true;
        ASSERT_EQ(ans, rightAns);
    }

}


// int main(int argc, char *argv[]) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }