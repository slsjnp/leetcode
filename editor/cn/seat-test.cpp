//
// Created by sj on 2021/10/16.
//
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int length = patience.size();
        int res[patience.size()];
        for (int i = 0; i < patience.size(); ++i) {
            res[i] = patience[i];
        }
        int net[patience.size()][patience.size()];
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                net[i][j] = -1;
            }
        }
        for (int i = 0; i < edges.size(); ++i) {
            net[edges[i][0]][edges[i][1]] = 1;
            net[edges[i][1]][edges[i][0]] = 1;

        }
        queue<vector<int>> qu;
        for (int i = 0; i < length; ++i) {
            if (net[0][i]!=-1){
                qu.push(vector<int>{0,i});
            }
        }
        while (qu.size()>0) {
            vector<int> now = qu.front();
            qu.pop();
            for (int j = 0; j < length; ++j) {
                if (net[now[1]][j]!=-1){
                    if (net[0][j] == -1){
                        net[0][j] = net[0][now[1]] + net[now[1]][j];
                        net[j][0] = net[0][now[1]] + net[now[1]][j];
                        qu.push(vector<int>{0, j});
                        continue;
                    }
                    net[0][j] = min(net[0][now[1]] + net[now[1]][j], net[0][j]);
                }
            }
        }
        for (int i = 1; i < length; ++i) {
            if ((2 * net[0][i]) % patience[i] == 0){
                res[i] = 2 * (2 * net[0][i]) - patience[i];
            }
            else{
                res[i] = 2 * (2 * net[0][i]) - (2 * net[0][i]) % patience[i];
            }

        }
        int sum = 0;
        for (int i = 1; i < length; ++i) {
            sum = max(sum, res[i]);
        }
        return sum+1;
    }
};

namespace {
    TEST(CountAndSay, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        vector<vector<int>> a = {{3, 8},{4, 13},{0, 7},{0, 4},{1, 8},{14, 1},{7, 2},{13, 10},{9, 11},{12, 14},{0, 6},{2, 12},{11, 5},{6, 9},{10, 3}};
        std::vector<int> nums = {0, 3, 2, 1, 5, 1, 5, 5, 3, 1, 2, 2, 2, 2, 1};
        auto ans = Solution().networkBecomesIdle(a, nums);
        decltype(ans) rightAns = 8;
        ASSERT_EQ(ans, rightAns);
    }

    // TEST(CountAndSay, solution) {      // NOLINT
    //     std::vector<int> nums = { };
    //     auto ans = Solution().countAndSay(nums);
    //     decltype(ans) rightAns = ;
    //     ASSERT_EQ(ans, rightAns);
    // }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}