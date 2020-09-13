#include<iostream>
#include <string>
using namespace std;

template <typename E >
struct Node {
	E elem;
	Node<E>* prev;
	Node<E>* next;
};

template <typename E >
class lterator {
public:
	lterator(Node<E>* u) {
		v = u;
	}
	E& operator*() {
		return v->elem;
	}
	bool opereator==(const lterator& p) const{
		return v == p.v;
	}
	bool opereator!=(const lterator& p) const{
		return v != p.v;
	}
	lterator& operator++() {
		v = v->next;
		return *this;
	}
	lterator& operator--() {
		v = v->prev;
		return *this;
	}
	friend class NodeList;
private:
	Node<E>* v;
	lterator(Node<E>* u);
};

template <typename E >
class NodeList {
private:
	Node<E> N;
public:
	lterator lter;
public:
	NodeList<E>() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	int size() const {
		return n;
	}
	bool empty() const {
		return (n == 0);
	}
	lterator<E> begin() const
	{
		return lter(header->next);
	}
	lterator<E> end() const
	{
		return lter(trailer);
	}
	void insert(const lter& p, const E& e) {
		Node* w = p.v;
		Node* u = w->prev;
		Node* v = new Node;
		v->elem = e;
		v->next = w;
		w->prev = v;
		v->prev = u;
		u->next = v;
		n++;
	}
	void insertFront(const E& e) {
		insert(begin(), e);
	}
	void insertBack(const E& e) {
		insert(end(), e);
	}
	void erase(const lter& p) {
		Node* v = p.v;
		Node* w = v->next;
		Node* u = v->prev;
		u->next = w;
		w->prev = u;
		delete v;
		n--;
	}
	void eraseFront() {
		erase(begin());
	}
	void eraseBack() {
		erase(--end());
	}
private:
	int n;
	Node* header;
	Node* trailer;
};

int main() {
	NodeList<int> list;
	cout << list.size();
}