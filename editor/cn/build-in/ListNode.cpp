//
// Created by sj on 2021/11/14.
//


#include "ListNode.h"

namespace LeetCode
{
    void print_list(ListNode* head){
        while (head != nullptr){
            std::cout << head->val;
            if (head->next != nullptr){
                std::cout << "->";
            }
            head = head->next;
        }
        std::cout << std::endl;
    }

    bool is_same_list(ListNode* l1, ListNode* l2){
        // flag = true;
        while (l1 != nullptr and l2 != nullptr and l1->val == l2->val){
            l1 = l1->next;
            l2 = l2->next;
        }
        return (l1 == nullptr) and (l2 == nullptr);
    }

    List::List() {
        this->head = nullptr;
    }

    List::List(std::initializer_list<int> l) : head(nullptr), tail(nullptr){
        for (auto it: l) {
            insert(it);
        }
    }

    List::~List()
    {
        ListNode *del_p = nullptr;
        while (head != nullptr)
        {
            del_p = head->next;
            delete head;
            head = del_p;
        }
        delete head;
    }

    void List::insert(int x)
    {
        if (head == nullptr)
            head = tail = new ListNode(x);
        else
        {
            ListNode *p = new ListNode(x);
            tail->next = p;
            tail = p;
            tail->next = nullptr;
        }
    }

    void List::print()
    {
        print_list(this->head);
    }

    bool List::operator==(const List &l1) const
    {
        return is_same_list(this->head, l1.head);
    }
} // namespace LeetCode