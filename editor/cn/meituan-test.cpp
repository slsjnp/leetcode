#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
#include <unordered_map>
#include <stack>
#include <queue>
// c libraries
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
// // file output
// #include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);
    // vector<int> nums1(m1, 0), nums2(m2, 0);
    vector<vector<int>> nums1(m1, vector<int> (2, 0));
    vector<vector<int>> nums2(m2, vector<int> (2, 0));
    for (int i = 0; i < m1; ++i) {
        int t;
        scanf("%d",&t);
        nums1[i][0] = t;
    }
    for (int i = 0; i < m1; ++i) {
        int t;
        scanf("%d",&t);
        nums1[i][1] = t;
    }

    for (int i = 0; i < m2; ++i) {
        int t;
        scanf("%d",&t);
        nums2[i][0] = t;
    }
    for (int i = 0; i < m2; ++i) {
        int t;
        scanf("%d",&t);
        nums2[i][1] = t;
    }

    // n m1 m2
    // nums1 nums2
    map<int, int> ma2;
    unordered_map<int, int> mal, mar;
    for (int i = 0; i < m1; ++i) {
        int l = nums1[i][0];
        int r = nums1[i][1];
        auto it = std::upper_bound(mal.begin(), mal.end(), l);
        if(it != mal.end()){
            if (r < it->first + it->second){

            }
        }
        mar[nums1[i][1]] = nums1[i][1] - nums1[i][0] + 1;
        mal[nums1[i][0]] = nums1[i][1] - nums1[i][0] + 1;
    }
    long long sum = 0;

    for(auto it :nums1){
        // left
        int l = it[0];
        int r = it[1];
        while(l <= r){
            auto idx = ma2.upper_bound(l);
            if (idx == ma2.end()){
                continue;
            }
            l = max(l, idx->second);
            int tmp = min(r, idx->first);
            sum += tmp - l + 1;
            if (tmp + 1 < r){
                l = tmp + 1;
            }
            else{
                break;
            }
        }
    }

    for(auto it :nums2){
        // left
        int l = it[0];
        int r = it[1];
        while(l <= r){
            auto idx = ma2.upper_bound(l);
            if (idx == ma2.end()){
                continue;
            }
            l = max(l, idx->second);
            int tmp = min(r, idx->first);
            printf("l:%d r:%d\n",l, tmp);
            sum += tmp - l + 1;
            if (tmp + 1 < r){
                l = tmp + 1;
            }
            else{
                break;
            }
        }
    }
    printf("%lld", sum);
    return 0;

    // vector<int> pre1(m1 + 1, 0);
    // // vector<int> pre2(m2 + 1, 0);
    //
    // for (auto it: nums1) {
    //
    // }

}

// int main(){
//     int n ,t;
//     scanf("%d %d",&n,&t);
//     char s[n + 1];
//     scanf("%s", &s);
//     string res;
//     if (t == 1){
//         int l = (n - 1) / 2;
//         int r = l + 1;
//         while(l >= 0 || r < n){
//             if (l >= 0){
//                 res += s[l];
//                 l--;
//             }
//             if (r < n){
//                 res += s[r];
//                 r++;
//             }
//         }
//         printf("%s", res.c_str());
//         return 0;
//     }
//     else{
//         for (int i = 0; i < n; ++i) {
//             if (i & 1){
//                 res = res + s[i];
//             }
//             else{
//                 res = s[i] + res;
//             }
//         }
//         printf("%s", res.c_str());
//         return 0;
//     }
//
//
// }
// int binary(vector<int> &nums, int l, int h, int k){
//     int mid;
//     while(l <= h){
//         mid = l + (l - h) / 2;
//         if (nums[mid] == k){
//             return mid;
//         }
//         else if(nums[mid] > k){
//             h = mid - 1;
//         }
//         else if(nums[mid] < k){
//             l = mid + 1;
//         }
//     }
//     int _size = nums.size();
//     if (l == _size && k > nums[_size - 1]){
//         return _size - 1;
//     }
//         // if (l == 0) return -1;
//     else return l - 1;
// }
//
// int main(){
//     int n;
//     scanf("%d", &n);
//     vector<int> ori(n, 0), zhe(n, 0);
//     for (int i = 0; i < n; ++i) {
//         int t;
//         scanf("%d", &t);
//         ori[i] = t;
//     }
//     for (int i = 0; i < n; ++i) {
//         int t;
//         scanf("%d", &t);
//         zhe[i] = t;
//     }
//     int m = 0;
//     scanf("%d", &m);
//     vector<int> mc(m, 0);
//     vector<int> md(m, 0);
//     for (int i = 0; i < m; ++i) {
//         int t;
//         scanf("%d", &t);
//         mc[i] = t;
//     }
//     for (int i = 0; i < m; ++i) {
//         int t;
//         scanf("%d", &t);
//         md[i] = t;
//     }
//
//     // ori zhe mc md
//     vector<int> pre_ori(n + 1, 0), pre_zhe(n + 1, 0);
//     for (int i = 0; i < n; ++i) {
//         pre_ori[i + 1] = pre_ori[i] + ori[i];
//         pre_zhe[i + 1] = pre_zhe[i] + zhe[i];
//     }
//
//     string s;
//     for (int i = 0; i < n; ++i) {
//         int sum = 0;
//         sum = pre_ori[i + 1];
//         int idx = binary(mc, 0, mc.size() - 1, sum);
//         auto it = upper_bound(mc.begin(), mc.end(), sum) - mc.begin();
//         if (it != 0){
//             sum -= md[it-1];
//         }
//
//         // if (idx != -1){
//         //     sum -= md[idx];
//         // }
//         if(pre_zhe[i + 1] < sum){
//             s += "Z";
//         }
//         else if (pre_zhe[i + 1] > sum){
//             s += "M";
//         }
//         else{
//             s += "B";
//         }
//     }
//     printf("%s", s.c_str());
//     return 0;
// }
