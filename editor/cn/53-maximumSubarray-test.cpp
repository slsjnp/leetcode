// 2022-03-11 17:52:18
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &nums, int l, int r){
        if (l == r){
            return (Status) {nums[l], nums[l], nums[l], nums[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(nums, l, m);
        Status rSub = get(nums, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int> &nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int _size = nums.size();
//         // long long dp[_size + 1];
//         // memset(dp, 0, sizeof(dp));
//         long long sum = nums[0];
//         long long pre = nums[0];
//         for (int i = 1; i < _size; ++i) {
//             pre = max((long long)nums[i], pre + nums[i]);
//             sum = max(sum, pre);
//         }
//         return sum;
//         // vector<long long >res;
//         // int l = 0;
//         // long long pre = 0;
//         // while (l < _size) {
//         //     pre = 0;
//         //     while (l < _size && nums[l] > 0){
//         //         pre += nums[l];
//         //         l++;
//         //     }
//         //     res.push_back(pre);
//         //     pre = 0;
//         //     while (l < _size && nums[l] < 0){
//         //         pre += nums[l];
//         //         l++;
//         //     }
//         //     res.push_back(pre);
//         // }
//         // for (int i = 0; i < _size; ++i) {
//         //     if (nums[i] + nums[i + 1] > 0){
//         //     }
//         // }
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MaximumSubarray, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().maximumSubarray(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}