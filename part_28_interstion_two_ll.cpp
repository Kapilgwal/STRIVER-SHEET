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

int getLen(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

Node *intersection(Node *&head1, Node *&head2)
{
    int n1 = getLen(head1);
    int n2 = getLen(head2);
    Node *temp1 = head1;
    Node *temp2 = head2;

    if (n1 == n2)
    {
        while (temp1 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                return temp1;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    else if (n1 > n2)
    {
        int cnt = n1 - n2;

        while (cnt--)
        {
            temp1 = temp1->next;
        }

        while (temp1 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                return temp1;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    else if (n2 > n1)
    {
        int cnt = n2 - n1;

        while (cnt--)
        {
            temp2 = temp2->next;
        }

        while (temp1 != NULL)
        {
            if (temp1 == temp2)
            {
                return temp1;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    else
    {
        return NULL;
    }
}

int main()
{

    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 7);
    // insertAtTail(head1, 2);
    // insertAtTail(head1, 4);

    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(tail2, 6);
    insertAtTail(tail2, 1);

    Node *ans = intersection(head1, head2);
    cout << ans->data << endl;

    return 0;
}