#include<iostream>
#include <string>
using namespace std;
template <typename E>
struct Node {
	E elem;
	Node<E>* next;
};
template <typename E>
class LinkedList {

	Node<E>* head;
public:
	
	LinkedList<E>() {
		head=NULL;
	}
	bool empty() const {
		return head == NULL;
	}
	~LinkedList<E>() {
		while (!empty()) removeFront();
	}
	const E& front() const {
		return head->elem;
	}

	void addFront(const E& e) {
		Node<E>* v = new Node<E>;
		v->elem = e;
		v->next = head;
		head = v;
	}
	void removeFront() {
		Node<E>* old = head;
		head = old->next;
		delete old;
	}

};
int main() {
	LinkedList<string> s_list;
	LinkedList<int> i_list;
	s_list.addFront("hello");
	s_list.addFront("bye");
	cout << s_list.front();
	s_list.removeFront();
	cout << s_list.front();
	i_list.addFront(2046);
	cout << i_list.front();
}