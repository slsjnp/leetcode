// 2022-03-10 17:17:47
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s2, string s1) {
        int _size = s1.size();
        unordered_map<char, int > ma, mb;
        for (auto it: s2) {
            mb[it]++;
        }
        int l = 0, r = 0;
        int res = 0;
        while(r < _size){
            char c = s1[r];
            ma[c]++;
            if (mb.count(c) && ma[c] == mb[c]) res++;
            r++;

            while(r - l > s2.size()){
                c = s1[l];
                if (mb.count(c) && ma[c] == mb[c]){
                    res--;
                }
                ma[c]--;
                l++;
            }
            if (res == mb.size()){
                return true;
            }
        }
        return false;

    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MPnaiL, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().MPnaiL(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}