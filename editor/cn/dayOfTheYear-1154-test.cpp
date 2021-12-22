// 2021-12-22 00:10:08
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dayOfYear(string date) {
        vector<int> ve = {31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> pre(ve.size() + 1, 0);
        // pre.push_back(0);
        for (int i = 1; i < ve.size(); ++i) {
            pre[i] = pre[i - 1] + ve[i-1];
        }
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        int sum = pre[m - 1] + d;
        if (m > 2 and ((y % 100 != 0 and y % 4 == 0) or y % 400 == 0)){
            printf("m:%d, d:%d",pre[m-1],d);
            return sum + 1;
        }
        else{
            printf("m:%d, d:%d",pre[m-1],d);
            return sum;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DayOfTheYear, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().dayOfTheYear(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}