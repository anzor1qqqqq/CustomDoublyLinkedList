#include <iostream>

using namespace std;

template <typename T>
struct Node {
	Node<T>* nextElem, *prevElem;
	T elem;

	Node(T elemParam = T(), Node<T>* prevElemParam = nullptr, Node<T>* nextElemParam = nullptr) {
		this->elem = elemParam;
		this->prevElem = prevElemParam;
		this->nextElem = nextElemParam;
	};
};

template <typename T>
class CustomList {
private:
	Node<T>* head, *tail;
	int sizeList;

public:

	CustomList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->sizeList = 0;
	};

	void addElemBack(T elem) {
		Node<T>* newNode = new Node<T>(elem);

		if (sizeList == 0) {
			this->head = newNode;
			this->tail = newNode;
		} else {
			newNode->prevElem = this->tail;

			this->tail->nextElem = newNode;

			this->tail = newNode;
		};

		this->sizeList++;
	};

};

int main() {
	CustomList<int> firstList;

	firstList.addElemBack(1);
	firstList.addElemBack(2);
	firstList.addElemBack(3);
	firstList.addElemBack(4);
};
