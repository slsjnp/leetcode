// 2022-03-06 23:38:02
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int _size = nums.size();
        unordered_map<int, int> ma;
        int sum = 0;
        for (int i = 0; i < _size; ++i) {
            int left = 0, right = 0;
            int now = nums[i];
            if (ma.count(nums[i])) continue;
            if (ma.count(nums[i] + 1)){
                right = ma[nums[i] + 1];
            }
            if (ma.count(nums[i] - 1)){
                left = ma[nums[i] - 1];
            }
            ma[nums[i]] = left + right + 1;
            ma[nums[i] - left] = ma[nums[i]];
            ma[nums[i] + right] = ma[nums[i]];
            sum = max(sum, ma[nums[i]]);
        }
        return sum;
    }
};
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int _size = nums.size();
//         sort(nums.begin(), nums.end());
//         int sum = 0;
//         for (int i = 0; i < _size; i++) {
//             int tmp = 0;
//             int j = i + 1;
//             for (; j < _size; ++j) {
//                 if (nums[j] == nums[j - 1]) {
//                     tmp++;
//                     continue;
//                 }
//                 if (abs(nums[j] - nums[j - 1]) != 1) break;
//             }
//             tmp = j - i - tmp;
//             sum = max(tmp, sum);
//         }
//         return sum;
//
//     }
// };

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LongestConsecutiveSequence, Example1) {      // NOLINT
        std::vector<int> nums = { 100,4,200,1,3,2 };
        auto ans = Solution().longestConsecutive(nums);
        decltype(ans) rightAns = 4;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}