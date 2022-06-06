#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node() : val(0), next(nullptr){}
	Node(int val) : val(val), next(nullptr){}
};


class Stack
{
private:
	Node *top;

public:
	Stack(){
		top = NULL;
	}
	~Stack(){
		Node *temp;
		while(top)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
		delete top;
	}

	bool isEmpty();
	bool isFull();
	void push(int x);
	void display();
	int pop();
	int stackTop();
	
};

int Stack :: stackTop()
{
	if(isEmpty())
		return -1;

	return top->val;
}

int Stack :: pop(){
	if(isEmpty())
		return -1;

	int x = top->val;
	Node *temp = top;
	top = top->next;
	delete temp;
	return x;
}

bool Stack :: isEmpty(){
	if(!top)
		return true;
	return false;
}

bool Stack :: isFull(){
	Node *temp = new Node();
	if(!temp)
		return true;
	return false;
}

void Stack :: push(int x){
	if(isFull())	
		return;

	Node *newNode = new Node(x);
	newNode->next = top;
	top = newNode;
}

void Stack :: display()
{
	if(isEmpty())
	{
		cout<<"Stack is Empty"<<endl;
		return;
	}
	cout<<"Stack :";
	Node* current = top;
	while (current)
	{
		cout << "  "<<current -> val ;
		current = current -> next;
	}
	cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int A[] = {1, 3, 5, 7, 9,10,14,18};

	Stack stk;

	// Populate stack with array elements
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
		stk.push(A[i]);
	}

	// Display stack;
	stk.display();

	cout << "Stack full: " << stk.isFull() << endl;

	// Top element
	cout << "Top element: " << stk.stackTop() << endl;

	// Pop out elements from stack
	cout << "Popped out elements: " << flush;
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
		cout << stk.pop() << ", " << flush;
	}
	cout << endl;
	stk.pop();

	cout << stk.isEmpty() << endl;
	
	return 0;
}
