// 2022-09-01 23:30:19
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static int age;
    struct cmp{
        bool operator()(const int a, const int b) const{
            string str_a = to_string(a);
            string str_b = to_string(b);
            int i = 0;
            int a_size = str_a.size();
            int b_size = str_b.size();

            while (i < a_size && i < b_size){
                if (str_a[i] != str_b[i]){
                    return str_a[i] < str_b[i];
                } else{
                    i++;
                }
            }
            if (i == a_size && i == b_size){
                return true;
            } else if (i == a_size){
                if (str_b[i] == '0'){
                    return false;
                } else return true;
            } else{
                if (str_a[i] == '0'){
                    return true;
                } else return false;
            }
        }
    };
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), cmp());
        string res = "";
        int _size = nums.size();
        for (int i = 0; i < _size; ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int Solution::age = 1;

namespace {
    TEST(Solution1, Example1) {      // NOLINT
        std::vector<int> nums = { 10, 2 };
        Solution a;
        Solution b;
        printf("age: %d\n", a.age);
        a.age = 2;
        printf("age: %d\n", b.age);
        auto ans = Solution().minNumber(nums);
        decltype(ans) rightAns = "123";
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}