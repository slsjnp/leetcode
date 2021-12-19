// 2021-10-16 00:05:50
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string s;
    int size;
    vector<string> res;
    int target;
    vector<string> addOperators(string num, int target) {
        size = num.length();
        this->target = target;
        s = num;

        dfs(0, 0, 0, "");
        return res;
    }
    void dfs(int ind, long long pre, long long sum, string path){
        /*
         * 0 is none
         * 1 is +
         * 2 is -
         * 3 is *
         * 4 is done
         * */
        if (ind == s.length()){
            if (sum == target){
                res.push_back(path);
            }
            return;
        }
        long long now = 0;
        for (int i = ind; i < size; ++i) {
            if (i != ind && s[i] == '0')
                break;
            now = now * 10 + s[i] - '0';
            if (i == 0){
                dfs(i + 1, now, now, to_string(now));
            }
            else {
                dfs(i + 1, now, sum + now, path + "+" + to_string(now));
                dfs(i + 1, -now, sum - now, path + "-" + to_string(now));
                dfs(i + 1, pre * now, sum - pre + pre * now, path + '*' + to_string(now));
            }
        }

    }
};
    // if (ind == size){
    //     if (sum == target_){
    //         res.push_back(s);
    //     }
    // }
    // long long val = 0;
    // // 向后遍历
    // for (int i = ind; i < size; ++i) {
    //     // 并非第一个 并前置0
    //     if (i != ind && str[ind] == '0')
    //         break;
    //
    //     // 不添加符号
    //     val = val * 10 + s[i] - '0';
    //     if (ind == 0){
    //         dfs(i + 1, val, val, to_string(val));
    //     }
    //     else{
    //         s.push_back(s[i]);
    //         dfs(i + 1, val, val, s);
    //     }
    //
    //     dfs(i + 1, )
    //     else{
    //         dfs(i + 1, pre * val, sum - pre + pre * val, s);
    //     }
    // }

    // typedef struct stat{
    //     int pre_val[2]={0 ,0};
    //     int pre_st[2]={0, 0};
    //     int now=0;
    // }stat;
    // vector<string> addOperators(string num, int target) {
    // length = num.length();
    // int status[length];
    // stat stat_[length];
    // enum op {add, minus, div, none};
    // vector<string> res;
    // index = 0; // status index
    // sec_index = num.begin(); // num index;
    // end = num.end();
    // flag=0;
    // for (int i = 0; i < length; ++i) {
    //     status[i] = add;
    // }
    // stat_[0].now = num[0];
    // string pre_str = string(num.begin(), num.begin() + index);
    // string next_str = string(num.begin() + index, num.end());
    // pre_pre_val = 0;
    // pre_val = 0;
    // pre_st = 0;
    // pre_pre_st = 0;
    // next_int = 0;

    // ch[0] = num.begin();
    // ch[1] = num.begin();
    // ch[2] = num.begin();
    // ch[3] = num.end();


    //     while (flag != 4 * (length - 1)){
    //         if (target==eval(status, stat_[index])){
    //             res.push_back(present_str(num, status));
    //         }
    //         change_status(status, stat_, num);
    //     }
    //     return res;
    // }
    // string present_str(string num, int status[]){
    //     string s;
    //     for (int i = 0; i < num.length(); ++i) {
    //         s.push_back(num[i]);
    //         switch (status[i]) {
    //             case 0:{
    //                 s.push_back('+');
    //             }
    //             case 1:{
    //                 s.push_back('-');
    //             }
    //             case 2:{
    //                 s.push_back('*');
    //             }
    //             default: continue;
    //         }
    //     }
    //     s.push_back(num.back());
    // }
    // int eval(int status[], stat st){
    //     // int sum = 0;
    //     int value1 = 0;
    //     int value2 = 0;
    //     int value3 = 0;
    //     if (2 <= status[index]){
    //         value3 = value(st.now, stoi(string(sec_index, end)), status[index]);
    //         value2 = value(st.pre_val[1], value3, st.pre_st[1]);
    //         value1 = value(st.pre_val[0], value2, st.pre_st[0]);
    //         // sum += value(st.pre_val[0], value(st.pre_val[1], value(now, string(sec_index, end), status[index]), st.pre_st[1]), st.pre_st[0])
    //         return value1;
    //     }
    //     else {
    //         value2 = value(st.pre_val[1], st.now, st.pre_st[1]);
    //         value1 = value(st.pre_val[0], value2, st.pre_st[0]);
    //         value3 = value(value1, stoi(string(sec_index, end)), status[index]);
    //         return value3;
    //     }
    //
    //     // if (pre_st <= status[sec_index]){
    //     //     sum = value(pre_val, string(sec_index, end), status[sec_index]);
    //     //     sum = value(pre_pre_val, sum, status[pre_st]);
    //     // }
    //     // else{
    //     //     sum = value(pre_pre_val, pre_val, status[pre_st]);
    //     //     sum = value(sum, string(sec_index, end), status[sec_index]);
    //     // }
    // }
    // int value(int pre, int next, int st){
    //     int sum = 0;
    //     switch (st){
    //         case 0:{
    //             return pre + next;
    //         }
    //         case 1:{
    //             return pre - next;
    //         }
    //         case 2:{
    //             return pre * next;
    //         }
    //         case 3:{
    //             return stoi(to_string(pre) + to_string(next));
    //         }
    //     }
    // }
    // // int value(string pre, string next, int st){
    // //     int sum = stoi(pre + next);
    // //     if (st == 3){
    // //         return sum;
    //     // switch (st) {
    //     //     case 0:{
    //     //         sum = stoi(pre) + stoi(next);
    //     //     }
    //     //     case 1:{
    //     //         sum = stoi(pre) - stoi(next);
    //     //     }
    //     //     case 2:{
    //     //         sum = stoi(pre) * stoi(next);
    //     //     }
    //     //     case 3:{
    //     //         sum = stoi(pre + next);
    //     //     }
    //         // case st==4{
    //         //     sum = stoi(pre + next);
    //         // }
    //     // }
    //     // return 0;
    //     // return sum;
    // // }
    // void change(int status[], stat st[], string& num){
    //     if (3 == status[index]){
    //         st[index+1].now = value(st[index].now, num[index], 3);
    //         // index++;
    //     }
    //     // *
    //     else if (2 == status[index]){
    //         st[index+1].pre_val[1] = st[index].pre_val[1] * st[index].now;
    //         st[index+1].now = (int)num[index+1];
    //         // index++;
    //     }
    //     // + -
    //     else{
    //         st[index+1].pre_val[1] = value(st[index].pre_val[1], st[index].now, st[index].pre_st[1]);
    //         st[index+1].pre_st[1] = status[index];
    //         st[index+1].pre_val[0] = 0;
    //         st[index+1].pre_st[0] = 0;
    //         // index++;
    //     }
    //     // pre_st =
    //     flag++;
    // }
    // void change_status(int status[], stat st[], string num){
    //     // 可前进
    //     if (index < length - 2){
    //         // none
    //         change(status, st, num);
    //         index++;
    //         sec_index++;
    //         status[index]++;
    //     }
    //     // 不可前进则回退
    //     else{
    //         while (status[index] == 4){
    //             flag -= 4;
    //             status[index] = 0;
    //             sec_index--;
    //             index--;
    //         }
    //         change(status, st, num);
    //         status[index]++;
    //     }
    // }
    // private:
    // int flag;
    // int length;
    // int index;
    // string::iterator sec_index;
    // string::iterator end;
    // int pre_pre_st;
    // int pre_st;
    // int pre_val;
    // int pre_pre_val;

    // string::iterator ch[4];
    // int status[];
    // };
    //leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ExpressionAddOperators, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        string nums = "123";
        int target = 6;
        auto ans = Solution().addOperators(nums, target);
        decltype(ans) rightAns = {string("123")};
        ASSERT_EQ(ans, rightAns);
    }

    // TEST(ExpressionAddOperators, solution) {      // NOLINT
    //     std::vector<int> nums = { };
    //     auto ans = Solution().expressionAddOperators(nums);
    //     decltype(ans) rightAns = ;
    //     ASSERT_EQ(ans, rightAns);
    // }
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}