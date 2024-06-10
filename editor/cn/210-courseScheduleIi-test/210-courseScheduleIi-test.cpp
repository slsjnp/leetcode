// 2023-09-10 20:10:36
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CourseScheduleIi, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().courseScheduleIi(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}