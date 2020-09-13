#include<iostream>
#include <string>
using namespace std;
template <typename E >
struct Node {
	E elem;
	Node<E>* next;
};
template <typename E>
class CLinked_List {
	Node<E>* cursor;


public:
	bool empty() const {
		return (cursor == NULL);
	}
	CLinked_List<E>() {
		cursor = NULL;
	}
	~CLinked_List<E>() {
		while (!empty()) remove();
	}
	const E& front() const {
		return cursor->next->elem;
	}
	const E& back() const {
		return cursor->elem;
	}
	void advance() {
		cursor = cursor->next;
	}
	void add(const E& e) {
		Node<E>* v = new Node<E>;
		v->elem = e;
		if (cursor == NULL) {
			v->next = v;
			cursor = v;
		}
		else {
			v->next = cursor->next;
			cursor->next = v;
		}
	}
	void remove() {
		Node<E>* old = new Node<E>;
		if (old == cursor) {
			cursor = NULL;
		}
		else {
			cursor->next = old->next;
		}
		delete old;
	}
};
int main() {
	CLinked_List<int> test;
	test.add(4);
	test.add(3);
	test.add(2);
	cout << test.front() << endl;
	test.advance();
	test.advance();
	test.advance();
	cout << test.front() << endl;
}