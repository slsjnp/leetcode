// 2022-03-10 17:40:13
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ma, vis;
        int l = 0, r = 0;
        int _size = s.size();
        int res = 0, sum = 0;
        while( r < _size){
            char c = s[r];
            if (ma.count(c) == 0 || ma[c] == 0){
                res++;
            }
            ma[c]++;
            r++;
            while(r - l > res){
                ma[s[l]]--;
                if (ma[s[l]] == 0){
                    res--;
                }
                l++;
            }
            sum = max(sum, res);
        }
        return sum;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(WtcaE1, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().wtcaE1(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}