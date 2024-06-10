// 2022-10-01 12:27:51
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<char, int> ma;

    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int _size = s.size();
        int l = 0;
        int r = 0;
        while (r < _size) {
            while (r < _size && (ma.count(s[r]) == 0 || ma[s[r]] == 0)) {
                ma[s[r]]++;
                r++;
            }
            res = max(res, r - l);
            // if (l < r){
            ma[s[l]]--;
            l++;
            // }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZuiChangBuHanZhongFuZiFuDeZiZiFuChuanLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().zuiChangBuHanZhongFuZiFuDeZiZiFuChuanLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}