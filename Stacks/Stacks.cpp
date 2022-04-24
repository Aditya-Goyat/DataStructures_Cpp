#include <iostream>

using namespace std;

class Node {
private:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}
	Node() {
		value = NULL;
		next = nullptr;
	}

	friend class Stack;
};

class Stack {
private:
	Node* top;

public:

	Stack() {
		top = nullptr;
	}

	void Push(int value) {
		if (top == nullptr) {
			top = new Node(value);
		}
		else {
			Node* temp = new Node(value);
			temp->next = top;
			top = temp;
		}
	}

	int Pop() {
		int value = -1;

		if (top == nullptr) {
			cout << "The stack is empty" << endl;
			return value;
		}
		else {

			if (top->next == nullptr) {
				value = top->value;
				free(top);
				return value;
			}
			else {
				Node* temp = top;
				top = top->next;
				value = temp->value;
				free(temp);
				return value;
			}
		}
	}

	void Display() {
		if (top == nullptr) {
			cout << "The stack is empty" << endl;
			return;
		}
		else {
			Node* currentNode = top;
			
			while (currentNode != nullptr) {
				cout << currentNode->value << endl;
				currentNode = currentNode->next;
			}
		}
	}

	int Peek() {
		if (top == nullptr) {
			cout << "The stack is empty" << endl;
			return -1;
		}
		else {
			return top->value;
		}
	}

	bool isEmpty() {
		return top == nullptr;
	}
};

int main() {

	Stack s;

	s.Push(20);
	s.Push(10);
	s.Push(0);

	s.Display();

	cout << "----------" << endl;

	cout << "Item popped is: " << s.Pop() << endl;
 
	cout << "----------" << endl;

	s.Display();

	cout << "----------" << endl;

	cout << "The top element is: " << s.Peek() << endl;

	return 0;
}