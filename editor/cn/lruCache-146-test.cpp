// 2022-01-13 00:21:54
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct LListNode {
    LListNode *next;
    LListNode *pre;
    int key;
    int val;

    LListNode() : key(0), val(0), next(nullptr), pre(nullptr) {}

    LListNode(int k, int v) : key(k), val(v), next(nullptr), pre(nullptr) {}
};

class DList {
public:
    LListNode *head;
    LListNode *tail;

    DList() {
        head = new LListNode();
        tail = new LListNode();
        head->next = tail;
        tail->pre = head;
    }

    void removeNode(LListNode *node) {
        // auto tmp = node;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
    }

    void setAsHead(LListNode *node) {
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
    }

    int getKey(LListNode *node) {
        return node->val;
    }

    void moveHead(LListNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        setAsHead(node);
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, LListNode *> ma;
    DList dl;
    int size;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (ma.count(key)) {
            dl.moveHead(ma[key]);
            return ma[key]->val;

        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (ma.count(key)) {
            ma[key]->val = value;
            dl.moveHead(ma[key]);
        } else {
            auto node = new LListNode(key, value);
            size++;
            if (size <= cap) {
                ma[key] = node;
                dl.setAsHead(node);
            } else {
                ma[key] = node;
                ma.erase(dl.tail->pre->key);
                dl.removeNode(dl.tail->pre);
                --size;
                dl.setAsHead(node);
            }
        }
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
        std::vector<int> nums = {};
        auto ans = Solution().lruCache(nums);
        decltype(ans) rightAns =;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}