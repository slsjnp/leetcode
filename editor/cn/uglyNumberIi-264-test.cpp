// 2022-01-15 13:45:28
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long> > pq;
        int i = 0;
        long ans = 0;
        pq.emplace(1);
        unordered_set<long> se;

        while (i < n) {
            long t = pq.top();
            if (se.count(t * 2) == 0) {
                pq.emplace(t * 2);
                se.insert(t * 2);
            }
            if (se.count(t * 3) == 0) {
                pq.emplace(t * 3);
                se.insert(t * 3);
            }
            if (se.count(t * 5) == 0) {
                pq.emplace(t * 5);
                se.insert(t * 5);
            }
            ans = pq.top();
            pq.pop();
            i++;
        }
        while(i < n){
            ans = pq.top();
            pq.pop();
            i++;
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(UglyNumberIi, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().uglyNumberIi(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}