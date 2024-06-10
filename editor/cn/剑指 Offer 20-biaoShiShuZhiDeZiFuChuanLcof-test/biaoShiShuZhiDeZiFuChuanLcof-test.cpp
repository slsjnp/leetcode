// 2022-08-23 11:21:21
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isNumber(string s) {
        string::iterator s_it = s.begin();
        int _size = 0;
        while(s_it != s.end()){
            if (*s_it == ' '){
                _size++;
            } else{
                break;
            }
        }

        string ss(s.begin() + _size, s.end());
        unordered_map<char, int> se;
        for(auto it : ss){
            se[it]++;
        }
        if (se['+'] + se['-'] > 1 || se['.'] > 1 || se['e'] + se['E'] > 1){
            return false;
        }



        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BiaoShiShuZhiDeZiFuChuanLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().biaoShiShuZhiDeZiFuChuanLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}