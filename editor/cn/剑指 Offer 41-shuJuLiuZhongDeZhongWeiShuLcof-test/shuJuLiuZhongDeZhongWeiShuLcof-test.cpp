// 2022-08-30 00:24:37
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class MedianFinder {
public:
    /** initialize your data structure here. */

    struct cmp_max {
        bool operator()(int &a, int &b) {
            return a < b;
        }
    };

    struct cmp_min {
        bool operator()(int &a, int &b){
            return a > b;
        }
    };

    priority_queue<int, vector<int>, cmp_max > q_max;
    priority_queue<int, vector<int>, cmp_min > q_min;

    MedianFinder() {

    }

    void addNum(int num) {
        if (!q_max.empty() && q_max.top() < num){
            q_min.push(num);
            if (q_min.size() > q_max.size() + 1){
                q_max.push(q_min.top());
                q_min.pop();
            }
        } else{
            q_max.push(num);
            if (q_max.size() > q_min.size() + 1) {
                q_min.push(q_max.top());
                q_max.pop();
            }
        }
    }

    double findMedian() {
        // printf("%d: %d \n", (q_max.size() + q_min.size()) % 2, q_max.top() );
        if ((q_max.size() + q_min.size()) % 2 == 1) {
            if (q_max.size() > q_min.size()){
                return q_max.top();
            } else return q_min.top();
        } else {
            return (q_max.top() + q_min.top()) / 2.0;
        }
    }
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ShuJuLiuZhongDeZhongWeiShuLcof, Example1) {      // NOLINT
        std::vector<int> nums = {};
        auto ans = Solution().shuJuLiuZhongDeZhongWeiShuLcof(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}