//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// class Solution {
// public:
//     vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
//         int _size = queries.size();
//         vector<long long> res(_size);
//         for (int i = 0; i < _size; ++i) {
//             res[i] = generate_tmp(intLength, queries[i] - 1);
//         }
//         return res;
//     }
//     long long generate_tmp(int len, int m){
//         long long tmp;
//         int flag = len&1;
//         string s = "1" + string((len - 1)/2,'0');
//         int _size = s.size();
//         s = to_string(stoll(s) + m);
//         if (s.size() > _size) return -1;
//         if (flag) {
//             string tmp1 = s + rever(s.substr(0, _size - 1));
//             tmp = stoll(tmp1);
//         } else{
//             string tmp1 = s + rever(s);
//             tmp = stoll(tmp1);
//         }
//         return tmp;
//     }
//
//     string rever(string s){
//         std::reverse(s.begin(), s.end());
//         return s;
//     }
// };

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int _size = nums.size();
        int flag = 0;
        int sum = 0;
        int pre = 0;
        for (int i = 0; i < _size; ++i) {
            if (flag){
                if (pre != nums[i]){
                    sum++;
                    flag = 0;
                }
            } else {
                sum++;
                flag = 1;
                pre = nums[i];
            }
        }
        if (sum & 1) sum--;
        return _size - sum;
    }
};

// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> se1(nums1.begin(), nums1.end());
//         unordered_set<int> se2(nums2.begin(), nums2.end());
//         vector<vector<int>> res(2);
//         std::sort(nums1.begin(), nums1.end());
//         std::sort(nums2.begin(), nums2.end());
//         for (int i = 0; i < nums1.size(); ++i) {
//             if (i > 0 && nums1[i] == nums1[i - 1]) continue;
//             if (se2.count(nums1[i]) == 0){
//                 res[0].push_back(nums1[i]);
//             }
//         }
//         for (int i = 0; i < nums2.size(); ++i) {
//             if (i > 0 && nums2[i] == nums2[i - 1]) continue;
//             if (se1.count(nums2[i]) == 0){
//                 res[1].push_back(nums2[i]);
//             }
//         }
//
//         return res;
//     }
// };

//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week286, Example2) {      // NOLINT
        std::vector<int> nums = {0,0,0,0,0,2,0,5,1,1,0,0};

        // vector<vector<int>> nums = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
        // vector<vector<int>> nums = {{0, 1, 1},
        //                             {2, 1, 1}};
        auto ans = Solution().maximumBobPoints(9, nums);
        decltype(ans) rightAns = {};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
