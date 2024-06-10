// 2021-12-19 21:01:36
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> ma;
        unordered_set<int> se;
        for (int i = 0; i < trust.size(); ++i) {
            ma[trust[i][1]]++;
            if (se.count(trust[i][0]) == 0){
                se.insert(trust[i][0]);
            }
        }
        for (int i = 0; i < trust.size(); ++i) {
            if (ma[trust[i][1]] == n - 1 and se.count(trust[i][1]) == 0){
                return trust[i][1];
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FindTheTownJudge, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().findTheTownJudge(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}