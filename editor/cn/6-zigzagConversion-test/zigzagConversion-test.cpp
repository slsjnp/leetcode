// 2022-10-23 10:34:55
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        auto cmp = [](int x, int y)->bool {
            if ((x & 1) != (y & 1)) return (x & 1) < (y & 1);
            return x < y;
        };
        std::sort(nums.begin(), nums.end(), cmp);
        std::sort(target.begin(), target.end(), cmp);
        int _size = nums.size();
        long long res = 0;
        for (int i = 0; i < _size; ++i) {
            res += abs(target[i] - nums[i]) / 2;
        }
        return res / 2;
    }
};
// class Solution {
// public:
//     int sum = 0;
//     vector<int> arr;
//     vector<int> tmp;
//     int _size;
//
//     int subarrayGCD(vector<int> &nums, int k) {
//         // printf("%d", gcd(9, 3));
//         _size = nums.size();
//         int flag;
//         for (int i = 0; i < _size; ++i) {
//             if (nums[i] == k){
//                 flag = 1;
//                 sum++;
//             } else{
//                 flag = 0;
//             }
//             for (int j = i + 1; j < _size; ++j) {
//                 if (flag == 0 && gcd(nums[i], nums[j]) == k){
//                     flag = 1;
//                     sum++;
//                 } else if (flag == 1 && gcd(nums[j], k) == k){
//                     sum++;
//                 } else{
//                     break;
//                 }
//             }
//         }
//         return sum;
//     }
//
//     // bool check(int b, int k) {
//     //     if (tmp.empty()) {
//     //         return k == b;
//     //     }
//     //     // int tmp_size = tmp.size();
//     //     // for (int i = 0; i < tmp_size; ++i) {
//     //     if (gcd(k, b) != k) {
//     //         return false;
//     //     }
//     //     // }
//     //     return true;
//     // }
//
//     int gcd(int a, int b) {
//         if (a > b) {
//             swap(a, b);
//         }
//         while (b > a && a != 0) {
//             b = b % a;
//             if (a > b) {
//                 swap(a, b);
//             }
//         }
//         return b;
//     }
// };
// class Solution {
// public:
//     bool haveConflict(vector<string>& event1, vector<string>& event2) {
//         int l1 = stoi(event1[0].substr(0,2));
//         int ll1 = stoi(event1[0].substr(3,2));
//         int e1 = stoi(event1[1].substr(0,2));
//         int ee1 = stoi(event1[1].substr(3,2));
//         int s1 = l1 * 60 + ll1;
//         int end1 = e1 * 60 + ee1;
//
//         int l2 = stoi(event2[0].substr(0,2));
//         int ll2 = stoi(event2[0].substr(3,2));
//         int e2 = stoi(event2[1].substr(0,2));
//         int ee2 = stoi(event2[1].substr(3,2));
//         int s2 = l2 * 60 + ll2;
//         int end2 = e2 * 60 + ee2;
//
//         printf("%d %d", s1, end1);
//
//         if ((s2 >= s1 && s2 <= end1) || (s1 >= s2 && s1 <= end2)){
//             return true;
//         } else{
//             return false;
//         }
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ZigzagConversion, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().zigzagConversion(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}