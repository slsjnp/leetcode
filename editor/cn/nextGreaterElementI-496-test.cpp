// 2021-10-26 21:49:59
#include <gtest/gtest.h>
// #include <vector>
// #include <unordered_set>
// #include <stack>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> ma;
        int ans[nums2.size()];
        int i = nums2.size() - 1;
        for (; i >= 0 ; --i) {
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop(); // 矮个子出站，反正会被挡住
            }
            ma[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for (int j = 0; j < nums1.size(); ++j) {
            res.push_back(ma.find(nums1[j])->second);
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(NextGreaterElementI, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().nextGreaterElementI(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}