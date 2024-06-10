// 2022-01-08 19:13:46
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        int _size = nums.size();
        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int len = nums.size();
//         int left = 1;
//         int right = len - 1;
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//
//             int cnt = 0;
//             for (int num : nums) {
//                 if (num <= mid) {
//                     cnt += 1;
//                 }
//             }
//
//             // 根据抽屉原理，小于等于 4 的个数如果严格大于 4 个，此时重复元素一定出现在 [1..4] 区间里
//             if (cnt > mid) {
//                 // 重复元素位于区间 [left..mid]
//                 right = mid;
//             } else {
//                 // if 分析正确了以后，else 搜索的区间就是 if 的反面区间 [mid + 1..right]
//                 left = mid + 1;
//             }
//         }
//         return left;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FindTheDuplicateNumber, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().findTheDuplicateNumber(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}