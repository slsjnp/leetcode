// 2021-10-27 17:07:58
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    unordered_set<string> se;
    string s;
    int d;
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int size = s.length();
        // 每个括号前后数量都相等
        int l = 0;
        int r = 0;
        d = 0;
        int flag = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '('){
                l++;
                flag++;
            }
            else if (s[i] == ')'){
                r++;
                if (flag){
                    d++;
                    flag--;
                }
            }
        }
        // int d = abs(l - r);
        // int d = max(- rd, r - rd);
        BFS(0, l, r, "", 0);

        int len = 0;
        // for (auto i: se) {
        //     if (len < i.length()) len = i.length();
        // }
        for (auto i: se) {
            res.push_back(i);
        }
        return res;
    }

    void BFS(int ind, int l, int r, string res_s, int lr, int flag=0){
        // 递归出口
        if (ind > s.length()){
            return;
        }
        // 左边剩余括号比右括号多
        if (lr > r){
            return;
        }

        // 左右括号相等的时候减枝
        if (l == r && l == d){
            // 相等则递归出口
            if (ind == s.length() && !lr){
                if (se.count(res_s) == 0){
                    se.insert(res_s);
                }
                return;
            }
            else{
                if (s[ind] == '('){
                    lr++;
                }
                else if (s[ind] == ')'){
                    if (!lr){
                        return;
                    }
                    lr--;
                }
                BFS(ind + 1, l, r, string(res_s + s[ind]), lr);
            }
            return;
        }
        if (s[ind] == '('){
            if (l > d){
                // 左括号可删
                if (flag && ind > 0 && s[ind] == s[ind - 1]){
                    BFS(ind + 1, l - 1, r, res_s, lr, flag | 1);
                    return;
                }
                BFS(ind + 1, l - 1, r, res_s, lr, flag | 1);
                // 不删
            }
            BFS(ind + 1, l, r, string(res_s + s[ind]), 1+lr);
        }
        else if (s[ind] == ')'){
            if (r > d){
                if (flag && ind > 0 && s[ind] == s[ind - 1]){
                    BFS(ind + 1, l, r - 1, res_s, lr, flag | 1);
                    return;
                }
                // 右括号可删
                BFS(ind + 1, l, r - 1, res_s, lr, flag | 1);
            }
            // 不删
            if (!lr){
                return;
            }
            BFS(ind + 1, l, r, string(res_s + s[ind]), lr-1);
        }
        else {
            BFS(ind + 1, l, r, string(res_s + s[ind]), lr);
        }



        // if (ind == 0 && s[0] == ')') {
        //     BFS(ind + 1, l, r - 1, res_s, p, d + 1);
        // }
        // if (ind == s.size() && !l && !r){
        //     // res.push_back(res_s);
        //     if (se.count(res_s) == 0){
        //         se.insert(res_s);
        //     }
        //     return;
        // }
        // else if (ind == s.size() && d != 0){
        //     string tmp;
        //     for (auto i: res_s) {
        //         if (i != '(' && i != ')'){
        //             tmp.push_back(i);
        //         }
        //         if (se.count(tmp) == 0){
        //             se.insert(tmp);
        //         }
        //     }
        // }
        // if (ind == s.size()) return;
        // if (l < r){
        //     if (s[ind] == ')'){
        //         if (d) BFS(ind + 1, l, r - 1, res_s, p, d - 1);
        //         if (p.length() > 0 && *(p.end()-1) == '('){
        //             BFS(ind + 1, l - 1, r - 1, string(res_s + s[ind]), string(p.begin(), p.end() - 1), d);
        //         }
        //         BFS(ind + 1, l, r, string(res_s + s[ind]), string(p + ')'), d);
        //     }
        //     else if (s[ind] == '('){
        //         BFS(ind + 1, l, r, string(res_s + s[ind]), string(p + s[ind]), d);
        //     }
        //     else BFS(ind + 1, l, r, string(res_s + s[ind]), p, d);
        //
        // }
        // else {
        //
        //     if (s[ind] == ')'){
        //         if (p.length() > 0 && *(p.end()-1) == '('){
        //             BFS(ind + 1, l - 1, r - 1, string(res_s + s[ind]), string(p.begin(), p.end() - 1), d);
        //         }
        //         BFS(ind + 1, l, r, string(res_s + s[ind]), string(p + ')'), d);
        //     }
        //     else if (s[ind] == '('){
        //         BFS(ind + 1, l, r, string(res_s + s[ind]), string(p + '('), d);
        //         if (l != r) BFS(ind + 1, s, l - 1, r, res_s, p, d);
        //     }
        //     else BFS(ind + 1, l, r, string(res_s + s[ind]), p, d);
        // }
        //
        // // else {
        // //     BFS(ind + 1, s, l, r, string(res_s + s[ind]), p, d);
        // // }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(RemoveInvalidParentheses, Example1) {      // NOLINT
        std::string nums = "((((((((((((((((((((aaaaa";
        auto ans = Solution().removeInvalidParentheses(nums);
        decltype(ans) rightAns = {"1"};
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}