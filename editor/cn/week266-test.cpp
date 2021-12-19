//
// Created by sj on 2021/11/7.
//


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
    long long countVowels(string word) {
        int _size = word.length();
        unordered_set<char> se = {'a', 'e', 'i', 'o', 'u'};
        int dp[_size];
        memset(dp, 0, sizeof(dp));
        int count;
        dp[0] = se.count(word[0]) ? 1 : 0;
        count = dp[0];
        long long sum = dp[0];
        for (int i = 1; i < _size; ++i) {
            if (se.count(word[i])) {
                count++;
                dp[i] = dp[i - 1] + i + 1;
            }
            else dp[i] = dp[i - 1];
            sum += dp[i];
        }
        return sum;
    }
};

// class Solution {
// public:
//     int countVowelSubstrings(string word) {
//         int _size = word.length();
//         unordered_map<char, int> ma;
//         int ind = 0;
//         int l = ind;
//         int times;
//         int count = 0;
//         unordered_set<char> se = {'a','e','i','o','u'};
//         int flag = 0;
//         int r;
//         while (ind < _size){
//             l = ind;
//             while (l <= _size){
//                 if (ma.size() == 5){
//                     count++;
//                     flag = 1;
//                 }
//                 if (se.count(word[l])){
//                     if (ma.count(word[l])){
//                         ma[word[l]] += 1;
//                     }
//                     else {
//                         ma[word[l]] = 1;
//                     }
//                 }
//                 else {
//                     // ma.clear();
//                     break;
//                 }
//                 l++;
//             }
//             ma.clear();
//             ind++;
//         }
//         return count;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Shoppin, Example2) {      // NOLINT
        // string s = "noosabasboosa";
        string s = "abc";
        auto ans = Solution().countVowels(s);
        decltype(ans) rightAns = 237;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
