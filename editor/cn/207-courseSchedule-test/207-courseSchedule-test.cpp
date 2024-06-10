// 2023-09-09 22:46:23
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool flag = true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 有向无环图？
        // int _size = prerequisites.size();
        int _size = numCourses;
        // unordered_map<int, int> adj_list;
        vector<vector<int>> adj_list(_size, vector<int>(_size, 0));
        vector<int> indegree(_size, 0);
        for(auto& it: prerequisites){
            indegree[it[0]]++;
            adj_list[it[0]][it[1]] = 1;
        }
        queue<int> qu;
        unordered_set<int> se;
        for (int i = 0; i < _size; ++i) {
            if (indegree[i] == 0){
                qu.push(i);
                se.insert(i);
            }
        }

        while (!qu.empty()){
            int top = qu.front();
            qu.pop();
            for (int i = 0; i < _size; ++i) {
                if(adj_list[i][top] == 1){
                    indegree[i]--;
                    if (indegree[i] == 0){
                        qu.push(i);
                        se.insert(i);
                    }
                }
            }
        }
        if (se.size() == _size){
            return true;
        } else{
            return false;
        }
    }
};
// class Solution {
// public:
//     unordered_map<int, vector<int> > pre_map;
//     unordered_set<int> sus_set;
//     unordered_set<int> pre_set;
//     bool flag = true;
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // 有向无环图？
//         int _size = prerequisites.size();
//         for (auto it: prerequisites) {
//             pre_map[it[0]].emplace_back(it[1]);
//         }
//
//         for (int i = 0; i < numCourses; ++i) {
//             pre_set.clear();
//             flag &= dfs(i);
//             if (!flag){
//                 return false;
//             }
//         }
//         return true;
//     }
//
//     bool dfs(int course){
//         int pre = course;
//         if (sus_set.count(pre) != 0 || pre_map.count(pre) == 0){
//             return true;
//         }
//         pre_set.insert(pre);
//         if (pre_map.count(pre) == 0){
//             return true;
//         }
//         auto vec = pre_map[pre];
//         for (auto it : vec){
//             if (sus_set.count(it) != 0){
//                 continue;
//             }
//             if (pre_set.count(it) == 0){
//                 pre_set.insert(it);
//                 flag &= dfs(it);
//             } else {
//                 flag = false;
//                 return false;
//             }
//             if (flag) {
//                 if (sus_set.count(it) == 0) sus_set.insert(it);
//             } else{
//                 return false;
//             }
//         }
//         return flag;
//     }
// };
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(CourseSchedule, Example1) {      // NOLINT
        std::vector<vector<int>> nums = {{0,1}  };
        auto ans = Solution().canFinish(2, nums);
        decltype(ans) rightAns = true;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}