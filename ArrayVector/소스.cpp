#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

template <typename E>
struct Node {
	E elem;
	Node<E>* prev;
	Node<E>* next;
};

template <typename E>
class ArrayVector {
public:
	ArrayVector<E>() {
		capacity = 0;
		n = 0;
		A = NULL;
	}
	int size() const {
		return n;
	}
	bool empty() const {
		return size() == 0;
	}
	E& operator[](int i) {
		return A[i];
	}
	E& at(int i) {
		return A[i];
	}
	void erase(int i) {
		for (int j = i+1; j < n; j++)
		{
			A[j - 1] = A[j];
		}
		n--;
	}
	void reserve(int N) {
		if (capacity >= N) return;
		E* B = new E[N];
		for (int j = 0; j < n; j++)
		{
			B[j] = A[j];
		}
		if (A != NULL) delete[] A;
		A = B;
		capacity = N;
	}
	void insert(int i, const E& e) {
		if (n >= capacity)
		{
			reserve(max(1, 2 * capacity));
		}
		for (int j = n-1; j >=i; j--)
		{
			A[j + 1] = A[j];
		}
		A[i] = e;
		n++;
	}
private:
	int capacity;
	int n;
	E* A;
};

int main() {
	ArrayVector<int> A;

	cout << A.empty();
}