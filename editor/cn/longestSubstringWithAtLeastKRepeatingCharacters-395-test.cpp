// 2022-02-01 16:03:17
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k == 1)
            return s.size();
        if (s.size() < k)
            return 0;
        return longestSubstring(s, 0, s.size() - 1, k);
    }

    int longestSubstring(string &str, int start, int end, int k) {
        if (start >= end || end - start + 1 < k)
            return 0;
        vector<int> count(26, 0);
        for (int i = start; i <= end; i++) {
            ++count[str[i] - 'a'];
        }

        bool needSplit = false;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < k) {
                needSplit = true;
                break;
            }
        }
        if (!needSplit)
            return end - start + 1;

        int ret = 0;
        int left = start, right = start;
        while (right <= end) {
            while (left <= end) {
                if (count[str[left] - 'a'] >= k)
                    break;
                ++left;
            }
            right = left + 1;

            while (right <= end) {
                if (count[str[right] - 'a'] > 0 && count[str[right] - 'a'] < k)
                    break;
                ++right;
            }

            if (right - left > ret)
                ret = max(ret, longestSubstring(str, left, right - 1, k));

            left = right + 1;
        }
        return ret;
    }
};
// class Solution {
// public:
//
//     int longestSubstring(string s, int k) {
//         int _size = s.size();
//         if (k == 1) return _size;
//         if (_size < k) return 0;
//         return longestSubstring(s, 0, _size - 1, k);
//     }
//
//     int longestSubstring(string &s, int l, int r, int k) {
//         int _size = r - l + 1;
//         if (_size < k) return 0;
//         unordered_map<char, vector<int>> counter;
//         unordered_set<char> chars(s.begin() + l, s.begin() + r + 1);
//         for (int i = l; i <= r; ++i) {
//             counter[s[i]].emplace_back(i);
//         }
//         for (char c: chars) {
//             // vector<string> t;
//             vector<pair<int, int>> t;
//             if (counter[c].size() < k) {
//                 // 切分字符串( origin string, tmp vector<string>, char c)
//                 split(s, l, r, t, counter, c);
//                 int res = 0;
//                 for (auto it : t) {
//                     int i = it.first, j = it.second;
//                     res = max(res, longestSubstring(s, i, j - 1, k));
//                 }
//                 return res;
//             }
//         }
//         return _size;
//     }
//
//     void
//     split(string &s, int l, int r, vector<pair<int, int>> &t,
//           unordered_map<char, vector<int>> &counter, const char flag = ' ') {
//         t.clear();
//         int pre = l;
//         for (int i = 0; i < counter[flag].size(); ++i) {
//             if (pre < counter[flag][i]){
//                 t.emplace_back(pre, counter[flag][i]);
//                 pre = counter[flag][i] + 1;
//             }
//         }
//         if (*counter[flag].rbegin() + 1 != r + 1) t.emplace_back(pair<int, int>{*counter[flag].rbegin() + 1, r + 1});
//
//         // istringstream iss(s);
//         // string tmp;
//         // while(getline(iss, tmp, flag)){
//         //     t.emplace_back(tmp);
//         // }
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestSubstringWithAtLeastKRepeatingCharacters, Example1) {      // NOLINT
        std::string nums = "bbaaacbd";
        auto ans = Solution().longestSubstring(nums, 3);
        decltype(ans) rightAns = 3;
        ASSERT_EQ(ans, rightAns);
    }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}