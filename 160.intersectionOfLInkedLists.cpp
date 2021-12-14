#include "header.hpp"
class Solution
{
public:
    //key: wait till the same start
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0;
        int lenB = 0;

        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }

        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;

        if (lenA > lenB)
        {
            int diff = lenA - lenB;
            while (diff != 0)
            {
                curA = curA->next;
                diff--;
            }

            while (curA != curB)
            {
                if (!curA || !curB)
                    return nullptr;
                curA = curA->next;
                curB = curB->next;
            }
        }
        else
        {

            int diff = lenB - lenA;
            while (diff != 0)
            {
                curB = curB->next;
                diff--;
            }

            while (curA != curB)
            {
                if (!curA || !curB)
                    return nullptr;
                curA = curA->next;
                curB = curB->next;
            }
        }

        return curA;
    }
};