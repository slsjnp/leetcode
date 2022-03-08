// 2022-03-06 01:00:26
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int _size = nums.size();
        int flag = 1;
        for (int i = 0; i < _size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = _size - 1;
            while (k > j) {
                while(k > j && j > i + 1 && nums[j] == nums[j - 1]) j++;
                while (k > j && nums[i] + nums[j] + nums[k] > 0) k--;
                if (k > j && nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(k > j && nums[k] == nums[k - 1]) k--;
                    k--;
                }
                j++;
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums) {
//         sort(nums.begin(), nums.end());//首先对sort进行排序
//
//         int left, right;//定义双指针
//
//         vector<vector<int>> res;//用来接收的结果容器
//
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > 0) {
//                 return res;//若第一个元素值已经大于0，则无法实现，提前结束匹配
//             }
//
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 continue;//i>0排除第一个情况，去重要保证“事后”原则，否则会漏掉{-1，-1，2}之类的三元组
//             }
//
//             left = i + 1;
//             right = nums.size() - 1;
//
//             while (left < right) {//第二层循环开始，采用双指针原则
//
//                 if (nums[i] + nums[left] + nums[right] > 0) {
//                     right--;
//                 } else if (nums[i] + nums[left] + nums[right] < 0) {
//                     left++;
//                 } else {
//                     res.push_back({nums[i], nums[left], nums[right]});//相等则插入结果容器
//                     //下面进对left和right的去重操作，选在发生匹配后进行，没发生匹配则不进行去重。如果没发生时匹配去重，则会漏掉诸如{-4，0，1，2，2，3}中{-4，2，2}这样的三元组
//                     while (left < right && nums[right] == nums[right - 1]) right--;
//                     while (left < right && nums[left] == nums[left + 1]) left++;
//                     right--;
//                     left++;
//
//                 }
//
//             }
//         }
//         return res;
//     }
// };

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(OneFGaJU, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().oneFGaJU(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}