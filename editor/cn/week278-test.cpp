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
    // check
        // 相 异或 是否为0 ，mask & （mask - 1） 是否为0
    // 并查集
    //
    vector<int> groupStrings(vector<string>& words) {
        // vector<int> res;
        unordered_map<int, vector<int>> ma;
        int _size = words.size();
        for (int i = 0; i < _size; ++i) {
            int s_size = words[i].size();
            int sum = 0;
            for (int j = 0; j < s_size; ++j) {
                sum ^= 1 << (words[i][j] - 'a');
            }
            ma[s_size].emplace_back(sum);
        }
    }
};
// class Solution {
// public:
//     string s;
//
//     string subStrHash(string s, int power, int modulo, int k, int hashValue) {
//         int _size = s.size();
//         int r = k;
//         this->s = s;
//         long long ha = hash(0, power, modulo, k);
//         while (r <= _size) {
//             if (hashValue == ha % modulo) {
//                 // return tmp;
//                 string tmp = string(s.begin() + r - k, s.begin() + r);
//                 return tmp;
//             }
//             ha -= s[r - k] - 'a' + 1;
//             r++;
//             if (r <= _size) {
//                 auto i = (int) pow(power, k) % modulo;
//                 ha += i * (s[r] - 'a' + 1) % modulo;
//             }
//             ha /= power;
//         }
//         return "";
//     }
//
//     long long hash(int l, int p, int m, int k) {
//         long long res = 0;
//         long long tmp = 1;
//         for (int i = 0; i < k; ++i) {
//             res += (s[i + l] - 'a' + 1) * tmp;
//             res %= m;
//             tmp = tmp * p % m;
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<int> maxScoreIndices(vector<int>& nums) {
//         int _size = nums.size();
//         vector<int> sum(_size + 1, 0);
//         for (int i = 0; i < _size; ++i) {
//             sum[i + 1] = sum[i] + nums[i];
//         }
//         int sco = 0;
//         vector<int> res;
//         for (int i = 0; i <= _size; ++i) {
//             sco = max(sco, (i - (sum[i] - sum[0])) + sum[_size] - sum[i]);
//         }
//         for (int i = 0; i <= _size; ++i) {
//             if (sco == (i - (sum[i] - sum[0])) + sum[_size] - sum[i]){
//                 res.emplace_back(i);
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     int findFinalValue(vector<int>& nums, int original) {
//         unordered_map<int, int> ma;
//         int _size = nums.size();
//         for (int i = 0; i < _size; ++i) {
//             ma[nums[i]]++;
//         }
//         while (ma.count(original)){
//             original *= 2;
//         }
//         return original;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week278, Example2) {      // NOLINT
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
