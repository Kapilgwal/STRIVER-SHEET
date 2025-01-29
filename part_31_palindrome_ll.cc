#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

void reverse(Node *&head)
{
    Node *back = NULL;
    Node *curr = head;
    Node *frwd = NULL;

    while (curr != NULL)
    {
        frwd = curr->next;
        curr->next = back;
        back = curr;
        curr = frwd;
    }

    head = back;
}

bool isPalindrome(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    reverse(slow->next);

    Node *ptr1 = head;
    Node *ptr2 = slow->next;

    while (ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}

int main()
{

    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 9);

    bool ans = isPalindrome(head);
    cout << ans << endl;
    return 0;
}