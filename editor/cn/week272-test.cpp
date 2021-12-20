//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int kIncreasing(vector<int> &arr, int k) {
        vector<int> tmp = arr;
        int _size = arr.size();
        int pre;
        // if (arr[0] > arr[1]){
        //     arr[0] = 0;
        // }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            if (arr[i] > arr[i + k]){
                arr[i] = t;
                t++;
            }
            pre = arr[i];
            for (int j = i; j < _size; j+=k) {
                if (arr[j] > pre){
                    continue;
                }
                else{
                    arr[j] = pre + 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < _size; ++i) {
            if (tmp[i] != arr[i]){
                sum++;
            }
        }
        return sum;


    }
};

// class Solution {
// public:
//     string addSpaces(string s, vector<int>& spaces) {
//         string res;
//         int _size = s.size();
//         int s_size = spaces.size();
//         int t = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (t < s_size and i == spaces[t]){
//                 res += " ";
//                 t++;
//             }
//             res += s[i];
//
//
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     string firstPalindrome(vector<string>& words) {
//         int _size = words.size();
//         string tmp;
//         for (int i = 0; i < _size; ++i) {
//             tmp = words[i];
//             reverse(words[i].begin(), words[i].end());
//             if (tmp == words[i]){
//                 return tmp;
//                 // break;
//             }
//         }
//         return "";
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week272, Example2) {      // NOLINT
        // std::vector<int> nums = { 10,83,53};
        // string s = "**|**|***|";
        vector<vector<int>> t = {{1, 5, 3},
                                 {1, 5, 1},
                                 {6, 6, 5}};
        // vector<int> n = {3, 2};
        auto ans = Solution().maxTwoEvents(t);
        decltype(ans) rightAns = 8;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
