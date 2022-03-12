#include "header.hpp"
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *cur = head;
        Node *newHead = nullptr;
        Node *newTail = nullptr;

        unordered_map<Node *, Node *> forwardList;
        forwardList[nullptr] = nullptr;

        while (cur != nullptr)
        {
            // first round, create the new head
            if (newHead == nullptr)
            {
                newHead = new Node(cur->val);
                newTail = newHead;
            }
            else
            { // copy the next node and move to it
                newTail->next = new Node(cur->val);
                newTail = newTail->next;
            }
            // copy each node's predecessor
            forwardList[cur] = newTail;
            cur = cur->next;
        }

        cur = newHead;
        while (cur != nullptr)
        {
            cur->random = forwardList[head->random];
            head = head->next;
            cur = cur->next;
        }

        return newHead;
    }
};