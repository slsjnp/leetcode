// 2023-09-11 22:56:05
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int _size = courses.size();
        std::sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        vector<vector<int> > res(_size + 1, vector<int> {0, 0});
        if (courses[0][1] > courses[0][0]){
            res[1][0] = 1;
            res[1][1] = courses[0][0];
        }
        if (_size == 1){
            return res[1][0];
        }
        if (_size == 2){
            if (courses[1][0] + res[1][1] <= courses[1][1]){
                return res[1][0] + 1;
            } else {
                return res[1][0];
            }
        }
        for (int i = 2; i < _size; ++i) {
            if (res[i - 1][1] + courses[i][0] <= courses[i][1]){
                res[i][0] = res[i - 1][0] + 1;
                res[i][1] = res[i - 1][1] + courses[i][0];
            } else{
                res[i][0] = res[i - 1][0];
                res[i][1] = res[i - 1][1];
            }
            if ((res[i - 2][0] + 1) == res[i][0] && res[i - 2][1] + courses[i][1] <= res[i][1]){
                res[i][1] = min(res[i - 2][1] + courses[i][1], res[i][1]);
            }
            res[i - 2][0] = res[i - 1][0];
            res[i - 2][1] = res[i - 1][1];
        }
        res[_size][0] = max(res[_size - 1][0], res[_size - 2][0]);
        return res[_size][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CourseScheduleIii, Example1) {      // NOLINT
        std::vector<vector<int>> nums = { {1, 2}, {2, 3} };
        auto ans = Solution().scheduleCourse(nums);
        decltype(ans) rightAns = 1;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}