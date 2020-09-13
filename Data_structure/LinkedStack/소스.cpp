#include<iostream>
#include <string>
using namespace std;
//노드구조
template <typename E>
struct Node {
	E elem;
	Node<E>* next;
};
//예외처리
class StackEmpty {
public:
	StackEmpty(string s) {
		cout << s << endl;
	}
};
//list
template <typename E>
class LinkedList{

	Node<E>* head;
public:

	LinkedList<E>() {
		head = NULL;
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
//stack
template <typename E>
class LinkedStack {

	int n = 0;
	LinkedList<E> S;
public:

	LinkedStack<E>() {
		n = 0;
	}
	int size() const {
		return n;
	}
	bool empty() const {
		return n == 0;
	}
	const E& top() const throw (StackEmpty) {
		if (empty()) throw StackEmpty("Top of empty stack");
		return S.front();
	}
	void push(const E& e) {
		++n;
		S.addFront(e);
	}
	void pop() throw(StackEmpty) {
		if (empty()) throw StackEmpty("Pop from empty stack");
		--n;
		S.removeFront();
	}
};
//test
int main() {
	LinkedStack<int> stack;

	stack.push(1);
	stack.push(2);
	cout << stack.size();
	stack.pop();
	cout << stack.size();
}