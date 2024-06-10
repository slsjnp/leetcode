//
// Created by sj on 2021/10/30.
//


// 2021-10-30 19:07:27
#include <gtest/gtest.h>
#include "header.h"
#include<cstdio>
#include<cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
typedef int Elemtype;
// 树的迭代遍历
// int sum = 0;
// void traverse(TreeNode *root) {
//     if (root == NULL){
//         return;
//     }
//     // 遍历时的操作，根据题目改, 比如记录值为X的个数
//     if (root->val == 'X'){
//         sum++;
//     }
//     traverse(root->left);
//     traverse(root->right);
// }
typedef struct SqList{
    Elemtype *data;
    int length;
} Sq;
// int 可以用Elemtype替代
void deleteElem(SqList& L, int n, Elemtype k){
    int l = 0; // 左指针
    for (int i = 0; i < n; ++i) {
        if (L.data[i] != k){ // 相当于把有效值保存起来
            L.data[l] = L.data[i];
            l++;
        }
    }
    L.length = l; // 更新有效值长度，相当于间接删除了其他不在范围内的元素
}
ListNode* deleteElem(ListNode* head, Elemtype k){
    ListNode* h = head; // 找个变量保存起来
    while (head->val == k) { // 头结点特殊处理
        ListNode* tmp = head; // 要删除的元素
        head = head->next; // 更新新的头结点
        free(tmp); // 删除
    }
    while (h != NULL){ // 不空就继续遍历
        // 记得要在删除的前一个位置
        if (h->next->val == k){ // 找到要删除的目标
            ListNode* tmp = h->next;
            h->next = h->next->next; // 更新下一个
            free(tmp) // 手起刀落人抬走
        }
        h = h->next; // 往后走
    }
    return head;
}



