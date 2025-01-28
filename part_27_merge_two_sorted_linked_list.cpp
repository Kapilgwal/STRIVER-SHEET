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

void insertAtTail(Node *&tail, int temp)
{
    Node *newNode = new Node(temp);
    tail->next = newNode;
    tail = newNode;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node *mergeLL(Node *&head1, Node *&head2)
{
    Node *dummy = new Node(-1); // Dummy node for easier implementation
    Node *temp = dummy;

    // Merge both linked lists
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            insertAtTail(temp, head1->data);
            head1 = head1->next;
        }
        else
        {
            insertAtTail(temp, head2->data);
            head2 = head2->next;
        }
    }

    // Add remaining elements of head1, if any
    while (head1 != NULL)
    {
        insertAtTail(temp, head1->data);
        head1 = head1->next;
    }

    // Add remaining elements of head2, if any
    while (head2 != NULL)
    {
        insertAtTail(temp, head2->data);
        head2 = head2->next;
    }

    return dummy->next; // Skip the dummy node and return the merged list
}

int main()
{
    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 7);

    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);
    insertAtTail(tail2, 8);

    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);

    Node *mergedHead = mergeLL(head1, head2);
    cout << "Merged List: ";
    print(mergedHead);

    return 0;
}
