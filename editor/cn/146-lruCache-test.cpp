// 2022-03-13 10:22:57
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct LList{
    LList* next;
    LList* pre;
    int key;
    int val;
    LList() : next(nullptr), pre(nullptr), key(0), val(0){};
    LList(int k, int v) : next(nullptr), pre(nullptr), key(k), val(v){};
};


class LRUCache {
public:
    LList *head;
    LList *tail;
    unordered_map<int, LList*> ma;
    int cap;
    int now_cap;

    LRUCache(int capacity) {
        head = new LList();
        tail = new LList();
        head->next = tail;
        tail->pre = head;
        cap = capacity;
        now_cap = 0;
    }

    LList* remove(LList* n){
        LList* tmp = n;
        // printf("remove: %d ", n->val);
        n->pre->next = n->next;
        n->next->pre = n->pre;
        return tmp;
    }

    void insert(LList* n){
        n->next = head->next;
        head->next->pre = n;
        head->next = n;
        n->pre = head;
        return;
    }

    void printList(LList* headd){
        LList* h = headd;
        printf("\n-------------------\n");
        while(h){
            printf("%d->",h->val);
            h = h->next;
        }
        printf("\n");
        for(auto it: ma){
            printf("%d->",it.first);
        }
        printf("\n-------------");
    }

    int get(int key) {
        // printf("\nget: %d ", key);

        if (ma.count(key)){
            // printf("get-key: %d ", ma[key]->val);
            insert(remove(ma[key]));
            // printList(head);
            return ma[key]->val;
        }
        else{
            return -1;
        }
    }

    void put(int key, int value) {
        // printf("\nput: %d ", key);
        // if(head){
        //     printf("%d ", head);
        // }
        // else printf("head is null");

        if (ma.count(key)){
            ma[key]->val = value;
            insert(remove(ma[key]));
            return;
        }

        LList* tmp = new LList(key, value);
        if (now_cap == cap){
            // printf("\n tail->pre: %d \n", tail->pre->val);
            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // 这里一定要注意，是key 不是 val
            ma.erase(tail->pre->key);
            delete remove(tail->pre);
            insert(tmp);
        }
        else{
            now_cap++;
            insert(tmp);
        }
        ma[key] = tmp;

        // printList(head);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(LruCache, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().lruCache(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}