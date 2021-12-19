// 2021-11-25 09:26:28
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct Neiberhood {
    int name;
    Neiberhood *next;

    explicit Neiberhood(int a) : name(a), next(nullptr) {};

};

// class Solution {
// public:
//     int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
//         int n = p.size();
//
//         // 邻接表建图
//         vector<vector<int>> e(n);
//         for(auto &ed : edges) {
//             e[ed[0]].push_back(ed[1]);
//             e[ed[1]].push_back(ed[0]);
//         }
//
//         // 记录哪些服务器已被扩展
//         vector<bool> vis(n);
//         queue<pair<int, int>> q;
//         q.emplace(0, 0);
//         vis[0] = true;
//
//         // 记录最晚到达时间
//         int ret = 0;
//
//         // 广度优先搜索
//         while(!q.empty()) {
//             auto [c, time] = q.front();
//             q.pop();
//
//             if(c != 0) {
//                 // c != 0 是因为首先会扩展到主服务器
//                 int cost = ((2 * time - 1) / p[c]) * p[c] + 2 * time;
//                 ret = max(ret, cost);
//             }
//
//             // 扩展所有与当前数据服务器直接相连的服务器
//             for(int &next : e[c]) {
//                 if(!vis[next]) {
//                     vis[next] = true;
//                     q.emplace(next, time + 1);
//                 }
//             }
//         }
//
//         return ret + 1;
//     }
// };


class Solution {
public:


    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        int n = patience.size();
        int e_size = edges.size();
        int res = -1;
        int last = 0;
        int i;
        vector<Neiberhood *> ne(n, nullptr);
        vector<int> ve_dis(n, -INT_MAX);
        int ns, nd;
        for (int i = 0; i < e_size; ++i) {
            ns = edges[i][0];
            nd = edges[i][1];
            Neiberhood *head = ne[ns];
            if (head == nullptr) {
                head = new Neiberhood(nd);
                ne[ns] = head;
            } else {
                while (head->next != nullptr) {
                    head = head->next;
                }
                head->next = new Neiberhood(nd);
            }

            // head = ne[nd];
            // if (head == nullptr) {
            //     head = new Neiberhood(ns);
            //     ne[nd] = head;
            // } else {
            //     while (head->next != nullptr) {
            //         head = head->next;
            //     }
            //     head->next = new Neiberhood(ns);
            // }
        }
        queue<pair<int, Neiberhood *>> qu;
        ve_dis[0] = 0;
        qu.emplace(make_pair(0, ne[0]));
        int now = 0;
        // int v_min;
        vector<int> v_ve(n, 0);
        // v_ve[0] = 1;
        while (!qu.empty()) {
            auto h = qu.front();
            qu.pop();
            now = h.first;
            auto head = h.second;
            while (head != nullptr) {
                if (ve_dis[head->name] == -INT_MAX) {
                    ve_dis[head->name] = ve_dis[now] + 1;
                    v_ve[head->name] = 1;
                    qu.emplace(make_pair(head->name, ne[head->name]));
                    i = head->name;
                    last = 0;
                    if (i and ve_dis[i] * 2 < patience[i]) {
                        res = max(res, 2 * ve_dis[i]);
                        // last = 0;
                    } else if (i){
                        // if (patience[i] == 1) {
                        //     last = ve_dis[i] * 2 - 1;
                        // } else last = ve_dis[i] * 2 - ve_dis[i] * 2 % patience[i];
                        last = ve_dis[i] * 2 - ve_dis[i] * 2 % patience[i];
                        if (ve_dis[i] * 2 % patience[i] == 0) {
                            last = ve_dis[i] * 2 - patience[i];
                        }
                        res = max(res, last + 2 * ve_dis[i]);
                    }
                }
                // if (ve_dis[head->name] > ve_dis[now] + 1) {
                if (!v_ve[head->name]){
                    ve_dis[head->name] = ve_dis[now] + 1;
                    qu.emplace(make_pair(head->name, ne[head->name]));
                    i = head->name;
                    last = 0;
                    if (i and ve_dis[i] * 2 < patience[i]) {
                        res = max(res, 2 * ve_dis[i]);
                        // last = 0;
                    } else if(i){
                        // if (patience[i] == 1) {
                        //     last = ve_dis[i] * 2 - 1;
                        // } else last = ve_dis[i] * 2 - ve_dis[i] * 2 % patience[i];
                        last = ve_dis[i] * 2 - ve_dis[i] * 2 % patience[i];
                        if (ve_dis[i] * 2 % patience[i] == 0) {
                            last = ve_dis[i] * 2 - patience[i];
                        }
                        res = max(res, last + 2 * ve_dis[i]);
                    }
                    v_ve[head->name] = 1;
                }
                head = head->next;
            }

            // auto h = qu.front();
            // qu.pop();
            // while (h != nullptr) {
            //     if (v_ve[h->name]){
            //         h = h->next;
            //     }
            //     else {
            //         v_min = h->name;
            //         break;
            //     }
            // }
            // while (h != nullptr) {
            //     if (v_ve[h->name]){
            //         h = h->next;
            //         continue;
            //     }
            //     if (ve_dis[h->name] == -INT_MAX) {
            //         ve_dis[h->name] = ve_dis[now] + 1;
            //     } else if (!v_ve[h->name]) {
            //         ve_dis[h->name] = min(ve_dis[h->name], ve_dis[now] + 1);
            //     }
            //     if (!v_ve[h->name] and ve_dis[h->name] <= ve_dis[v_min]) {
            //         v_min = h->name;
            //
            //     }
            //     h = h->next;
            // }
            // if (v_ve[v_min] != 1) {
            //     qu.push(ne[v_min]);
            //     v_ve[v_min] = 1;
            //     now = v_min;
            // }
        }

        // for (int i = 1; i < n; ++i) {
        //     if (ve_dis[i] == -INT_MAX) continue;
        //     last = 0;
        //     if (ve_dis[i] * 2 < patience[i]) {
        //         res = max(res, 2 * ve_dis[i]);
        //         // last = 0;
        //     } else {
        //         // if (patience[i] == 1) {
        //         //     last = ve_dis[i] * 2 - 1;
        //         // } else last = ve_dis[i] * 2 - ve_dis[i] * 2 % patience[i];
        //         last = ve_dis[i] * 2 - ve_dis[i] * 2 % patience[i];
        //         if (ve_dis[i] * 2 % patience[i] == 0) {
        //             last = ve_dis[i] * 2 - patience[i];
        //         }
        //         res = max(res, last + 2 * ve_dis[i]);
        //     }
        // }
        return res + 1;
    }

};


//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(TheTimeWhenTheNetworkBecomesIdle, Example1) {      // NOLINT
        // vector<vector<int>> a =;
        std::vector<int> nums = {0,3,2,1,5,1,5,5,3,1,2,2,2,2,1};
        vector<vector<int>> a = {{3, 8},{4, 13},{0, 7},{0, 4},{1, 8},{14, 1},{7, 2},{13, 10},{9, 11},{12, 14},{0, 6},{2, 12},{11, 5},{6, 9},{10, 3}};
        auto ans = Solution().networkBecomesIdle(a, nums);
        decltype(ans) rightAns = 8;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}