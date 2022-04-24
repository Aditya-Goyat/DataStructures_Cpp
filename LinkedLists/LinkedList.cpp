#include <iostream>

using namespace std;

class Node {
private:
	int value;
	Node* next;
	Node(int value) {
		next = nullptr;
		this->value = value;
	}
	Node() {
		next = nullptr;
		this->value = NULL;
	}
	
	friend class LinkedList;
	friend class DoubleLinkedList;
};

class LinkedList {
	Node* head;

public:

	LinkedList() {
		head = nullptr;
	}

	void Display() {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			Node* currentNode = new Node();
			currentNode = head;

			while (currentNode != nullptr) {
				cout << currentNode->value << endl;
				currentNode = currentNode->next;
			}
		}
	}

	void InsertAtBeginning(int value) {
		if (head == nullptr) {
			head = new Node(value);
		}
		else {
			Node* temp = new Node(value);
			temp->next = head;
			head = temp;
		}
	}

	void InsertAtEnd(int value) {
		if (head == nullptr) {
			head = new Node(value);
		}
		else {
			Node* currentNode = new Node();
			currentNode = head;

			while (currentNode->next != nullptr) {
				currentNode = currentNode->next;
			}

			currentNode->next = new Node(value);
		}
	}

	void InsertAtPosition(int value, int position) {
		if (head == nullptr) {
			if (position == 1)
				InsertAtBeginning(value);
			else {
				cout << "Linked list is empty" << endl;
				return;
			}
		}
		else {
			Node* currentNode = new Node();
			currentNode = head;

			for (int i = 1; i < position - 1; i++) {
				currentNode = currentNode->next;

				if (currentNode == nullptr) {
					cout << "Position value is out of linked list range" << endl;
					return;
				}
			}

			Node* temp = new Node(value);
			temp->next = currentNode->next;
			currentNode->next = temp;

		}
	}

	void DeleteFromBeginning() {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			if (head->next == nullptr) {
				free(head);
				return;
			}

			Node* newHead = new Node();
			newHead = head->next;
			free(head);
			head = newHead;
		}
	}

	void DeleteFromEnd() {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			Node* currentNode = new Node();
			currentNode = head;

			while (currentNode->next->next != nullptr) {
				currentNode = currentNode->next;
			}

			free(currentNode->next);
			currentNode->next = nullptr;
		}
	}

	void DeleteFromPosition(int position) {
		if (position == 1) {
			DeleteFromBeginning();
			return;
		}
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			Node* currentNode = new Node();
			currentNode = head;

			for (int i = 1; i < position - 1; i++) {
				currentNode = currentNode->next;

				if (currentNode == nullptr) {
					cout << "Position value is out of linked list range" << endl;
					return;
				}
			}

			Node* temp = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(temp);
		}
	}
};

class DoubleNode {
public:
	int value;
	DoubleNode* next;
	DoubleNode* prev;
	DoubleNode(int value) {
		prev = nullptr;
		next = nullptr;
		this->value = value;
	}
	DoubleNode() {
		prev = nullptr;
		next = nullptr;
		this->value = NULL;
	}
};

class DoubleLinkedList {
	DoubleNode* head;

public:
	DoubleLinkedList() {
		head = nullptr;
	}

	void Display() {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			DoubleNode* currentNode = head;

			while (currentNode != nullptr) {
				cout << currentNode->value << endl;
				currentNode = currentNode->next;
			}
		}
	}

	void InsertAtBeginning(int value) {
		if (head == nullptr) {
			head = new DoubleNode(value);
		}
		else {
			DoubleNode* temp = new DoubleNode(value);
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void InsertAtEnd(int value) {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			DoubleNode* currentNode = head;
			DoubleNode* temp = new DoubleNode(value);

			while (currentNode->next != nullptr) {
				currentNode = currentNode->next;
			}

			currentNode->next = temp;
			temp->prev = currentNode;
		}
	}

	void InsertAtPosition(int value, int position) {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			DoubleNode* currentNode = head;

			for (int i = 1; i < position - 1; i++) {
				currentNode = currentNode->next;

				if (currentNode == nullptr) {
					cout << "Position value is out of linked list range" << endl;
					return;
				}
			}

			DoubleNode* temp = new DoubleNode(value);
			currentNode->next->prev = temp;
			temp->next = currentNode->next;
			temp->prev = currentNode;
			currentNode->next = temp;
		}
	}

	void DeleteFromBeginning() {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			if (head->next == nullptr) {
				free(head);
				return;
			}

			DoubleNode* temp = head;
			head->next->prev = nullptr;
			head = head->next;
			free(temp);
		}
	}

	void DeleteFromEnd() {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}

		DoubleNode* currentNode = head;

		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
		}

		DoubleNode* temp = currentNode->prev;

		temp->next = nullptr;
		free(currentNode);
	}

	void DeleteFromPosition(int position) {
		if (head == nullptr) {
			cout << "Linked list is empty" << endl;
			return;
		}
		else {
			if (position == 1) {
				DeleteFromBeginning();
				return;
			}
			else {
				DoubleNode* currentNode = head;

				for (int i = 1; i < position - 1; i++) {
					currentNode = currentNode->next;

					if (currentNode == nullptr) {
						cout << "Position value is out of linked list range" << endl;
						return;
					}
				}

				DoubleNode* nextNode = currentNode->next->next;
				DoubleNode* temp = currentNode->next;

				currentNode->next = nextNode;
				nextNode->prev = currentNode;
				free(temp);
			}
		}
	}
};

int main() {

	LinkedList l;

	l.InsertAtBeginning(20);
	l.InsertAtBeginning(10);
	l.InsertAtEnd(30);
	l.InsertAtEnd(40);
	l.InsertAtPosition(25, 3);
	l.Display();

	cout << "---------" << endl;

	l.DeleteFromBeginning();
	l.Display();

	cout << "---------" << endl;

	l.DeleteFromEnd();
	l.Display();

	cout << "---------" << endl;

	l.DeleteFromPosition(2);
	l.Display();

	cout << "---------" << endl;

	cout << "DoubleLinkedList" << endl;

	cout << "---------" << endl;

	DoubleLinkedList d;

	d.InsertAtBeginning(10);
	d.InsertAtBeginning(0);
	d.InsertAtEnd(20);
	d.InsertAtPosition(15, 3);
	d.InsertAtEnd(30);
	d.Display();

	cout << "---------" << endl;

	d.DeleteFromBeginning();
	d.Display();

	cout << "---------" << endl;

	d.DeleteFromEnd();
	d.Display();

	cout << "---------" << endl;

	d.DeleteFromPosition(2);
	d.Display();

	return 0;
}