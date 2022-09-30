#include "header.hpp"
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *groupPrev = new ListNode(-1, head);

        while (true)
        {
            // count k nodes
            auto k_node = getKth(groupPrev, k);
            // we don't handle the last k nodes
            if (k_node == nullptr)
                break;

            auto nextGroup = k_node->next;
            // reverse the group
            auto prev = k_node->next;
            auto curr = groupPrev->next;

            while (curr != nextGroup)
            {
                auto tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            // first node in group
            auto temp = groupPrev->next;
            // reset the start of the group
            groupPrev->next = k_node;
            // group prev equals to the first node in the group
            groupPrev = temp;
        }
    }

    ListNode *getKth(ListNode *node, int k)
    {
        while (node != nullptr and k > 0)
        {
            node = node->next;
            k--;
        }

        return node;
    }
};