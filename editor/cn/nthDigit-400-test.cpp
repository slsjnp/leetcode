// 2021-11-30 17:33:41
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10){
            return n;
        }
        vector<long> res;
        // res.push_back(0);
        long sum = 0;
        int ind = 1;
        long nums = 9;
        while (sum < (long)1 << 40){
            res.emplace_back(sum);
            sum += nums * ind;
            ind++;
            nums *= 10;
        }
        int it = upper_bound(res.begin(), res.end(), n) - res.begin();

        // if (it == res.size()){
        //
        // }
        int tmp = n - res[it - 1];
        printf("%d\n", tmp);
        // 第多少个数
        sum = 1;
        for (int i = 1; i < it; ++i) {
            sum *= 10;
        }
        // 数字
        string s ;
        // if (tmp < it) s = to_string(sum);
        s = to_string(sum + (tmp - 1) / it);
        printf("%s\n", s.c_str());
        // 第几个
        int i = (tmp - 1) % it;
        printf("%d", i);
        return s[i] - '0';
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(NthDigit, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        auto ans = Solution().findNthDigit(999999999);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}