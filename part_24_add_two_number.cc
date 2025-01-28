#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&tail, int temp) {
    Node *newNode = new Node(temp);
    tail->next = newNode;
    tail = newNode;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverse(Node *&head) {
    Node *back = NULL;
    Node *curr = head;
    Node *frwd = NULL;

    while (curr != NULL) {
        frwd = curr->next;
        curr->next = back;
        back = curr;
        curr = frwd;
    }

    head = back;
}

Node *addTwoNumber(Node *&head1, Node *&head2) {
    // Reverse both lists
    reverse(head1);
    reverse(head2);

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry > 0) {
        int val1 = (head1 != NULL) ? head1->data : 0;
        int val2 = (head2 != NULL) ? head2->data : 0;

        int sum = carry + val1 + val2;
        int rem = sum % 10;
        carry = sum / 10;

        // Insert at the tail of the result list
        insertAtTail(temp, rem);

        // Move pointers
        if (head1 != NULL) head1 = head1->next;
        if (head2 != NULL) head2 = head2->next;
    }

    // Reverse the result list
    Node *result = dummy->next;
    reverse(result);

    return result;
}

int main() {
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

    Node *mergedHead = addTwoNumber(head1, head2);
    cout << "Sum: ";
    print(mergedHead);

    return 0;
}
