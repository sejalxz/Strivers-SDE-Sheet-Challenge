#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next;

	Node() : val(-1), next(NULL) {}
	Node(int x) : val(x),next(NULL){}
};

class Queue
{

private:
	int size;
	Node *front;
	Node *rear;

public:
	Queue(){
		front = NULL;
		rear = NULL;
		size = 0;
	}
	~Queue(){
		Node *current = front;
		while(current)
		{
			Node *temp = current;
			current = current->next;
			delete temp;
		}
		delete front,rear,current;
	}

	void enqueue(int x);
	int dequeue();
	void display();
	int top();
	bool isFull();
	bool isEmpty();
	
};

bool Queue :: isEmpty(){
	if(!front){
		cout<<"Queue Underflow\n";
		return true;
	}
	return false;
}

bool Queue :: isFull(){
	Node *temp = new Node;
	if(!temp){
		cout<<"Queue Overflow\n";
		return true;
	}
	return false;
}

void Queue :: enqueue(int x){
	if(isFull())
		return;

	Node *newNode = new Node(x);
	if(front == NULL){
		front = rear = newNode;
	}
	else{
		rear->next = newNode;
		rear = rear->next;
	}
}

int Queue :: dequeue(){
	if(isEmpty())
		return -1;

	int x = front->val;
	Node *temp = front;
	front = front->next;
	delete temp;
	return x;
}

int Queue :: top()
{
	if(isEmpty())
		return -1;
	return front->val;
}

void Queue :: display(){
	cout<<"Queue :";
	Node *current = front;
	while(current)
	{
		cout<<"  "<<current->val;
		current = current->next;
	}
	cout<<endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 


    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }

    q.display();

    q.enqueue(20);
    q.enqueue(26);
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }

    cout<<"Queue front : "<<q.top()<<endl;
    q.display();

    q.dequeue();
    q.dequeue();

    cout<<"Queue Empty : "<<q.isEmpty()<<endl;
	
	
	return 0;
}
