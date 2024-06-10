// 2022-12-09 10:29:35
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
        int _size = boxes.size();
        long ws[_size + 1];
        int cs[_size];
        ws[0] = cs[0] = 0;
        for (int i = 0; i < _size; ++i) {
            int p = boxes[i][0];
            int w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < _size - 1) {
                cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
            }
        }
        int dp[_size + 1];
        dp[0] = 0;

        deque<int> q{0};
        for (int i = 1; i <= _size; ++i) {
            // 判断是否合法
            while (!q.empty() && (i - q.front() > maxBoxes || ws[i] - ws[q.front()] > maxWeight)) q.pop_front();

            // 更新最新值
            if (!q.empty()) dp[i] = cs[i - 1] - cs[q.front()] + 2 + dp[q.front()];

            // 滑动窗口
            if (i < _size){
                // 保证单调递增性，也就是保证 dp[q.back()] - cs[q.back()] 单调队列末尾元素比当前代价小。
                while(!q.empty() && dp[q.back()] - cs[q.back()] >= dp[i] - cs[i]) q.pop_back();
                q.push_back(i);
            }
        }
        return dp[_size];

    }

    // O(n2) 前缀和计算cost
    // int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
    //     int _size = boxes.size();
    //     long ws[_size + 1];
    //     int cs[_size];
    //     ws[0] = cs[0] = 0;
    //     for (int i = 0; i < _size; ++i) {
    //         int p = boxes[i][0];
    //         int w = boxes[i][1];
    //         ws[i + 1] = ws[i] + w;
    //         if (i < _size - 1) {
    //             cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
    //         }
    //     }
    //
    //     int dp[_size + 1];
    //     memset(dp, 0x3f, sizeof(dp));
    //     dp[0] = 0;
    //     for (int i = 1; i <= _size; ++i) {
    //         for (int j = max(0, i - maxBoxes); j < i; ++j) {
    //             if (ws[i] - ws[j] <= maxWeight){
    //                 dp[i] = min(dp[i], dp[j] + cs[i - 1] - cs[j] + 2);
    //             }
    //         }
    //     }
    //     return dp[_size];
    // }

    // 朴素dp，暴力计算前缀和
    // int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
    //     int _size = boxes.size();
    //     // vector<int> dp(_size + 5, INT_MAX);
    //     int dp[_size + 5];
    //     // memset赋值按字节计算，127为八个字节第一位非0的最大值，即可获得一个较大的数
    //     memset(dp, 127, sizeof(dp));
    //     dp[0] = 0;
    //     for (int i = 1; i <= _size; ++i) {
    //         int sum = 0;
    //         for (int j = i; j >= 1 && j >= i - maxBoxes + 1; --j) {
    //             sum += boxes[j - 1][1];
    //             if (sum > maxWeight) break;
    //             dp[i] = min(dp[i], dp[j - 1] + cost(boxes, j, i));
    //         }
    //     }
    //     return dp[_size];
    // }
    //
    // int cost(vector<vector<int>> &boxes, int l, int r){
    //     int ans = 2;
    //     int port = boxes[l - 1][0];
    //     while(++l <= r){
    //         if (boxes[l - 1][0] == port) continue;
    //         ans++;
    //         port = boxes[l - 1][0];
    //     }
    //     return ans;
    // }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DeliveringBoxesFromStorageToPorts, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().deliveringBoxesFromStorageToPorts(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}