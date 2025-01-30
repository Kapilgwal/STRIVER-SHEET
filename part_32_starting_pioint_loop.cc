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

bool isCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
        {
            return true;
        }

        fast = fast->next;
    }

    return false;
}

Node *startingPoint(Node *head)
{

    set<Node *> st;

    while (head != NULL)
    {
        if (st.find(head) == st.end())
        {
            st.insert(head);
            head = head->next;
        }

        else
        {
            return head;
        }
    }

    return NULL;
}

Node * startingPointBetter(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    Node *seventh = new Node(6);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    Node *ans = startingPoint(first);
    cout << ans->data << endl;

    return 0;
}