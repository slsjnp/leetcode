// 2022-03-06 19:31:17
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        int _size = height.size();
        // vector<int> res(_size, -1);
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < _size ; ++i) {
            while(!st.empty() && height[st.top()] < height[i]){
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                sum += (r - l - 1) * h;
            }
            st.push(i);
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(TrappingRainWater, Example1) {      // NOLINT
        std::vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
        auto ans = Solution().trap(nums);
        decltype(ans) rightAns = 6;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}