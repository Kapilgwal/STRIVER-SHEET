#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// This function has been explained
// in previous videos/articles

// Function to reverse a linked list
// using the 3-pointer approach
Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at
   // head of linked list
   Node* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   Node* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       Node* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

// Function to get the Kth node from
// a given position in the linked list
Node* getKthNode(Node* temp, int k){
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 

    // Decrement K until it reaches
    // the desired position
    while(temp != NULL && k > 0){
        // Decrement k as temp progresses
        k--; 
        
        // Move to the next node
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
}

// Function to reverse nodes in groups of K
Node* kReverse(Node* head, int k){
    // Initialize a temporary
    // node to traverse the list
    Node* temp = head; 

    // Initialize a pointer to track the
    // ;ast node of the previous group
    Node* prevLast = NULL; 
    
    // Traverse through the linked list
    while(temp != NULL){
        // Get the Kth node of the current group
        Node* kThNode = getKthNode(temp, k); 

        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            
            break; 
        }
        
 
        Node* nextNode = kThNode -> next; 

        kThNode -> next = NULL; 

        reverseLinkedList(temp); 
     
        if(temp == head){
            head = kThNode;
        }else{
            prevLast -> next = kThNode; 
        }

        prevLast = temp; 

        temp = nextNode; 
    }
    
    return head; 
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}