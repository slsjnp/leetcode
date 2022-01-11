// 2022-01-10 14:23:18
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string _num;
    int _size;
    vector<vector<int>> res;
    bool isAdditiveNumber(string num) {
        // if (num[0] == '0') return false;
        _num = num;
        _size = num.size();
        return dfs(0);
    }

    bool dfs(int l) {
        int m = res.size();
        if (l == _size) return m >= 3;
        int _max = _num[l] == '0' ? l + 1 : _size;
        // long long pre = 0;
        vector<int> cur;
        for (int i = l; i < _max; ++i) {
            cur.push_back(_num[i] - '0');
            // while(i + 1 < _size and _num[i + 1] == '0'){
            //     cur.push_back(0);
            //     i++;
            // }
            if (m < 2 or check(res[m - 2], res[m - 1], cur)){
                res.push_back(cur);
                if (dfs(i + 1)) return true;
                res.pop_back();
            }
            // cur.pop_back();
        }
        return false;
    }

    bool check(vector<int>& a, vector<int>& b, vector<int>& c){
        vector<int> ans;
        int t = 0;
        for (int i = 0; i < a.size() or i < b.size(); ++i) {
            if (i < a.size()) t += a[i];
            if (i < b.size()) t += b[i];
            ans.push_back(t % 10);
            t /= 10;
        }
        if (t) ans.push_back(1);
        bool ok = (c.size() == ans.size());
        for (int i = 0; i < c.size(); ++i) {
            if (c[i] != ans[c.size() - 1 - i]) return false;
        }
        return true;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(AdditiveNumber, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().additiveNumber(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}