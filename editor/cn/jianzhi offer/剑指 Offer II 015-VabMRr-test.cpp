// 2022-03-10 17:18:16
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int _size = s.size();
        unordered_map<char, int> ma, mb;
        for (auto it: p) {
            mb[it]++;
        }
        int l = 0, r = 0;
        vector<int> res;
        int sum = 0;
        while(r < _size){
            char c = s[r];
            ma[c]++;
            if (mb.count(c) && ma[c] == mb[c]){
                sum++;
            }
            r++;
            while(r - l > p.size()){
                c = s[l];
                if (mb.count(c) && ma[c] == mb[c]){
                    sum--;
                }
                ma[c]--;
                l++;
            }
            if (sum == mb.size()){
                res.push_back(l);
            }
        }
        return res;

    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(VabMRr, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().VabMRr(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}