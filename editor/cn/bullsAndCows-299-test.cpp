// 2021-11-08 23:08:30
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string getHint(string secret, string guess) {
        // unordered_map<char, int> ma;
        // unordered_map<char, int> ma2;
        vector<int> ma(10, 0);
        vector<int> ma2(10, 0);
        int a = 0,b = 0;
        for (int i = 0; i < secret.length(); ++i) {
            int flag = 1;
            int flag2 = 1;
            if (secret[i] == guess[i]){
                a++;
                flag = 0;
                flag2 = 0;
            }
            if (flag and ma[guess[i] - '0'] > 0){
                b++;
                ma[guess[i] - '0']--;
                flag = 0;
            }
            if (flag2 and ma2[secret[i] - '0'] > 0){
                b++;
                ma2[secret[i] - '0']--;
                flag2 = 0;
            }
            if (flag) {
                if (ma2[guess[i] - '0'] == 0) ma2[guess[i] - '0'] = 1;
                else ma2[guess[i] - '0']++;
            }
            if (flag2){
                if (ma[secret[i] - '0'] == 0) ma[secret[i] - '0'] = 1;
                else ma[secret[i] - '0']++;
            }
        }
        // se.clear();
        return to_string(a) + "A" + to_string(b) + "B";

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BullsAndCows, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        string nums = "1234";
        string a = "0111";
        auto ans = Solution().getHint(nums, a);
        decltype(ans) rightAns = "0A1B";
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}