// 2021-11-05 21:02:41
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int s_size = s.length();
        int w_size = words.size();
        int ws_size = words[0].length();
        int ind = 0;
        map<string, int> ma;
        int stat[s_size - ws_size + 10];
        vector<int> res;
        memset(stat, 0, sizeof(stat));
        // 初始化map
        int sum = 1;
        int flag = 0;
        for (int i = 0; i < w_size; ++i) {
            if (ma.count(words[i]) == 0) {
                ma[words[i]] = 1;
            } else {
                ma[words[i]] += 1;
            }
        }
        int l = 0, r = ws_size;
        int times;
        map<string, int> ma2;
        // 滑动窗口迭代 ,计算hash_map
        while (ind < ws_size) {
            l = ind;
            times = 0;
            while (l < s_size) {
                times++;
                if (l + ws_size <= s_size) {
                    string _s = string(l + s.begin(), s.begin() + l + ws_size);
                    if (ma.count(_s)) {
                        if (times > w_size) {
                            ma2[string(l - ws_size * w_size + s.begin(),
                                       s.begin() + l - ws_size * w_size + ws_size)] -= 1;
                        }
                        if (ma2.count(_s)) {
                            ma2[_s] += 1;
                        } else {
                            ma2[_s] = 1;
                        }
                    } else {
                        ma2.clear();
                        times = 0;
                    }
                    if (ma == ma2) {
                        res.push_back(l - (w_size - 1) * ws_size);
                    }
                }

                l += ws_size;
            }
            ind++;
            ma2.clear();
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SubstringWithConcatenationOfAllWords, Example1) {      // NOLINT
        std::vector<string> nums = {"aa", "aa"};
        // ["bar","foo","the"]
        string s = "aaaaaaaaaaaaaa";
        auto ans = Solution().findSubstring(s, nums);
        decltype(ans) rightAns = {8};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}