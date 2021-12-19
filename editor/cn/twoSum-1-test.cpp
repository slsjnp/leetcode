// 2021-10-15 10:10:59
#include <gtest/gtest.h>
#include <vector>
#include <map>
#include<string>
#include <unordered_map>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, vector<int>> hash_map;
        std::unordered_map<int, vector<int>>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp;
            auto it = hash_map.find(nums[i]);
            if (it==hash_map.end()){
                tmp.push_back(i);
                hash_map.insert(std::pair<int, vector<int>>(nums[i], tmp));
            }
            else{
                it->second.push_back(i);
            }
        }
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()){
                if (it->second[0] == i){
                    if (it->second.size() > 1){
                        res = vector<int> {i, it->second[1]};
                        break;
                    }
                    else{
                        continue;
                    }
                }
                res = vector<int> {i, it->second[0]};
                break;
            }

        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(TwoSum, Example1) {      // NOLINT
        std::vector<int> nums = { 0,4,3,0 };
        int target = 0;
        auto ans = Solution().twoSum(nums, target);
        decltype(ans) rightAns = vector<int> {0, 1};
        ASSERT_EQ(ans, rightAns);
    }

    // TEST(TwoSum, solution) {      // NOLINT
    //     std::vector<int> nums = { };
    //     auto ans = Solution().twoSum(nums);
    //     decltype(ans) rightAns = ;
    //     ASSERT_EQ(ans, rightAns);
    // }
}
class SolutionInefficient {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, vector<int>> hash_map;
        std::unordered_map<int, vector<int>>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp;
            auto it = hash_map.find(nums[i]);
            if (it==hash_map.end()){
                tmp.push_back(i);
                hash_map.insert(std::pair<int, vector<int>>(nums[i], tmp));
            }
            else{
                it->second.push_back(i);
            }
        }
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()){
                if (it->second[0] == i){
                    if (it->second.size() > 1){
                        res = vector<int> {i, it->second[1]};
                        break;
                    }
                    else{
                        continue;
                    }
                }
                res = vector<int> {i, it->second[0]};
                break;
            }

        }
        return res;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}