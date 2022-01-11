// 2021-12-22 00:29:48
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // int repeatedStringMatch(int* a, int n) {
    //     int low = 0;
    //     int high = n - 1;
    //     int tmp = a[0];
    //     int sum = 0;
    //     while(low < high){
    //         while (low < high && a[high] < 0) {
    //             high--;
    //             sum++;
    //         }
    //         a[low] = a[high];
    //         low++;
    //         while (low < high && a[low] >= 0) {
    //             low++;
    //             sum++;
    //         }
    //         a[high] = a[low];
    //         high--;
    //     }
    //     a[low] = tmp;
    //     // for (int i = 0; i < n; ++i) {
    //         printf("%d \n", sum);
    //     // }
    //     return 0;
    // }
    int repeatedStringMatch(string a, string b) {
        int a_size = a.size();
        int b_size = b.size();
        int l = 0;
        int flag;
        int r;
        int times;
        for (int i = 0; i < a_size; ++i) {
            flag = 1;
            times = 0;
            l = 0;
            r = i;
            vector<int> vis(a_size, 0);
            while (l < b_size and flag != 0) {
                if (a[r] != b[l]) {
                    flag = 0;
                }
                l++;
                vis[(r + l) % a_size]++;
                // if (r % a_size == i % a_size) times++;
                r = (r + 1) % a_size;

            }
            if (flag) {
                int max_ = vis[0];
                int min_ = vis[0];
                for (auto it: vis) {
                    if (it > max_){
                        max_ = it;
                    }
                    if (it < min_){
                        min_ = it;
                    }
                }
                if (a[0] != b[0]){
                    if (max_ == min_) return max_ + 1;
                    if (max_ != min_) return max_;
                }
                else {
                    return max_;
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RepeatedStringMatch, Example1) {      // NOLINT
        // std::vector<int> nums = {};
        int a[10] = {-1,-2,-6,5,3,6,-4,-2,-3,9};
        auto ans = Solution().repeatedStringMatch(a, 10);
        decltype(ans) rightAns = 0;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}