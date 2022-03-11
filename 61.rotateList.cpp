/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "header.hpp"
// the key is to make the list circular first
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        int num = 1;
        ListNode *counter = head;
        while (counter->next != nullptr)
        {
            counter = counter->next;
            num++;
        }
        // if num = 5, a->b->c->d->e
        // k = 2, it should be d->e->a->b->c

        // k = 5-2 = 3
        // now counter is at the new head, making it circular
        counter->next = head;
        k = num - k % num;
        // move forward to the end of the list
        while (k != 0)
        {
            counter = counter->next;
            k--;
        }
        // save the head
        head = counter->next;
        // make it non circular
        counter->next = nullptr;
        return head;
    }
};