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

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node *&head)
{
    Node *back = NULL;
    Node *temp = head;
    Node *frwd = NULL;

    while (temp != NULL)
    {
        frwd = temp->next;
        temp->next = back;
        back = temp;
        temp = frwd;
    }

    head = back;
}

int main()
{

    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 4);
    print(head);
    reverse(head);
    print(head);
    return 0;
}