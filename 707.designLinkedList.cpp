#include "header.hpp"

class MyLinkedList
{
public:
    MyLinkedList()
    {
        dummy = new ListNode(-1);
        head = nullptr;
        tail = nullptr;
    }

    int get(int index)
    {
        if (head == nullptr)
            return -1; // not initialized
        if (index >= size)
            return -1;
        if (index == 0)
            return head->val;

        ListNode *curr = head;
        while (index--)
        {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val)
    {

        ListNode *temp = new ListNode(val, dummy->next);
        dummy->next = temp;
        head = temp;
        if (size == 0)
            tail = head;
        size++;
    }

    void addAtTail(int val)
    {
        if (size == 0) // not initialized;
        {
            ListNode *temp = new ListNode(val, dummy->next);
            dummy->next = temp;
            head = temp;
            tail = head;
            size++;
            return;
        }
        ListNode *temp = new ListNode(val);
        tail->next = temp;
        tail = temp;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index == size)
            return addAtTail(val);
        if (index == 0)
            return addAtHead(val);
        if (index > size)
            return;

        ListNode *curr = head;
        ListNode *prev = dummy;
        while (index--)
        {
            curr = curr->next;
            prev = prev->next;
        }

        ListNode *temp = new ListNode(val, curr);
        prev->next = temp;

        size++;
    }

    void deleteAtIndex(int index)
    {
        if (head == nullptr)
            return; // not initialized
        if (index >= size || index < 0)
            return;

        ListNode *curr = head;
        ListNode *prev = dummy;
        while (index--)
        {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        head = dummy->next; // there could be a new head
        if (index == (size - 1))
            tail = prev;
        size--;
    }

private:
    ListNode *dummy;
    ListNode *head;
    ListNode *tail;
    int size = 0;
};

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtIndex(0, 10);
    obj->addAtIndex(0, 20);
    obj->addAtIndex(1, 30);
    cout << obj->get(0) << endl;
    return 0;
}