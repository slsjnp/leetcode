// 2021-12-19 22:01:09
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<string, vector<string>> ma;
    unordered_map<string, int> deg;
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 建图
        sort(tickets.begin(), tickets.end(), [](vector<string> a, vector<string> b){return a[1] > b[1];});
        for (int i = 0; i < tickets.size(); ++i) {
            if (ma.count(tickets[i][0]) == 0){
                ma[tickets[i][0]] = vector<string> {tickets[i][1]};
            }
            else{
                ma[tickets[i][0]].emplace_back(tickets[i][1]);
            }
            deg[tickets[i][0]]++;
            deg[tickets[i][1]]--;
        }
        // string start;
        // for (auto it: deg) {
        //     if(it.second == 1){
        //         start = it.first;
        //         res.emplace_back(start);
        //         dfs(start);
        //         reverse(res.begin() + 1, res.end());
        //         return res;
        //     }
        // }
        // res.emplace_back((*ma.rbegin()).first);
        // dfs((*ma.rbegin()).first);
        res.emplace_back("JFK");
        dfs("JFK");
        reverse(res.begin() + 1, res.end());
        return res;
    }
    void dfs(string start){
        while (!ma[start].empty()){
            string dec = ma[start].back();
            ma[start].pop_back();
            dfs(dec);
            res.emplace_back(dec);
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(ReconstructItinerary, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().reconstructItinerary(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}