// class Solution {
// public:
//     long long nextInt(long long n) {
//         string s = to_string(n);
//         int s_size = s.size();
//
//         for (int i = (s_size - 1) / 2; i >= 0; --i) {
//             if (s[i] != '9') {
//                 s[i]++;
//                 // 是否有对称位置
//                 if (i != s_size - 1 - i) {
//                     s[s_size - 1 - i]++;
//                 }
//                 for (int j = i + 1; j < s_size - 1 - i; ++j) {
//                     s[j] = '0';
//                 }
//                 return stoll(s);
//             }
//         }
//         long long res = 1;
//         for (int i = 0; i < s_size; ++i) {
//             res *= 10;
//         }
//         return res + 1;
//     }
//
//     long long strtolong(string x, int k) {
//         long long res = 0;
//         int x_size = x.size();
//         long long now = 1;
//         for (int i = x_size - 1; i >= 0; --i) {
//             res += (x[i] - '0') * now;
//             now *= k;
//         }
//         return res;
//     }
//
//     string tentokstr(long long n, int k) {
//         string res = "";
//         while (n > 0) {
//             res += char(n % k + '0');
//             n = n / k;
//         }
//         return res;
//     }
//
//     bool isTrue(string x){
//         int _size = x.size();
//         for (int i = 0; i < _size / 2; ++i) {
//             if (x[i] != x[_size - 1 - i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     long long kMirror(int k, int n) {
//         long long sum = 0;
//         int times = 0;
//         long long i = 0;
//         while (times < n) {
//             // 下一个回文字符数
//             i = nextInt(i);
//             // 十进制转k进制
//             string x = tentokstr(i, k);
//             if (isTrue(x))
//             {
//                 // printf("%llu, ", stoll(x, nullptr, 3));
//                 sum += i;
//                 times++;
//             }
//             // string cpx = x;
//             // reverse(x.begin(), x.end());
//         }
//         return sum;
//     }
// };
// class Solution {
// public:
//     long long sum = 0;
//     int times = 0;
//     int k;
//
//     string intToA(int n, int radix) {
//         string ans = "";
//         do {
//             int t = n % radix;
//             if (t >= 0 && t <= 9) ans += (t + '0');
//             else ans += (t - 10 + 'a');
//             n /= radix;
//         } while (n != 0);  //使用do{}while()以防止输入为0的情况
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
//
//     void check(string now) {
//         if (now[0] == '0') {
//             return;
//         }
//         long long n = stoll(now, nullptr, k);
//         string te = to_string(n);
//         string t = te;
//         reverse(te.begin(), te.end());
//         if (te == t) {
//             sum += n;
//             times++;
//         }
//     }
//     vector<string> st;
//     // 构建回文串
//     void dfs(string now, int i){
//         for (int j = 1; j < 10; ++j) {
//             st.emplace_back(to_string(i) + now + to_string(i));
//         }
//     }
//     long long kMirror(int k, int n) {
//         this->k = k;
//         string now = "";
//         string now1 = "1";
//         int i = 1;
//         int j = 0;
//         while (times < n) {
//             st.emplace_back(to_string(i) + now + to_string(i));
//             st.emplace_back(to_string(i) + now1 + to_string(i));
//             // check(to_string(i) + now + to_string(i));
//             i++;
//             i %= 10;
//
//         }
//
//         for (int i = 1; times < n; ++i) {
//
//             string ten = to_string(i);
//             string te = ten;
//             reverse(ten.begin(), ten.end());
//             if (te == ten) {
//                 string x = intToA(i, k);
//                 string t = x;
//                 reverse(x.begin(), x.end());
//                 if (t == x) {
//                     sum += i;
//                     times++;
//                 }
//             }
//
//         }
//         return sum;
//     }
// };
// class RangeFreqQuery {
// public:
//     unordered_map<int, vector<int>> ma;
//     RangeFreqQuery(vector<int>& arr) {
//         int _size = arr.size();
//         for (int i = 0; i < _size; ++i) {
//             if (ma.count(arr[i]) == 0){
//                 ma[arr[i]] = vector<int> {i};
//             }
//             else{
//                 ma[arr[i]].emplace_back(i);
//             }
//         }
//     }
//
//     int query(int left, int right, int value) {
//         if (ma.count(value) == 0){
//             return 0;
//         }
//         // vector<int> res = ma[value];
//         int l = lower_bound(ma[value].begin(), ma[value].end(), left) - ma[value].begin();
//         int r = upper_bound(ma[value].begin(), ma[value].end(), right) - ma[value].begin();
//         if (r - l > 0){
//             return r - l;
//         }
//         else {
//             return 0;
//         }
//     }
// };

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// class Solution {
// public:
//     int wateringPlants(vector<int>& plants, int capacity) {
//         int _size = plants.size();
//         int now = capacity;
//         int res = 0;
//         for (int i = 0; i < _size; ++i) {
//             if (plants[i] > now){
//                 res += 2 * i + 1;
//                 now = capacity - plants[i];
//             }
//             else {
//                 now -= plants[i];
//                 res++;
//             }
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int _size = colors.size();
//         int res = 1;
//         int times = 1;
//         int flag = colors[0];
//         unordered_map<int, int> ma;
//         unordered_map<int, int> ma1;
//         for (int i = 0; i < _size; ++i) {
//             ma[colors[i]] = max(ma[colors[i]], i);
//             if (ma1.count(colors[i]) == 0){
//                 ma1[colors[i]] = i;
//             }
//             ma1[colors[i]] = min(ma1[colors[i]], i);
//         }
//         for (auto it: ma) {
//             for (auto ia: ma1) {
//                 if (ia.first != it.first){
//                     res = max(res, abs(ia.second - it.second));
//                 }
//             }
//         }
//         return res;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)

namespace {
    TEST(Week268, Example2) {      // NOLINT
        int a = 7, b = 17;
        auto ans = Solution().kMirror(a, b);
        decltype(ans) rightAns = 20379000;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
