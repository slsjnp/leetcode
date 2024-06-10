// 2021-11-03 21:38:50
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ve;
    vector<vector<int>> col;
    vector<vector<int>> heightMap;
    int res;

    int trapRainWater(vector<vector<int>> &heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        this->heightMap = heightMap;
        if (m <= 2 or n <= 2) {
            return 0;
        }
        for (auto i: heightMap) {
            find_ex(i);
        }
        for (int i = 1; i < m; ++i) {
            int l = 0;
            int r = n - 1;
            while (l < n - 1 and heightMap[i][l] < heightMap[i][l + 1]) l++;
            while (r > 0 and heightMap[i][r - 1] > heightMap[i][r]) r--;
            // 找到有机会的点
            while (l < r) {
                dfs(i, l, ve[i][l]);
                l = ve[i][l];
            }
        }
    }

    bool dfs(int rol, int l, int r, int h = -1, int d = -1) {
        // 判断上和右
        while (l != r) {
            if (r == -1) {
                // 判断上
                if (heightMap[rol - 1][l + 1] > heightMap[rol][l + 1]) {
                    if (heightMap)
                }
            }
        }


    }

    void find_ex(vector<int> v) {
        // 找到下一个不低于他的点
        if (v.empty()) {
            return;
        }
        int v_size = v.size();
        vector<int> v_res[v_size];
        stack<int> st;
        for (int i = v_size - 1; i >= 0; --i) {
            while (st.size() > 0 && v[st.top()] < v[i]) {
                // 矮个子出站
                st.pop();
            }
            if (st.size() == 0) {
                v_res[i] = -1;
            } else {
                v_res[i] = st.top();
            }
            st.push(i);
        }
        ve.push_back(v_res);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(TrappingRainWaterIi, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().trappingRainWaterIi(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}