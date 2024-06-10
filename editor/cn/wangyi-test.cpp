//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
// c libraries
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
// // file output
// #include <iostream>
#include <fstream>
#include <gtest/gtest.h>


using namespace std;

int mainn(int n, int m, vector<vector<int>> res) {
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> res(n, vector<int>(m));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         scanf("%d", &res[i][j]);
    //     }
    // }
    int sum = INT_MAX;
    queue<vector<int>> qu;
    map<pair<int, int>, int> ma;
    qu.push({0, 0, 0});
    vector<vector<int>> di = {{0, 1},
                              {1, 0},
                              {0, -1}};
    while (!qu.empty()) {
        auto it = qu.front();
        qu.pop();
        for (auto dis: di) {
            int xx = it[0] + dis[0];
            int yy = it[1] + dis[1];
            if (xx < n && yy < m && yy >= 0) {
                int cost = res[it[0]][it[1]] == res[xx][yy] ? 1 : 2;
                if (ma.count({xx, yy}) == 0 || (ma.count({xx, yy}) && ma[{xx, yy}] > it[2] + cost)) {
                    qu.push({xx, yy, it[2] + cost});
                    ma[{xx, yy}] = it[2] + cost;
                }
            }
            if (xx == n && yy == m) {
                sum = min(sum, it[2]);
            }
        }
    }
    // printf("%d", ma[{n - 1,m - 1}]);
    return ma[{n - 1,m - 1}];
}
// int main() {
//     int n;
//     cin >> n;
//     vector<int> res(n);
//     int odd = 3;
//     int add = 2;
//     int start = 1, end;
//     int now = 2;
//     int step = 1;
//
//     int tmp = n;
//     int sum = 0;
//     while (tmp > 0) {
//         tmp /= 2;
//         sum++;
//     }
//
//     res[0] = 1;
//     printf("%d ", res[0]);
//     for (int i = 1; i < sum; ++i) {
//         end = min(start + now, n);
//         now *= 2;
//         while (start < end && add <= n && odd <= n) {
//             // 第几层
//             if (i & 1){
//                 res[start] = add;
//                 add += 2;
//             } else{
//                 res[start] = odd;
//                 odd += 2;
//             }
//             printf("%d ", res[start]);
//             start++;
//         }
//     }
//     while(odd <= n){
//         printf("%d ", odd);
//         odd += 2;
//     }
//     return 0;
// }

// int main(){
//     // char s[200000];
//     string s;
//     // scanf("%s", &s);
//     cin>>s;
//     int _size = s.size();
//     unordered_map<int,int> ma;
//     for (int i = 1; i < _size; ++i) {
//         if (abs(s[i] - s[i - 1]) <= 1){
//             ma[i - 1] = s[i] - 'a' + s[i - 1] - 'a' + 2;
//         } else{
//             ma[i - 1] = 0;
//         }
//     }
//     int dp[_size + 1];
//     memset(dp, 0, sizeof(dp));
//     dp[0] = ma.count(0) ? ma[0]: 0;
//     dp[1] = ma.count(1) ? ma[1]: max(dp[0], 0);
// //     for (int i = 0; i < _size; ++i) {
//     for (int j = 2; j <= _size; ++j) {
//         dp[j] = max(dp[j - 2] + ma[j], dp[j - 1]);
//     }
// //     }
//     printf("%d", dp[_size]);
//     return 0;
// }

int main(){
    int a,b,x,y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    vector<vector<int>> dp(a + 1, vector<int> (b + 1, INT_MAX - 3));
    dp[a][b] = 0;
    for (int i = a; i >= 0 ; --i) {
        for (int j = b; j >= 0; ++j) {
            int idx = max(i - x, 0);
            int idy = max(j - x, 0);
            int yidx = max(i - y, 0);
            int yidy = max(j - y, 0);
            dp[idx][j] = min(dp[i][j] + 1, dp[idx][j]);
            dp[i][idy] = min(dp[i][j] + 1, dp[i][idy]);
            dp[yidx][yidy] = min(dp[yidx][yidy], dp[i][j] + 1);
        }
    }
    return dp[0][0];
}

//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(wangyi, Example2
    ) {      // NOLINT
        // std::vector<int> nums = {0, 0, 0, 0, 0, 2, 0, 5, 1, 1, 0, 0};
        vector<vector<int>> nums = {{1, 0, 0},
                                    {1, 1, 1},
                                    {0, 0, 1}};

        // vector<vector<int>> nums = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
        // vector<vector<int>> nums = {{0, 1, 1},
        //                             {2, 1, 1}};
        auto ans = mainn(3, 3, nums);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns
        );

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
