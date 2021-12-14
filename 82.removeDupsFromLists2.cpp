#include "header.hpp"
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        ListNode *dummy = new ListNode(-101);
        dummy->next = head;
        ListNode *cur = dummy;

        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        bool flag = true;
        while (cur->next->next != nullptr)
        {
            if (cur->next->val != cur->next->next->val)
                flag = false;
            cur = cur->next;
        }
        if (flag)
            return nullptr;

        cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            if (cur->next->next->val == cur->next->val)
            {
                while (cur->next->next != nullptr && cur->next->next->val == cur->next->val)
                {
                    cur->next->next = cur->next->next->next;
                }
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }

        head = dummy->next;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    // head->next->next = new ListNode(3);

    head = s.deleteDuplicates(head);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}