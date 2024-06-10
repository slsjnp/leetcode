// 2022-08-24 19:31:58
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> res;
    MinStack() {

    }
    
    void push(int x) {
        int top = x;
        if (!res.empty()){
            top = res.back();
        }
        res.push_back(x);
        if (x < top){
            res.push_back(x);
        } else{
            res.push_back(top);
        }
    }
    
    void pop() {
        res.pop_back();
        res.pop_back();
    }
    
    int top() {
        if (res.size() > 1){
            return res[res.size() - 2];
        } else{
            return 0;
        }
    }
    
    int min() {
        return res.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(BaoHanMinhanShuDeZhanLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().baoHanMinhanShuDeZhanLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}