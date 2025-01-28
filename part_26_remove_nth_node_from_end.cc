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

void print(Node *head) {
    Node *temp = head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertAtTail(Node *&tail, int temp) {
    Node *newNode = new Node(temp);
    tail->next = newNode;
    tail = newNode;
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

void removeNode(Node *&head, int cnt) {
    if (cnt <= 0 || head == NULL) {
        return;
    }

    reverse(head);

    Node *curr = head;
    Node *prev = NULL;

    while (cnt > 1 && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt--;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr; 
    }

    reverse(head);
}

int main() {
    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    cout << "Original List: ";
    print(head);

    removeNode(head, 2); 
    cout << "After Removing 2nd Node from End: ";
    print(head);

    return 0;
}
