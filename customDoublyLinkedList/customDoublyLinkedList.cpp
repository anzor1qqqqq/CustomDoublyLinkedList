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

	void addElemFront(T newElem) {
		if (this->sizeList > 0) {
			Node<T>* newNode = new Node<T>(newElem, this->tail);

			this->tail->nextElem = newNode;

			this->tail = newNode;
		} else {
			this->addElemBack(newElem);
		}; 
	};
	
	void addElemIndex(T newElem, int index) {
		if (this->sizeList == 0 && index == 0) {
			this->addElemBack(newElem);
		} else if (this->sizeList > 0 && index == 0) {
			this->addElemFront(newElem);
 		} else if (this->sizeList > index) {

			if (this->sizeList / 2 >= index) {
				Node<T>* current = this->head;

				for (int i = 0; i < index - 1; i++) {
					current = current->nextElem;
				};

				current->nextElem = new Node<T>(newElem, current->nextElem->prevElem, current->nextElem);
				current->nextElem->nextElem->prevElem = current->nextElem;
			} else {
				Node<T>* current = this->tail;

				for (int i = this->sizeList; i > index + 1; i--) {
					current = current->prevElem;
				};

				current->prevElem = new Node<T>(newElem, current->prevElem, current->prevElem->nextElem);
				current->prevElem->prevElem->nextElem = current->prevElem;
			};

			this->sizeList++;
		} else {
			abort();
		};
	};
};

int main() {
	CustomList<int> firstList;

	firstList.addElemBack(1);
	firstList.addElemBack(2);
	firstList.addElemBack(3);

	firstList.addElemIndex(54, 1);
	firstList.addElemIndex(54, 2);
};
