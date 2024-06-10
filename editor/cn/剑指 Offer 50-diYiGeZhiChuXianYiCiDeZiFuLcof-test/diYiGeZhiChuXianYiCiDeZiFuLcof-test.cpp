// 2022-10-01 17:56:24
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> ma;
        int _size = s.size();
        for (int i = _size - 1; i >= 0; --i) {
            ma[s[i]]++;
        }
        for (auto it: ma) {
            if (it.second == 1){
                return it.first;
            }
        }
        return ' ';

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DiYiGeZhiChuXianYiCiDeZiFuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().diYiGeZhiChuXianYiCiDeZiFuLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}