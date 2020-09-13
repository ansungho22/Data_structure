#include<iostream>
#include <string>
using namespace std;
template <typename E>
struct Node {
	E elem;
	Node<E>* prev;
	Node<E>* next;
};

class DequeEmpty {
public:
	DequeEmpty(string s) {
		cout << s << endl;
	}
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
		return (header->next == trailer);
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
	void removeFront() {
		remove(header->next);
	}
	void removeBack() {
		remove(trailer->prev);
	}
};

template <typename E>
class LinkedDeque {

public:
	LinkedDeque<E>() {
		n = 0;
	}
	int size() const {
		return n;
	}
	bool empty() const {
		return n == 0;
	}
	const E& front() const throw(DequeEmpty) {
		if (empty())
			throw DequeEmpty("front of empty Deque");
		return D.front();
	}
	const E& back() const throw(DequeEmpty) {
		if (empty())
			throw DequeEmpty("front of empty Deque");
		return D.back();
	}
	void insertFront(const E& e) {
		D.addFront(e);
		n++;
	}
	void insertBack(const E& e) {
		D.addBack(e);
		n++;
	}
	void removeFront() throw(DequeEmpty) {
		if (empty())
			throw DequeEmpty("removeFront of empty deque");
		D.removeFront();
		n--;
	}
	void removeBack() throw(DequeEmpty) {
		if (empty())
			throw DequeEmpty("removeBack of empty deque");
		D.removeBack();
		n--;
	}
private:
	DLinked_List<E> D;
	int n;
};

int main() {
	LinkedDeque<int> deque;
	deque.insertFront(2);
	deque.insertBack(3);
	cout << deque.front() << deque.back();
}