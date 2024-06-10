// 2021-10-15 23:36:10
#include <gtest/gtest.h>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        string s = countAndSay(n - 1);
        // string s = to_string(str_s);
        string res;
        int count = 1;
        int i = 1;
        // if (s.length() == 1){
        //     return "11";
        // }
        for (; i < s.length(); ++i) {
            if (s[i-1] != s[i]){
                for(auto a:to_string(count)){
                    res.push_back(a);
                }
                res.push_back(s[i-1]);
                count = 1;
            }
            else{
                count++;
            }
        }
        for(auto a:to_string(count)){
            res.push_back(a);
        }
        res.push_back(s[i-1]);
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CountAndSay, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        int nums = 4;
        auto ans = Solution().countAndSay(nums);
        decltype(ans) rightAns = "1211";
        ASSERT_EQ(ans, rightAns);
    }

    // TEST(CountAndSay, solution) {      // NOLINT
    //     std::vector<int> nums = { };
    //     auto ans = Solution().countAndSay(nums);
    //     decltype(ans) rightAns = ;
    //     ASSERT_EQ(ans, rightAns);
    // }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}