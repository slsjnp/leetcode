// 2021-10-28 18:29:45
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        int size = s.length();
        unordered_map<int, vector<string>> ma;
        int sum = 1;
        string tmp;
        for (int i = 0; i <= 30; ++i) {
            tmp = to_string(sum);
            if (ma.find(tmp.length()) == ma.end()){
                vector<string> st = {tmp};
                ma[tmp.length()] = st;
            }
            else{
                ma[tmp.length()].push_back(tmp);
            }
            sum <<= 1;
        }
        vector<string> res = ma[size];
        for (auto i: res) {
            bool ans = equ(i, s);
            if (ans){
                return ans;
            }
        }
        return false;
    }
    // 状态转移 ind , str , bit_map,
    bool equ(string a, string b, int bit = 0){
        for (int i = 0; i < a.length(); ++i) {
            for (int j = 0; j < b.length(); ++j) {
                if (a[i] == b[j]){
                    if (!(bit & (1<<j))){
                        bit |= (1 << j);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < a.length(); ++i) {
            if (bit & (1 << i)){
                continue;
            }
            return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ReorderedPowerOf2, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        int nums = 1;
        auto ans = Solution().reorderedPowerOf2(nums);
        decltype(ans) rightAns = true;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}