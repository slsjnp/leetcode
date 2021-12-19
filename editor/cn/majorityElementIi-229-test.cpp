// 2021-10-22 23:49:48
#include <gtest/gtest.h>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // vector<int> majorityElement(vector<int>& nums) {
    //     map<int, int> ma;
    //     int size = nums.size();
    //     for (int i = 0; i < size; ++i) {
    //         if (ma.count(nums[i])){
    //             ma[nums[i]]++;
    //         }
    //         else{
    //             ma[nums[i]] = 1;
    //         }
    //     }
    //     vector<int> res;
    //     int target = size / 3;
    //     for (auto i: ma) {
    //         if (i.second > target){
    //             res.push_back(i.first);
    //         }
    //     }
    //     return res;
    // }
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        int a = -1, b = -1;
        int a1 = 0, b1 = 0;
        for (int i: nums) {
            if (i==a && a1 != 0) a1++;
            else if (i == b && b1 != 0) b1++;
            else if (a1==0 && ++a1 >= 0) a = i;
            else if (b1==0 && ++b1 >= 0) b = i;
            else {
                a1--;
                b1--;
            }
        }
        a1 = 0;
        b1 = 0;
        for (int i: nums) {
            if (a==i){
                a1++;
            }
            else if (b==i){
                b1++;
            }
        }
        if (a1 > (size/3)){
            res.push_back(a);
        }
        if (b1 > (size/3)){
            res.push_back(b);
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(MajorityElementIi, Example1) {      // NOLINT
        std::vector<int> nums = {4,1,2,3,4,4,3,2,1,4};
        auto ans = Solution().majorityElement(nums);
        decltype(ans) rightAns = {1};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}