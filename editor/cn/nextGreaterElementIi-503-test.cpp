// 2021-10-26 23:45:07
#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int size_ = nums.size();
        for (int i = 0; i < size_; ++i) {
            nums.push_back(nums[i]);
        }
        int size = nums.size();
        stack<int> st;
        int ans[size];
        for (int i = size - 1; i >= 0; --i) {
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            // 此处应该存下标
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int tmp = 0;
        for (int i = 0; i < size_; ++i) {
            if (ans[i] == -1){
                res.push_back(-1);
            }
            // else if (ans[i] == 0){
            //     res.push_back(size_);
            // }
            else res.push_back(nums[ans[i]]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(NextGreaterElementIi, Example1) {      // NOLINT
        std::vector<int> nums = { 5,4, 3,2,1 };
        auto ans = Solution().nextGreaterElements(nums);
        decltype(ans) rightAns = {2, -1, 2};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}