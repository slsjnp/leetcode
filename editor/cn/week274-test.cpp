//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumInvitations(vector<int> &favorite) {
        int _size = favorite.size();
        vector<int> follow(_size, 0), in(_size, 0), vis(n, 0);
        queue<int> q;
        for (int i = 0; i < _size; ++i) {
            in[favorite[i]]++;
        }


    }
};
// class Solution {
// public:
//     bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//         sort(asteroids.begin(), asteroids.end());
//         int _size = asteroids.size();
//         long long now = mass;
//         for (int i = 0; i < _size; ++i) {
//             if (now >= asteroids[i]){
//                 now += asteroids[i];
//             } else return false;
//         }
//         return true;
//     }
// };
// class Solution {
// public:
//     int numberOfBeams(vector<string>& bank) {
//         int _size = bank.size();
//         vector<int> res(_size);
//         for (int i = 0; i < _size; ++i) {
//             int sum = 0;
//             for (int j = 0; j < bank[0].size(); ++j) {
//                 if (bank[i][j] == '1'){
//                     sum++;
//                 }
//             }
//             res[i] = sum;
//         }
//         int pre = res[0];
//         int ans = 0;
//         for (int i = 1; i < _size; ++i) {
//             if (res[i] != 0){
//                 ans += pre * res[i];
//                 pre = res[i];
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     bool checkString(string s) {
//         int _size = s.size();
//         int flag = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (s[i] == 'b'){
//                 flag = 1;
//             }
//             if (s[i] == 'a' and flag){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week274, Example2) {      // NOLINT
        std::vector<int> nums = {98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821,
                                 98818, 98821, 98818};
        auto ans = Solution().getDistances(nums);
        decltype(ans) rightAns = {0, 1};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
