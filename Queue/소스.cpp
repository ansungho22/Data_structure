#include<iostream>
#include <string>
using namespace std;
template <typename E >
struct Node {
	E elem;
	Node<E>* next;
};
class QueueEmpty{
public:
	QueueEmpty(string s) {
		cout << s << endl;
	}
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

template <typename E>
class LinkedQueue {
	int n;
	CLinked_List<E> C;
public:
	LinkedQueue() {
		n = 0;
	}
	int size() const {
		return n;
	}
	bool empty() const {
		return n == 0;
	}
	const E& front() const throw(QueueEmpty) {
		if (empty())
			throw QueueEmpty("front of empty queue");
		return C.front();
	}
	void enqueue(const E& e) {
		C.add(e);
		C.advance();
		n++;
	}
	void dequeue() throw(QueueEmpty) {
		if (empty())
			throw QueueEmpty("dequeue of empty queue");
		C.remove();
		n--;
	}
};
int main() {
	LinkedQueue<int> queue;
	queue.enqueue(4);
	
	cout << queue.front()<<queue.size();
	queue.dequeue();
	cout << queue.size();
}