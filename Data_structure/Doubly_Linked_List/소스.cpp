#include<iostream>
#include <string>
using namespace std;
template <typename E >
struct Node {
	E elem;
	Node<E>* prev;
	Node<E>* next;
};
template <typename E>
class DLinked_List {
	Node<E>* header;
	Node<E>* trailer;

protected:
	void add(Node<E>* v, const E& e) {
		Node<E>* u = new Node<E>;
		u->elem = e;
		u->next = v;
		u->prev = v->prev;
		v->prev->next = u;
		v->prev = u;
	}
	void remove(Node<E>* v) {
		Node<E>* u = v->prev;
		Node<E>* w = v->next;
		u->next = w;
		w->prev = u;
		delete v;
	}

public:
	DLinked_List<E>() {
		header = new Node<E>;
		trailer = new Node<E>;
		header->next = trailer;
		trailer->prev = header;
	}
	bool empty() const {
		return (header -> next == trailer);
	}
	~DLinked_List<E>() {
		while (!empty()) removeFront();
		delete header;
		delete trailer;
	}
	const E& front() const {
		return header->next->elem;
	}
	const E& back() const {
		return trailer->prev->elem;
	}
	void addFront(const E& e) {
		add(header->next, e);
	}
	void addBack(const E& e) {
		add(trailer, e);
	}
	void removeFront(){
		remove(header->next);
	}
	void removeBack(){
		remove(trailer->prev);
	}
};
int main() {
	DLinked_List<int> test;
	test.addBack(4);
	test.addFront(3);
	test.addFront(4);
	cout << test.front() <<endl<< test.back();
}