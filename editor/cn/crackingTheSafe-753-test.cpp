// 2021-12-19 23:19:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    unordered_set<int> seen;
    string ans;
    int highest;
    int k;

public:
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = node * 10 + x;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }

    string crackSafe(int n, int k) {
        highest = pow(10, n - 1);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};
// class Solution {
// public:
//     string res;
//     unordered_map<int, vector<int>> ma;
//
//     string crackSafe(int n, int k) {
//         for (int i = 0; i < k; ++i) {
//             // ma[i] = vector<int> {0};
//             for (int j = 0; j < k; ++j) {
//                 if (j != i) {
//                     if (ma.count(i) == 0){
//                         ma[i] = vector<int> {j};
//                     }
//                     else ma[i].emplace_back(j);
//                 }
//             }
//         }
//         // res = "0";
//         dfs(0);
//         reverse(res.begin() + 1, res.end());
//         return res;
//     }
//
//     void dfs(int start) {
//         while (!ma[start].empty()) {
//             int dec = ma[start].back();
//             ma[start].pop_back();
//             dfs(dec);
//             res += '0' + dec;
//         }
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CrackingTheSafe, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().crackingTheSafe(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}