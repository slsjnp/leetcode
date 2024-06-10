// 2022-01-08 01:06:00
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int _size = nums.size();
        int low;
        int high;
        int mid;
        int k;
        int ans = 0;
        for (int i = 0; i < _size; ++i) {
            k = target - nums[i];
            if (k < nums[j + 1]){
                break;
            }
            for (int j = i + 1; j < _size; ++j) {
                low = j;
                high = _size - 1;
                k -= nums[j];
                if (k < nums[j + 1]){
                    break;
                }
                while(low <= high){
                    mid = low + (high - low) / 2;
                    if (nums[mid] == k){
                        high = mid - 1;
                    }
                    else if(nums[mid] > k){
                        high = mid - 1;
                    }
                    else if(nums[mid] < k){
                        low = mid + 1;
                    }
                }
                ans += low - j + 1;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ThreeSumSmaller, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().threeSumSmaller(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}