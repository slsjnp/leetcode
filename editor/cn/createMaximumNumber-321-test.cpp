// 2022-02-14 16:36:41
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int start = max(0, k - (int)nums1.size()), end = min(k, (int)nums2.size());
        vector<int> ans(k, 0);
        if(nums1.size() + nums2.size() == k){
            return merge(nums1, nums2, k);
        }
        // printf("\n");
        for (int i = start; i <= end; ++i) {
            // printf("%d ",i);
            vector<int> res1 = maxVector(nums1, k - i), res2 = maxVector(nums2, i);
            // for (auto it:res1) printf("%d ",it);
            // printf("\n");

            vector<int> res = merge(res1, res2, k);


            if (compare(res, 0, ans, 0)){
                ans = res;
                // for (auto it:ans) printf("%d ",it);
                // printf("\n");
            }
        }
        return ans;
    }
    bool compare(vector<int> &res1, int l1, vector<int> &res2, int l2){
        int size = min(res1.size() - l1, res2.size() - l2);
        for (int i = 0; i < size; ++i) {
            if (res1[l1] > res2[l2]){
                return true;
            }
            else if (res1[l1] < res2[l2]){
                return false;
            }
            l1++;
            l2++;
        }
        if(res1.size() - l1 > res2.size() - l2) return true;
        return false;
    }

    vector<int> merge(vector<int> &res1, vector<int> &res2, int k) {
        int l1 = 0, l2 = 0;
        int _size1 = res1.size();
        int _size2 = res2.size();
        int l = 0;
        vector<int> res(k, 0);
        while (l < k) {
            while (l < k and l1 < _size1 and l2 < _size2) {
                // vector<int> v1(res1.begin() + l1, res1.end());
                // vector<int> v2(res2.begin() + l2, res2.end());
                if (compare(res1, l1, res2, l2)) {
                    res[l] = res1[l1];
                    l1++;
                } else {
                    res[l] = res2[l2];
                    l2++;
                }
                l++;
            }
            while (l < k and l1 == _size1 and l2 < _size2) {
                res[l] = res2[l2];
                l2++;
                l++;
            }
            while (l < k and l2 == _size2 and l1 < _size1) {
                res[l] = res1[l1];
                l1++;
                l++;
            }
        }
        return res;
    }

    vector<int> maxVector(vector<int> &nums1, int k) {
        if (k == 0) return {};
        int l1 = 0;
        vector<int> res;
        int _size1 = nums1.size();
        while (l1 < _size1) {
            while (!res.empty() and res.size() + (_size1 - l1) > k and res.back() < nums1[l1]) {
                res.pop_back();
            }
            res.push_back(nums1[l1]);
            l1++;
        }
        return vector<int> (res.begin(), res.begin() + k);
    }
};




//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CreateMaximumNumber, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().createMaximumNumber(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}