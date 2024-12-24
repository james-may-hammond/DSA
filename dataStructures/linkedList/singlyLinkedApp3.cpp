#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
//This is the most effiecient approach thus far O(1)

class Node{
public:
    int data;
    Node* next;
    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    void printlist(){
        Node* curr_node = head;
        while (curr_node) {
            cout<<curr_node->data<<" ";
            curr_node = curr_node->next;
        }
        cout<<endl;
    }
    bool searchLinkedList (int query) {
        Node* curr_node = head;
        while (curr_node !=nullptr){
            if (curr_node->data = query)
                return true;
            curr_node = curr_node->next;
        } 
        return false;
    }
    
};

int main() {
	  LinkedList alpha;
    alpha.append(1);
    alpha.append(2);
    alpha.append(3);
    alpha.append(4);
    alpha.append(5);
    bool a = alpha.searchLinkedList(1);
    alpha.printlist();
    return 0;
  
}
