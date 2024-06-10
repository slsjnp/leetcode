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
//     vector<int> sortEvenOdd(vector<int>& nums) {
//         vector<int> res;
//         vector<int> j, o;
//         for (int i = 0; i < nums.size(); ++i) {
//             if ((i & 1) == 0){
//                 o.push_back(nums[i]);
//             }
//             else{
//                 j.push_back(nums[i]);
//             }
//         }
//         sort(j.begin(),j.end(), [&](int a, int b){return a > b;});
//         sort(o.begin(),o.end());
//         for (int i = 0; i < nums.size(); ++i) {
//             if ((i & 1) == 0){
//                 res.push_back(o[i/2]);
//             }
//             else{
//                 res.push_back(j[i / 2]);
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     long long smallestNumber(long long num) {
//         string s = to_string(num);
//         if (num > 0){
//             sort(s.begin(),s.end());
//             long long tmp = 1;
//             long long sum = 0;
//             for (int i = 0; i < s.size(); ++i) {
//                 if (s[i] == '0'){
//                     tmp *= 10;
//                 }
//                 else {
//                     if (tmp == 1){
//                         sum = sum * 10 + s[i] - '0';
//                     }
//                     else{
//                         sum += s[i] - '0';
//                         sum = sum * tmp;
//                         tmp = 1;
//                     }
//                 }
//             }
//             return sum;
//         }
//         else{
//             sort(s.begin(),s.end(), [&](int a, int b){return a > b;});
//             long long sum = 0;
//             for (int i = 0; i < s.size() - 1; ++i) {
//                 sum = sum * 10 + s[i] - '0';
//             }
//             return -sum;
//         }
//     }
// };
class Bitset {
public:
    vector<uint32_t> res;
    int v;
    int flag = 0;
    int con = 0;

    Bitset(int size) {
        int s = size / 32;
        if (size % 32) {
            s++;
        }
        v = size;
        res = vector<uint32_t>(s, 0);
    }

    void fix(int idx) {
        // if ((!flag and (res[idx / 32] & (1 << idx % 32)) == 0) or (flag and (res[idx / 32] & (1 << idx % 32)) == 1)) {
        if ((res[idx / 32] & (1 << idx % 32)) == flag) == 1){
            con++;
            res[idx / 32] ^= 1 << (idx % 32);
        }
        // if (flag) res[idx / 32] = (res[idx / 32] | (1 << (idx % 32))) ^ (1 << (idx % 32));
        // else res[idx / 32] |= 1 << (idx % 32);
        // con++;
    }

    void unfix(int idx) {
        if ((res[idx / 32] & (1 << idx % 32)) == flag) == 0){
        // if ((!flag and (res[idx / 32] & (1 << idx % 32)) == 1) or (flag and (res[idx / 32] & (1 << idx % 32)) == 0)) {
            con--;
            res[idx / 32] ^= 1 << (idx % 32);
        }
        // // if (flag and (res[idx / 32] & (1 << idx % 32)) == 0) con--;
        // if ((res[idx / 32] & (1 << idx % 32)) == 1) con--;
        // if (flag) res[idx / 32] = res[idx / 32] | (1 << (idx % 32));
        // else res[idx / 32] = (res[idx / 32] | (1 << (idx % 32))) ^ (1 << (idx % 32));
        // // con--;
    }

    void flip() {
        flag ^= 1;
        con = v - con;
        // printf("con %d ", con);
    }

    bool all() {
        if (con == v) return true;
        else return false;
        // for (int i = 0; i < res.size() - 1; ++i) {
        //     if ((res[i] != UINT32_MAX and !flag) or (flag and res[i] != 0)) {
        //         return false;
        //     }
        // }
        // uint32_t g = UINT32_MAX;
        // if (v % 32){
        //     g = ((1 << (v % 32)) - 1);
        // }
        // if ((res[res.size() - 1] != g and !flag) or (flag and res[res.size() - 1] != (~g & g))) return false;
        // return true;
    }

    bool one() {
        if (con) return true;
        else return false;
        // for (int i = 0; i < res.size(); ++i) {
        //     if ((res[i] != 0 and !flag) or (flag and res[i] != UINT32_MAX)) {
        //         return true;
        //     }
        // }
        // return false;
    }

    int count() {
        return con;
        // int sum = 0;
        // for (int i = 0; i < res.size(); ++i) {
        //     uint32_t mask = res[i];
        //     while (mask != 0) {
        //         sum++;
        //         mask &= mask - 1;
        //     }
        // }
        // if (flag) sum = v - sum;
        // return sum;
    }



    string toString() {
        string s;
        for (int i = 0; i < v; ++i) {
            if ((1 << (i % 32)) & res[i / 32]) {
                if (flag) {
                    s += '0';
                } else s += '1';
            } else {
                if (flag) {
                    s += '1';
                } else s += '0';
            }
        }
        return s;
    }
};


/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week279, Example2) {      // NOLINT
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
