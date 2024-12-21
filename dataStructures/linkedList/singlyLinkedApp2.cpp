#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
//O(n)
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last_node = head;
        while (last_node->next){
            last_node = last_node->next;
        }
        last_node = new_node;
    }
};


int main() {
    
    return 0;
}