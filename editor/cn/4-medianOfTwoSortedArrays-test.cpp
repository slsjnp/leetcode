// 2022-03-12 14:05:44
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1l = nums1.size();
        int n2l = nums2.size();
        int x = n1l + n2l;
        if (x & 1){
            return (double) findKth(nums1, nums2, (x + 1) / 2);
        }
        return (double) (findKth(nums1, nums2, x / 2) + findKth(nums1, nums2, x / 2 + 1)) / 2.0;

    }
    int findKth(vector<int> &n1, vector<int> &n2, int k){
        int n1l = n1.size();
        int n2l = n2.size();

        int l = 0;
        int r = 0;
        while (true){
            if (l == n1l){
                return n2[r + k - 1];
            }
            if (r == n2l){
                return n1[l + k - 1];
            }
            if (k == 1){
                return min(n1[l], n2[r]);
            }

            int ll = min(l + k / 2 - 1, n1l - 1);
            int rr = min(r + k / 2 - 1, n2l - 1);
            if (n1[ll] <= n2[rr]){
                k -= ll - l + 1;
                l = ll + 1;
            }
            else{
                k -= rr - r + 1;
                r = rr + 1;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MedianOfTwoSortedArrays, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().medianOfTwoSortedArrays(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}