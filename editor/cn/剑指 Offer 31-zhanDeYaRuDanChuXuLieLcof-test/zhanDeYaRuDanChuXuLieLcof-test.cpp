// 2022-08-24 20:30:21
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int _size = pushed.size();
        int pop_size = popped.size();
        if (_size != pop_size) return false;
        if (_size == 0) return true;
        int l = 0;
        int start = -1;
        vector<int> res;
        int top = -1;
        for (int i = 0; i < _size; ++i) {
            if (!res.empty()) {
                top = res.back();
            }
            while (top == popped[l]) {
                res.pop_back();
                l++;
                if (!res.empty()) {
                    top = res.back();
                } else {
                    break;
                }
            }
            res.push_back(pushed[i]);
        }
        if (!res.empty()) {
            top = res.back();
        }
        while (top == popped[l]) {
            res.pop_back();
            l++;
            if (!res.empty()) {
                top = res.back();
            } else {
                break;
            }
        }
        if (res.empty()){
            return true;
        } else{
            return false;
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZhanDeYaRuDanChuXuLieLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().zhanDeYaRuDanChuXuLieLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}