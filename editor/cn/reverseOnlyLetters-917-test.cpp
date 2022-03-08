// 2022-02-25 00:17:35
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int _size = s.size();
        string res;
        int i = 0;
        int r = _size - 1;
        while(i < _size){
            if (!(s[i] >= 'A' and s[i] <= 'Z') and !(s[i] <= 'z' and s[i] >= 'a')){
                res += s[i];
            }
            else{
                while (r >= 0 and !(s[r] >= 'A' and s[r] <= 'Z') and !(s[r] <= 'z' and s[r] >= 'a')){
                    r--;
                }
                if (r >= 0){
                    res += s[r];
                    r--;
                }
            }
            i++;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ReverseOnlyLetters, Example1) {      // NOLINT
        std::string nums ="ab-cd";
        auto ans = Solution().reverseOnlyLetters(nums);
        decltype(ans) rightAns = "";
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}