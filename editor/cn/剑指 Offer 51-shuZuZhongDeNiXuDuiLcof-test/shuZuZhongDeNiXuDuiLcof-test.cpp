// 2022-10-01 17:58:54
#include <gtest/gtest.h>
#include "../header.h"
#include <atomic>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> tmp;
    int merge_sort(vector<int>& nums, int l, int r){
        if (l >= r){
            return 0;
        }
        atomic<int> p;
        p.load();
        int mid = l + (r - l) / 2;
        int res = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);
        int i = l;
        int j = mid + 1;
        int index = l;

        // 归并排序 保存在tmp中
        while (i <= mid && j <= r){
            if (nums[i] <= nums[j]){
                tmp[index++] = nums[i++];
                res += (j - (mid + 1));
            } else{
                tmp[index++] = nums[j++];
            }
        }
        for (int k = i; k <= mid; ++k) {
            tmp[index++] = nums[k];
            res += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[index++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return res;

    }
    int reversePairs(vector<int>& nums) {
        tmp.assign(nums.size(), 0);
        return merge_sort(nums, 0, nums.size() - 1);
        // vector<int> arr;
        // int _size = nums.size();
        // int res = 0;
        // for (int i = 0; i < _size; ++i) {
        //     auto index = std::upper_bound(arr.begin(), arr.end(), nums[i]);
        //     if (index != arr.end()){
        //         res += arr.end() - index;
        //     }
        //     arr.insert(index, nums[i]);
        // }
        // return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

namespace {
    TEST(ShuZuZhongDeNiXuDuiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().shuZuZhongDeNiXuDuiLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}