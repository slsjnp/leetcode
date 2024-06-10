//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(biweek62, Example1) {      // NOLINT
        // std::vector<int> nums = {};
        // vector<vector<int>> nums = {{0},{0},{0},{0},{1},{1},{0},{0},{1}};
        // vector<vector<int>> nums = {{0,0,1,1},{0,0,1,1}};
        vector<vector<int>> nums = {{1, 0, 0, 0},
                                    {1, 0, 0, 0},
                                    {1, 0, 0, 0},
                                    {1, 0, 0, 0},
                                    {1, 0, 0, 0}};
        // vector<vector<int>> nums = {{1,1,1,1,1,0},{1,0,0,1,0,0},{1,1,0,1,1,0},{1,0,0,1,0,0},{1,0,1,0,1,0},{1,1,1,0,1,1},{0,0,1,0,0,0},{0,0,1,1,0,0}};
        auto ans = Solution().possibleToStamp(nums, 4, 3);
        decltype(ans) rightAns = true;
        ASSERT_EQ(ans, rightAns);
    }

    // TEST(biweek69, Example2) {      // NOLINT
    //     // std::vector<int> nums = { 10,83,53};
    //     // string s = "**|**|***|";
    //     vector<vector<int>> t = {{1, 5, 3},
    //                              {1, 5, 1},
    //                              {6, 6, 5}};
    //     // int a = 6;
    //     // vector<int> n = {3, 2};
    //     auto ans = Robot(6, 3);
    //     ans.move(2);
    //     ans.move(2);
    //     ans.move(2);
    //     ans.move(1);
    //     ans.move(4);
    //     int c = 0;
    //     decltype(c) rightAns = 8;
    //     ASSERT_EQ(c, rightAns);
    // }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
