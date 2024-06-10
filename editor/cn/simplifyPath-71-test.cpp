// 2022-01-06 23:02:24
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int _size = path.size();
        vector<string> ve;
        for (int i = 0; i < _size; ) {
            // int r = i;
            string tmp;
            // int idx = 0;
            while(path[i] != '/' and i < _size){
                tmp += path[i];
                i++;
            }
            while(path[i] == '/' and i < _size){
                i++;
            }
            // printf("%d\n", i);
            // i = r;
            if (tmp.size() == 0){
                continue;
            }
            if (tmp.size() == 1 and tmp == "."){
                continue;
            }
            else if (tmp.size() == 2 and tmp == ".."){
                if (!ve.empty()) ve.pop_back();
            }
            else {
                ve.push_back(tmp);
            }
        }
        for (auto it: ve) {
            ans += "/" + it;
        }
        if (ans.size() == 0){
            return "/";
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(SimplifyPath, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().simplifyPath(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}