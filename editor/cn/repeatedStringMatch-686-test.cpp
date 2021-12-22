// 2021-12-22 00:29:48
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int a_size = a.size();
        int b_size = b.size();
        int l = 0;
        int flag;
        int r;
        int times;
        for (int i = 0; i < a_size; ++i) {
            flag = 1;
            times = 0;
            l = 0;
            r = i;
            while (l < b_size and flag != 0) {
                if (a[r] != b[l]) {
                    flag = 0;
                }

                l++;
                if (r % a_size == i % a_size) times++;
                r = (r + 1) % a_size;

            }
            if (flag) {
                break;
            }
        }
        if (flag != 0) {
            if (a_size > b_size) {
                for (int i = 0; i < a_size; ++i) {
                    flag = 1;
                    times = 0;
                    l = 0;
                    r = i;
                    while (l < b_size and flag != 0) {
                        if (a[r] != b[l]) {
                            flag = 0;
                        }

                        l++;
                        r = (r + 1) % a_size;

                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    return 1;
                } else return 2;
            }
            // if (a[0] != b[0] or a_size > b_size){
            //     return times+1;
            // }

            //     return 1 + ceil(b_size / (float ) a_size);
            // }
            // return ceil(b_size / (float ) a_size);
            if (ceil(b_size / (float) a_size) > 1) {
                return times + 1;
            }
        } else {
            return -1;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RepeatedStringMatch, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().repeatedStringMatch(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}