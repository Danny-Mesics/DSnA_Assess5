#pragma once
#include <iostream>
using namespace std;

class List {
protected:
	struct Node {
	public:
		Node() {}
		Node(int data) : data{ data }, next{ nullptr }, previous{ nullptr } {}
		~Node() {
			if (next != nullptr) {
				delete next;
			}
		}
		int data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;
	int numberOfNodes;

public:
	struct Iterator {
	private:
		Node* value;
	public:
		Iterator(Node* value) : value{ value } {}

		Iterator& operator++() { // Prefix ++i so increases then we use
			value = value->next;
			return *this;
		}

		Iterator& operator++(int) { // Postfix i++ where we use it then it increases
			Iterator tmp = *this;
			value = value->next;
			return tmp;
		}

		Iterator& operator--() { // Prefix --i so decreases then we use
			value = value->previous;
			return *this;
		}

		Iterator& operator--(int) { // Postfix i-- where we use it then it decreases
			Iterator tmp = *this;
			value = value->previous;
			return tmp;
		}

		bool operator!=(const Iterator& rhs) {
			return value != rhs.value;
		}
		bool operator==(const Iterator& rhs) {
			return value == rhs.value;
		}


		int operator*() {
			return value->data;
		}

		Node* operator->() {
			return value;
		}

		Node* GetValue() {
			return value;
		}
	};

	List() {
		head = nullptr;
		tail = nullptr;
	}

	~List() {
		if (!IsEmpty()) {
			Clear();
		}
	}

#pragma region Adding Methods

	void PushFront(int data) {
		Node* newNode = new Node(data);
		if (IsEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		numberOfNodes++;
	}

	void PushBack(int data) {
		Node* newNode = new Node(data);
		if (IsEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		numberOfNodes++;
	}

	// Insert a new node after the current node
	void Insert(int insertAfterThisNode, int value) {
		Node* newNode = new Node(value);
		for (auto i = Begin(); i != End();) {
			if (IsEmpty()) {
				head = newNode;
				tail = newNode;
				numberOfNodes++;
				continue;
			}
			// TO DO: check if i exists
			else if (*i == insertAfterThisNode) {
				newNode->next = i->next;
				i->next = newNode;
				newNode->previous = i.GetValue();

				if (i == tail) {
					tail = newNode;
				}
				numberOfNodes++;
			}
			++i;
		}
	}
#pragma endregion

#pragma region Removal Methods

	// It is necessary to set nullptr on the linking pointers
	// before calling delete as the way node destructors are set up
	// causes a chain reaction of deleting through the list


	//Remove the first element of the list
	void PopFront() {
		if (IsEmpty()) {
			return;
		}

		Node* temp = head;

		// 
		if (head->next != nullptr) {
			head->next->previous = nullptr;
		}

		head = head->next;
		temp->next = nullptr;

		delete temp;
		temp = nullptr;

		numberOfNodes--;
	}

	//Remove the last element of the list
	void PopBack() {
		if (IsEmpty()) {
			return;
		}

		Node* temp = tail;

		if (tail->previous != nullptr) {
			tail->previous->next = nullptr;
		}

		tail = tail->previous;
		temp->previous = nullptr;

		delete temp;
		temp = nullptr;

		numberOfNodes--;
	}


	void Remove(int value) {
		// The iterator will be set to the previous node of i
		Iterator iterator(nullptr);

		for (auto i = Begin(); i != End();) {
			if (*i == value) {
				// If i is the head
				if (i.GetValue() == head) {
					head = i->next;
					Node* temp = i.GetValue();
					++i;
					i->next = nullptr;
					delete temp;
					numberOfNodes--;
					continue;
				}
				// If i is the tail
				else if (i.GetValue() == tail) {
					iterator->next = tail->next;
					delete tail;
					tail = iterator.GetValue();
					numberOfNodes--;
					return;
				}
				// if i is at an arbitary location in the list
				else {
					iterator->next = i->next;
					i->next->previous = iterator.GetValue();
					Node* temp = i.GetValue();
					++i;
					temp->next = nullptr;
					delete temp;
					numberOfNodes--;
					continue;
				}
			}

			iterator = i;
			i++;
		}
	}
#pragma endregion

#pragma region Return Values

	//Returns head by value
	int First() {
		if (head != nullptr)
			return head->data;
	}

	//Returns tail by value
	int Last() {
		if (tail != nullptr)
			return tail->data;
	}

	//Returns an Iterator to first position of list
	Iterator Begin() {
		return Iterator(head);
	}

	//Returns an Iterator to last position of list
	Iterator End() {
		return Iterator(nullptr);
	}

	int Count() {
		return numberOfNodes;
	}

	bool IsEmpty() {
		return head == nullptr;
	}

	bool IsSorted() {
		for (auto i = Begin(); i != End(); i++) {
			if (i->next != nullptr && i->data > i->next->data) {
				return false;
			}
		}
		return true;
	}

#pragma endregion


	void Clear() {
		delete head;
		numberOfNodes = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PrintList() {
		cout << "IsEmpty(): " << IsEmpty() << "\t(0 = false, 1 = true)" << endl;
		cout << "Count(): " << Count() << endl;
		if (!IsEmpty()) {
			cout << "First(): " << First() << endl;
			cout << "Last(): " << Last() << endl << endl;
			cout << "The List:" << endl;
			for (auto i = Begin(); i != End(); i++) {
				cout << *i << ", ";
			}
		}
	}

	void InsertionSort() {
		for (auto i = Begin(); i != End();) {
			Node* nodeToPass = i.GetValue();
			if (nodeToPass == nullptr) {
				return;
			}
			i++;

			nodeToPass->next = nullptr;
			nodeToPass->previous = nullptr;
			SortedInsert(nodeToPass);
		}
	}
private:
	void SortedInsert(Node*& currentNode) {
		if (IsSorted()) {
			for (auto i = Begin(); i != End();) {
				if (currentNode == head) {
					return;
				}
				if (currentNode->data <= head->data) {
					currentNode->next = head;
					head->previous = currentNode;
					head = currentNode;
					return;
				}
				else {
					while (i->next != nullptr && i->next->data < currentNode->data) {
						i++;
					}

					currentNode->next = i->next;

					if (i->next != nullptr) {
						currentNode->next->previous = currentNode;
					}
					else {
						tail = currentNode;
					}

					i->next = currentNode;
					currentNode->previous = i.GetValue();
				}
				return;
			}
		}
	}

};