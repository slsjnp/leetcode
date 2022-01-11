//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// class Root{
// public:
//     struct TreeNode{
//         TreeNode* parent;
//         TreeNode* left;
//         TreeNode* right;
//     };
// };
class Solution {
public:
    unordered_map<int, vector<int>> ma;
    unordered_map<int, vector<int>> ml;
    int countHighestScoreNodes(vector<int> &parents) {
        int _size = parents.size();
        int root = 0;
        for (int i = 0; i < _size; ++i) {
            ma[parents[i]].emplace_back(i);
        }
        root = ma[-1];
        stack<int> st;
        while(ma.count(root) or !qu.empty()){
            while (ma.count(root)){
                st.push(root);
                root = ma[root][0];
            }
            root = st.top();
            qu.pop;
            if (ml.count(root) == 0){
                ml[root] = vector<int> (2);
                if (ml.count(ma[root][0])){
                    ml[root][1] = ml[ma[root][0]][1] + ;
                }
            }
            ml[root][0] = ml[ma[root][0]];
        }
        // dfs(0);
    }
    void dfs(int n){

    }
};
// class Solution {
// public:
//     int nextBeautifulNumber(int n) {
//         vector<int> res;
//         // unordered_map<int ,int> ma;
//         string s = to_string(n);
//         int _size = s.size();
//         if (s[0] > _size){
//             return "1" + s
//         }
//         int t = nextS(s);
//         while()
//     }
// };
// class Solution {
// public:
//     int countValidWords(string sentence) {
//         int _size = sentence.size();
//         vector<string> res;
//         unordered_map<int, int> ma;
//         for (int i = 0; i < _size; ++i) {
//             string s;
//             while (i < _size and sentence[i] != ' ') {
//                 s += sentence[i];
//                 i++;
//             }
//             res.emplace_back(s);
//         }
//         int sum = 0;
//         for (auto it: res) {
//             vector<int> ve(4, 0);
//             for (auto w: it) {
//                 if (w < 'a' or w > 'z') {
//                     if (w == '-') {
//                         ve[1]++;
//                     } else if (w == '!' or w == '.' or w == ',') {
//                         ve[3]++;
//                     } else {
//                         ve[3] = 2;
//                         break;
//                     }
//                 } else {
//                     if (ve[3] > 0) {
//                         ve[3]++;
//                         break;
//                     }
//                     if (ve[1] > 0) {
//                         ve[2]++;
//                     } else {
//                         ve[0]++;
//                     }
//                 }
//             }
//             if (ve[3] > 1) {
//                 continue;
//             } else if (ve[1] > 1) {
//                 continue;
//             } else if (ve[1] and (ve[2] == 0 or ve[0] == 0)) {
//                 continue;
//             } else if (ve[0] or (!ve[0] and ve[3] == 1)) {
//                 sum++;
//
//                 // printf("%s\n", it.c_str());
//             }
//         }
//         return sum;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week264, Example2) {      // NOLINT
        std::vector<int> nums = {98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821,
                                 98818, 98821, 98818};
        auto ans = Solution().getDistances(nums);
        decltype(ans) rightAns = {0, 1};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
