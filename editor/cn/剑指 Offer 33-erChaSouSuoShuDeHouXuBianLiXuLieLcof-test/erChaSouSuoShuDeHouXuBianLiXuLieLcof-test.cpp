// 2022-08-24 22:46:12
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //维护一个单调递减栈
    //遍历给的后序遍历结果
    //当访问右子树时，单调递增，将其压入栈
    //当开始访问左子树时，栈顶的元素比接下来的大，将大于新进右子树节点都弹出栈，维护最后一个弹出栈的值maxPre
    //maxPre是弹出栈的节点最大值，但是接下来遍历节点的最小值
    //异常时：若下一个遍历的节点值大于maxPre，则表示不是后序遍历
    bool verifyPostorder(vector<int> &postorder) {
        int _size = postorder.size();
        stack<int> st;
        int root = INT_MAX;
        // st.push(postorder[0]);
        for (int i = _size - 1; i >= 0; --i) {
            if (postorder[i] > root) {
                return false;
            }
            while (!st.empty() && postorder[i] < st.top()) {
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;

    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ErChaSouSuoShuDeHouXuBianLiXuLieLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().erChaSouSuoShuDeHouXuBianLiXuLieLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}