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

	void removeElemFront() {
		if (this->sizeList > 0) {
			Node<T>* tmp = this->head;

			this->head = tmp->nextElem;

			this->head != nullptr ? this->head->prevElem = nullptr : this->tail = nullptr;

			delete tmp;

			this->sizeList--;
		} else {
			abort();
		};
	};

	void removeElemBack() {
		if (this->sizeList > 0) {
			Node<T>* tmp = this->tail;

			this->tail = tmp->prevElem;

			this->tail != nullptr ? this->tail->nextElem = nullptr : this->head = nullptr;

			delete tmp;

			this->sizeList--;
		} else {
			abort();
		};
	};

	void removeElemIndex(int index) {
		if (this->sizeList > index) {
			if (index == 0) {
				this->removeElemFront();
			} else if (this->sizeList == index - 1) {
				this->removeElemBack();
			} else {
				Node<T>* current = this->head;

				for (int i = 0; i < index - 1; i++) {
					current = current->nextElem;
				};

				Node<T>* deleteElem = current->nextElem;

				current->nextElem = deleteElem->nextElem;

				current->nextElem->prevElem = deleteElem->prevElem;

				delete deleteElem;
			};

			this->sizeList--;
		} else {
			abort();
		};
	};

	T getElemIndex(int index) {
		if (this->sizeList > index) {
			T resul;

			if (this->sizeList / 2 >= index) {
				Node<T>* current = this->head;

				for (int i = 0; i < index; i++) {
					current = current->nextElem;
				};

				resul = current->elem;	
			} else {
				Node<T>* current = this->tail;

				for (int i = this->sizeList - (index + 1); i > 0; i--) {
					current = current->prevElem;
				};

				resul = current->elem;
			};
			
			return resul;
		};

		abort();
	};

	void clear() {
		while (this->sizeList != 0) {
			this->removeElemFront();
		};
	};

	~CustomList() {
		this->clear();
	}
};

int main() {
	CustomList<int> firstList;

	firstList.addElemBack(1);
	firstList.addElemBack(2);
	firstList.addElemBack(3);

	firstList.addElemIndex(4, 1);
	firstList.addElemIndex(5, 2);

	firstList.removeElemFront();

	firstList.removeElemIndex(1);

	//firstList.removeElemBack();

	cout << firstList.getElemIndex(0);

	cout << firstList.getElemIndex(2);
};