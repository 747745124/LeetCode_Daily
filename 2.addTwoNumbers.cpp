#include "header.hpp"
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *head = res;
        //initialize the current node
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        while (p1 != nullptr || p2 != nullptr)
        {
            int sum = 0;
            if (p1 == nullptr && p2 != nullptr)
                sum = carry + p2->val;
            if (p1 != nullptr && p2 == nullptr)
                sum = carry + p1->val;
            if (p1 != nullptr && p2 != nullptr)
                sum = carry + p1->val + p2->val;
            if (sum >= 10)
                carry = 1;
            else
                carry = 0;
            res->next = new ListNode(sum % 10);
            res = res->next;
            if (p1 != nullptr)
                p1 = p1->next;
            if (p2 != nullptr)
                p2 = p2->next;
        }
        if (carry)
        {
            res->next = new ListNode(1);
        }
        return head->next;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    ListNode *res = s.addTwoNumbers(l1, l2);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
