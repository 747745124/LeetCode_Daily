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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *next = head;
        ListNode dummy(0, head);

        ListNode *prev = &dummy;

        while (n--)
            next = next->next;

        while (next != nullptr)
        {
            prev = prev->next;
            next = next->next;
        }

        prev->next = prev->next->next;

        return dummy.next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = s.removeNthFromEnd(head, 2);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}