// 2022-08-27 10:33:01
#include <gtest/gtest.h>
#include "../header.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr){
            return nullptr;
        }

        Node* tmp = head;
        while(tmp != nullptr){
            Node* n = new Node(tmp->val);
            n->next = tmp->next;
            n->random = tmp->random;
            tmp->next = n;
            tmp = n->next;
        }

        tmp = head->next;
        while(tmp != nullptr){
            if(tmp->random != nullptr){
                tmp->random = tmp->random->next;
            } else{
                tmp->random = nullptr;
            }
            if (tmp->next != nullptr){
                tmp = tmp->next->next;
            } else{
                break;
            }
        }
        tmp = head;
        Node* h = tmp;
        Node* res = head->next;
        while(tmp->next != nullptr){
            // printf("%d ", tmp->val);
            h = tmp->next;
            tmp->next = tmp->next->next;
            tmp = h;
        }

        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(FuZaLianBiaoDeFuZhiLcof, Example1) {      // NOLINT
        std::vector<int> nums = {  };
        auto ans = Solution().fuZaLianBiaoDeFuZhiLcof(nums);
        decltype(ans) rightAns = ;
        ASSERT_EQ(ans, rightAns);
    }

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}