// 2022-10-01 17:09:05
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long> > pq;
        pq.push(1);
        pq.push(2);
        pq.push(3);
        pq.push(5);
        long top = 1;
        unordered_set<long> se;
        se.insert(1);
        se.insert(2);
        se.insert(3);
        se.insert(5);
        for (int i = 0; i < n; ++i) {
            top = pq.top();
            // printf("%d ",top);
            pq.pop();
            if (se.count(top * 2) == 0){
                pq.push(top * 2);
                se.insert(top * 2);
            }
            if (se.count(top * 3) == 0){
                pq.push(top * 3);
                se.insert(top * 3);
            }
            if (se.count(top * 5) == 0){
                pq.push(top * 5);
                se.insert(top * 5);
            }
        }
        return top;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ChouShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().chouShuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}