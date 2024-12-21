#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

class Node {
public:
    // Our base variables
    int data;
    Node* next;
    // constructor to initialize node with the data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void printList (Node* curr) {
    while (curr != nullptr) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node(1);
    Node* seceond = new Node(2);
    Node* third = new Node(3);

    head ->next = seceond;
    seceond ->next = third;
    printList(head);
    return 0;
}