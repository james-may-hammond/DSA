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
		next = prev = nullptr;
	}
};

class LinkedList{
public:
	Node* delHead (Node* head) {
		if (head == nullptr) return nullptr;
		Node* tmp = head;
		head = head->next;
		if (head != nullptr) head ->prev = nullptr;
		delete tmp;
		return head;
	}
	Node* delTail (Node* head) {
		if (head == nullptr) return nullptr;
		// This time we need to account for both corner cases
		if (head->next == nullptr) {
			delete head;
			return nullptr;
		}
		// Traversing to the last node
		Node* curr_node = head;
		while (curr_node!=nullptr) {
			curr_node = curr_node->next;
		}
		// the node before curr_node points to null
		curr_node->prev->next = nullptr;
		delete curr_node;
		return head;
	}
	Node* delIndex (Node* head, int pos) {
		Node* curr_node = head;
		int ind = 0;
		while (ind != pos) {
			curr_node = curr_node->next;
			ind++;
		}
		if (!curr_node) return head;
		if (curr_node->prev) curr_node->prev->next = curr_node->next;
		if (head==curr_node) head = curr_node->next;
		
		delete curr_node;
		return head;
	}
	
	void printlist (Node* head) {
		Node* curr_node = head;
		while (curr_node != nullptr) {
			cout<<curr_node->data<<" ";
			curr_node = curr_node->next;
		}
		cout<<endl;
	}
};

int main() {
	LinkedList ll;
	// hardcoding in a list
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->prev = head;
	head->next->next = new Node(3);
	head->next->next->prev = head->next;
	cout<<"Orignal List ";
	ll.printlist(head);
	head = ll.delHead(head);
	cout<<"new List ";
	ll.printlist(head);
	head = ll.delIndex(head, 1);
	cout<<"new List ";
	ll.printlist(head);
	return 0;
}