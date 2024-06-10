//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class DetectSquares {
public:
    unordered_map<int, vector<int>> m1, m2;

    DetectSquares() {
        return;
    }

    void add(vector<int> point) {
        m1[point[0]].push_back(point[1]);
        m2[point[1]].push_back(point[0]);
    }

    int count(vector<int> point) {
        int sum = 0;
        int x = point[0], y = point[1];
        vector<int> col = m1[point[0]], row = m2[point[1]];
        int times = 1, n_times = 1;
        for (int i = 0; i < col.size(); ++i) {
            int n_sum = 0;
            int len = abs(col[i] - y);
            if (col[i] - y != 0) {
                // int len = abs(col[i] - y);
                for (int j = 0; j < row.size(); ++j) {
                    if (abs(row[j] - x) == len) {
                        n_sum++;
                    }
                }
            } else {
                times++;
            }
            sum += n_sum;
        }
        for (int i = 0; i < col.size(); ++i) {
            int n_sum = 0;
            int len = abs(col[i] - y);
            if (col[i] - y != 0) {
                vector<int> tmp = m2[col[i]];
                for (int j = 0; j < tmp.size(); ++j) {
                    if (abs(tmp[j] - point[0]) == len) {
                        n_sum++;
                    }
                }
                sum += n_sum * times;
            }
        }

        // sum *= times;
        return sum;
    }
};

class DetectSquares {
public:
    unordered_map<int, vector<int>> m1, m2;

    DetectSquares() {
        return;
    }

    void add(vector<int> point) {
        m1[point[0]].push_back(point[1]);
        m2[point[1]].push_back(point[0]);
    }

    int count(vector<int> point) {
        int sum = 0;
        int x = point[0], y = point[1];
        vector<int> col = m1[point[0]], row = m2[point[1]];
        int times = 1, n_times = 1;
        for (int i = 0; i < col.size(); ++i) {
            int n_sum = 0;
            int len = abs(col[i] - y);
            if (col[i] - y != 0) {
                // int len = abs(col[i] - y);
                for (int j = 0; j < row.size(); ++j) {
                    if (abs(row[j] - x) == len) {
                        n_sum++;
                    }
                }
            } else {
                times++;
            }
            sum += n_sum;
        }
        for (int i = 0; i < col.size(); ++i) {
            int n_sum = 0;
            int len = abs(col[i] - y);

            if (col[i] - y != 0) {
                vector<int> tmp = m2[col[i]];
                for (int j = 0; j < tmp.size(); ++j) {
                    if (abs(tmp[j] - point[0]) == len) {
                        n_sum++;
                    }
                }
                sum += n_sum * times;
            }
        }

        // sum *= times;
        return sum;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */


// class Solution {
// public:
//     int sumOfBeauties(vector<int>& nums) {
//         int sum = 0;
//         vector<int> rmax, rmin;
//         int max_ = 0;
//         int min_ = INT_MAX;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (max_ < nums[i]){
//                 max_ = nums[i];
//             }
//             rmax.push_back(max_);
//             int j = nums.size() - 1 - i;
//             if (min_ > nums[j]){
//                 min_ = nums[j];
//             }
//             rmin.push_back(min_);
//         }
//         for (int i = 1; i <= nums.size() - 2; ++i) {
//             if (rmax[i - 1] < nums[i] and rmin[i + 1] > nums[i]){
//                 sum += 2;
//             }
//             else if (nums[i] > nums[i - 1] and nums[i] < nums[i + 1]){
//                 sum++;
//             }
//         }
//         return sum;
//     }
// };
// class Solution {
// public:
//     int finalValueAfterOperations(vector<string>& operations) {
//         int sum = 0;
//         for (int i = 0; i < operations.size(); ++i) {
//             if (operations[i][1] == '+'){
//                 sum++;
//             }
//             else{
//                 sum--;
//             }
//         }
//         return sum;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week259, Example2) {      // NOLINT
        std::vector<int> nums = {98816, 98816, 98818, 98815, 98819, 98816, 98819, 98816, 98824, 98824, 98819, 98821,
                                 98818, 98821, 98818};
        auto ans = Solution().getDistances(nums);
        decltype(ans) rightAns = {0, 1};
        ASSERT_EQ(ans, rightAns);

    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
