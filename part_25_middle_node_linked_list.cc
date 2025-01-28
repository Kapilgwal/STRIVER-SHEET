#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node * &tail,int temp){
    Node * newNode = new Node(temp);
    tail -> next = newNode;
    tail = newNode;
}

void print(Node * head){
    Node * temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

Node * middleLL(Node * &head){
    Node * slow = head;
    Node * fast = head;

    while(fast != NULL and fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // head = slow;
    return slow;
}

int main() {

Node * head = new Node(1);
Node * tail = head;
insertAtTail(tail,2);
insertAtTail(tail,3);
insertAtTail(tail,4);
insertAtTail(tail,5);
insertAtTail(tail,6);
insertAtTail(tail,7);
print(head);
Node * newHead = middleLL(head);
print(newHead);



return 0;
}