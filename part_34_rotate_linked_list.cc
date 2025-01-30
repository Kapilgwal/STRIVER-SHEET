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
        next = nullptr;
    }
};

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void rotate(Node *&head, int k)
{
    if (!head || !head->next || k == 0)
        return;

    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    k = k % len;
    if (k == 0)
        return;

    k = len - k;

    Node *temp1 = head;
    for (int i = 1; i < k; i++)
    {
        temp1 = temp1->next;
    }

    Node *newHead = temp1->next;
    temp1->next = NULL;

    Node *temp4 = newHead;
    while (temp4->next != NULL)
    {
        temp4 = temp4->next;
    }

    temp4->next = head;
    head = newHead;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    print(head);
    rotate(head, 2);
    print(head);

    return 0;
}
