//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#include&lt;iostream&gt;

using namespace std;

// int main() {
//     int n = s.size();
//     int j = n - 1;
//     int tim = 0; //记录交换次数
//     int flag = 0;//标记是否已经存在个数为奇数的字符
//     //从右端j开始寻找与s[i]相同的s[k]
//     for (int i = 0; i & lt; j;
//     i++){
//         for (int k = j; k & gt;= i;
//         k--){
//             if (k == i) {//找到了单独的一个字符，
//                 if (n % 2 == 0 || flag == 1) {//且如果字符床长度为偶数过着之前已经找到一个单独的字符，就无法调整为回文了
//                     cout & lt;
//                     &lt;
//                     "Impossible";
//                     return 0;
//                 }
//                 tim += n / 2 - i;
//             } else {
//                 if (s[i] == s[k]) { //把找到的s[k]移到最右端
//                     for (int l = k; l & lt; j;
//                     l++){
//                         swap(s[l], s[l + 1]);
//                         tim++;
//                     }
//                     j--;
//                     break;
//                 }
//             }
//         }
//     }
//     cout & lt;
//     &lt;
//     tim;
//     return 0;
// }


class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int j = n - 1;
        int tim = 0; 
        int flag = 0;
        for (int i = 0; i < j; i++){
            for (int k = j; k >= i; k--){
                if (k == i) {
                    // if (n % 2 == 0) {
                    //     return 0;
                    // }
                    tim += n / 2 - i;
                } else {
                    if (s[i] == s[k]) {
                        for (int l = k; l < j; l++){
                            swap(s[l], s[l + 1]);
                            tim++;
                        }
                        j--;
                        break;
                    }
                }
            }
        }
        return tim;
    }
};
// class Solution {
// public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> res;
//         unordered_map<int, vector<int>> ma;
//         int _size = edges.size();
//         for (int i = 0; i < _size; ++i) {
//             ma[edges[i][1]].push_back(edges[i][0]);
//         }
//         for (int i = 0; i < n; ++i) {
//             queue<int> qu;
//             qu.push(i);
//             vector<int> tmp;
//             unordered_set<int> se;
//             int t;
//             while(!qu.empty()){
//                 t = qu.front();
//                 qu.pop();
//                 for(auto it: ma[t]){
//                     if (se.count(it) == 0){
//                         qu.push(it);
//                         tmp.push_back(it);
//                         se.insert(it);
//                     }
//                 }
//             }
//             sort(tmp.begin(), tmp.end());
//             res.push_back(tmp);
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         int _size = nums.size();
//         vector<int> res;
//         for (int i = 0; i < _size; ++i) {
//             string s = to_string(nums[i]);
//             string n;
//             for (int j = 0; j < s.size(); ++j) {
//                 n += '0' + mapping[s[j] - '0'];
//             }
//             res.push_back(stoi(n));
//         }
//         vector<int> idx(_size);
//         iota(idx.begin(), idx.end(), 0);
//         sort(idx.begin(), idx.end(), [&res](int a, int b){
//             return res[a] < res[b];
//         });
//         vector<int> ans;
//         for (int i = 0; i < _size; ++i) {
//             ans.push_back(nums[idx[i]]);
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int mostFrequent(vector<int>& nums, int key) {
//         int _size = nums.size();
//         unordered_map<int ,int > se;
//         for (int i = 0; i < _size; ++i) {
//             if (nums[i] == key and i < _size - 1){
//                 // if (se.count(nums[i + 1]) == 0){
//                 //     se.insert(nums[i+ 1]);
//                 // }
//                 se[nums[i + 1]]++;
//             }
//         }
//         // return (int)se.size();
//         int sum = 0;
//         int ans;
//         for (auto it: se) {
//             if(it.second  > sum){
//                 sum = it.second;
//                 ans = it.first;
//             }
//         }
//         return ans;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(week280, Example2) {      // NOLINT
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
