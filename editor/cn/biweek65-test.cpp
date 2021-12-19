//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int ,int> ma;
        for (auto i: items) {
            ma[i[0]] = max(ma[i[0]], i[1]);
        }
        int pre = ma.begin()->second;
        for (auto i = ma.begin(); i != ma.end(); ++i) {
            if (pre > i->second){
                i->second = pre;
            }
            else {
                pre = i->second;
            }
        }
        vector<int> res;
        for (auto i : queries) {
            res.push_back(ma[i]->second);
        }
        return res;
    }
};

// class Robot {
// public:
//     vector<vector<int>> ma;
//     enum flag {
//         East, North, West, South
//     };
//     int head;
//     vector<int> loc;
//     int width;
//     int height;
//
//     Robot(int width, int height) {
//         // int a[width][height];
//         this->width = width;
//         this->height = height;
//         ma = vector<vector<int>>(width, (vector<int>(height, 0)));
//         this->loc = vector<int>{0, 0};
//         head = East;
//     }
//
//     void move(int num) {
//         // int t = head;
//         // switch (head) {
//         if (head == 0) {
//             if (num + loc[0] < width) {
//                 loc[0] += num;
//             } else {
//                 int tmp = num + loc[0] - (width - 1);
//                 loc[0] = width - 1;
//                 head = North;
//                 move(tmp);
//                 return;
//             }
//         }// right
//         if (head == 1) {
//             if (num + loc[1] < height) {
//                 loc[1] += num;
//             } else {
//                 int tmp = num + loc[1] - height + 1;
//                 loc[1] = height - 1;
//                 head = West;
//                 move(tmp);
//                 return;
//             }
//         }
//         if (head == 2) {
//             if (-num + loc[0] >= 0) {
//                 loc[0] -= num;
//             } else {
//                 int tmp = abs(-num + loc[0] + 1);
//                 loc[0] = 0;
//                 head = South;
//                 move(tmp);
//                 return;
//             }
//         }
//         if (head == 3) {
//             if (-num + loc[1] >= 0) {
//                 loc[1] -= num;
//             } else {
//                 int tmp = abs(-num + loc[1] + 1);
//                 loc[1] = 0;
//                 head = East;
//                 move(tmp);
//                 return;
//             }
//         }
//         // }
//     }
//
//     vector<int> getPos() {
//         return loc;
//     }
//
//     string getDir() {
//         // switch (head) {
//             if (head == 0)
//                 return "East";
//             if (head == 1)
//                 return "North";
//             if (head == 2)
//                 return "West";
//             if (head == 3)
//                 return "South";
//         // }
//         return 0;
//     }
// };

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

// class Solution {
// public:
//     bool checkAlmostEquivalent(string word1, string word2) {
//         int _size = word1.size();
//         bool res = true;
//         // sort(word1.begin(), word1.end());
//         // sort(word2.begin(), word2.end());
//         unordered_map<char , int> ma1;
//         unordered_map<char , int> ma2;
//         int time = 0;
//         int ind = 0;
//         for (int i = 0; i < _size; ++i) {
//             ma1[word1[i]]++;
//             ma2[word2[i]]++;
//         }
//         for (auto i : ma1) {
//             if (abs(i.second - ma2[i.first]) > 3){
//                 res = false;
//             }
//         }
//
//         for (auto i : ma2) {
//             if (abs(i.second - ma1[i.first]) > 3){
//                 res = false;
//             }
//         }
//         return res;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Shopp, Example2) {      // NOLINT
        // std::vector<int> nums = { 10,83,53};
        // string s = "**|**|***|";
        vector<vector<int>> t = {{1, 5, 3},
                                 {1, 5, 1},
                                 {6, 6, 5}};
        // int a = 6;
        // vector<int> n = {3, 2};
        auto ans = Robot(6, 3);
        ans.move(2);
        ans.move(2);
        ans.move(2);
        ans.move(1);
        ans.move(4);
        int c = 0;
        decltype(c) rightAns = 8;
        ASSERT_EQ(c, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
