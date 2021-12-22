#include "header.hpp"
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
// reorder the list in the form of l1->ln->l2->ln-1->l3->ln-2->...
// convert list to vector
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head != NULL && head->next != NULL && (head->next)->next != NULL)
        {
            vector<ListNode *> v;
            ListNode *cur = head;
            while (cur)
            {
                v.push_back(cur);
                cur = cur->next;
            }
            int i = 0, s = v.size() - 1, k = (s + 1) / 2;
            for (i; i < k; s--)
            {
                v[i]->next = v[s];
                v[s]->next = v[++i];
            }
            v[i]->next = NULL;
        }
    }
};