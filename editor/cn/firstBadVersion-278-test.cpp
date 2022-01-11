// 2022-01-08 18:54:23
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        while(low <= high){
            mid = low + (high - low ) / 2;
            bool flag = isBadVersion(mid);
            if (flag){
                return mid;
            }
            else {low = mid + 1;}
        }
        return low;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FirstBadVersion, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().firstBadVersion(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}