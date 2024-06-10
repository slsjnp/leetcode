// 2022-01-14 22:29:34
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    // string tmp;
    vector<string> tmp;
    int _size;
    string target;

    vector<string> restoreIpAddresses(string s) {
        _size = s.size();
        target = s;
        dfs(0);
        return res;
    }

    void dfs(int pos){
        if(pos == _size and tmp.size() == 4){
            string t = tmp[0];
            for (int i = 1; i < 4; ++i) {
                t += '.' + tmp[i];
            }
            res.emplace_back(t);
            return;
        }
        // printf("%d ", pos);
        if (pos + (4 - tmp.size()) * 3 < _size - pos){
            return;
        }
        int _max = pos + 3;
        if (target[pos] == '0') _max = pos + 1;
        string dig;
        for (int i = pos; i < _max and i < _size; ++i) {
            dig += target[i];
            if (stoi(dig) < 256){
                tmp.emplace_back(dig);
                dfs(i + 1);
                tmp.pop_back();
            }

        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RestoreIpAddresses, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().restoreIpAddresses(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}