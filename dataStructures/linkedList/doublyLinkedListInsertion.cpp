#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
class Node{
public:
	int data;
	Node* prev;
	Node* next;
	Node(int d){
		data = d;
		next = nullptr;
		prev = nullptr;
	}
};
class LinkedList{
public:
	Node* insertAtHead(Node* head, int new_data){
		Node* new_node = new Node(new_data);
		new_node->next = head;
		if (head !=NULL)
				head->prev = new_node;
		return new_node;
	}
	
	void printlist(Node* head){
		Node* curr_node = head;
		while(curr_node!=NULL){
			cout<<curr_node->data<<" ";
			curr_node = curr_node->next;
		}
		cout<<endl;
	}
	
	Node* insertAfterNode(int new_data, Node* head, int key){
		Node* curr_node = head;
		while (curr_node!=nullptr) {
			if (curr_node->data == key) {
				break;
			}
			curr_node = curr_node->next;
		}
		// this shall occour in case of node not found
		if (curr_node==nullptr) return head;
		Node* new_node = new Node(new_data);
		new_node->prev = curr_node;
		new_node->next = curr_node->next;
		curr_node->next = new_node;
		if (new_node->next != nullptr) {
			//this sets the pointer of the prev node
			new_node->next->prev = new_node;
		}
		return head;
	}
	
	Node* insertBeforeNode(int new_data, Node* head, int key){
		Node* curr_node = head;
		while (curr_node!=nullptr) {
			if (curr_node->data == key) {
				break;
			}
			curr_node = curr_node->next;
		}
		// this shall occour in case of node not found
		if (curr_node==nullptr) return head;
		Node* new_node = new Node(new_data);
		new_node->prev = curr_node->prev;
		new_node->next = curr_node;
		if (curr_node->prev !=NULL) {
			//this sets the pointer of the prev node
			new_node->prev->next = new_node;
		} else {
			head = new_node;
		}
		curr_node->prev = new_node;
		return head;
	}
	
	Node* insertAtIndex (int new_data, Node* head, int index) {
		Node* curr_node = head;
		int ind = 0;
		// Inserting at the start
		Node* new_node = new Node(new_data);
		if (index==0){
			new_node->next = head;
			new_node->prev = nullptr;
			if (head!=nullptr) head->prev = new_node;
			return new_node;
		}
		while (ind!=index){
			curr_node = curr_node->next;
			ind++;
		}
		// Index out of bounds
		if (curr_node == nullptr && ind!=index) {
			cout<<"Index is out of bounds!"<<endl;
			return head;
		}
		
		new_node->prev = curr_node->prev;
		new_node->next = curr_node;
		if (curr_node->prev != nullptr) curr_node->prev->next = new_node;
		curr_node->prev = new_node;
		return head;
	}
	
	Node* insertAtEnd (int new_data, Node* head) {
		Node* new_node = new Node(new_data);
		if (head == NULL) head = new_node;
		else{
			Node* curr_node = head;
			while (curr_node->next != nullptr) {
				curr_node = curr_node->next;
			}
			curr_node->next = new_node;
			new_node->prev = curr_node;
		}
		return head;
	}
};
using namespace std;
int main() {
	LinkedList ll;
	Node* head = new Node(2);
	head->next = new Node(3);
	head->next->prev = head;
	head->next->next = new Node(4);
	head->next->next->prev = head->next;
	cout<<"Orignal List ";
	ll.printlist(head);
	head = ll.insertAtHead(head, 10);
	cout<<"new List ";
	ll.printlist(head);
	head = ll.insertAfterNode(14, head, 3);
	cout<<"new List ";
	ll.printlist(head);
	head = ll.insertBeforeNode(9, head, 14);
	cout<<"new List ";
	ll.printlist(head);
	head = ll.insertAtIndex(5, head, 3);
	cout<<"new List ";
	ll.printlist(head);
//	head = ll.insertAtIndex(100, head, 99);
//	cout<<"new List ";
//	ll.printlist(head);
	head = ll.insertAtEnd(55, head);
	cout<<"new List ";
	ll.printlist(head);
	return 0;
}