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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        vector<int> nodeVals;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            auto tmp = curr;
            nodeVals.push_back(curr->val);
            curr = curr->next;
        }
        int n = nodeVals.size();
        if (!n)
            return nullptr;
        if (n == 1)
            return new ListNode(nodeVals[0]);
        for (int i = 0; i < n / 2; i++)
        {
            swap(nodeVals[2 * i], nodeVals[2 * i + 1]);
        }

        ListNode *node = new ListNode(nodeVals[0]);
        ListNode *header = node;
        for (int i = 0; i < n - 1; i++)
        {
            node->next = new ListNode(nodeVals[i + 1]);
            node = node->next;
        }
        return header;
    }

    ListNode *swapPairs_new(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode dummy(-1, head);
        ListNode *curr = head;
        ListNode *prev = &dummy;

        while (curr != nullptr && curr->next != nullptr)
        {
            auto first_node = curr;
            auto second_node = curr->next;

            prev->next = second_node;
            first_node->next = second_node->next;
            second_node->next = first_node;

            prev = first_node;
            curr = first_node->next;
        }

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
    head = s.swapPairs_new(head);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}