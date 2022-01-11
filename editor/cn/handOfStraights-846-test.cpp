// 2021-12-30 19:26:43
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int _size = hand.size();
        map<int, int> ma;
        for (int i = 0; i < _size; ++i) {
            ma[hand[i]]++;
        }
        int tm = 1;
        int now = 0;
        for (auto& it : ma) {
            while (it.second != 0){
                it.second--;
                tm = 1;
                now = it.first;
                while (tm < groupSize){
                    now++;
                    if(ma.count(now) and ma[now] != 0){
                        ma[now]--;
                        tm++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(HandOfStraights, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().handOfStraights(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}