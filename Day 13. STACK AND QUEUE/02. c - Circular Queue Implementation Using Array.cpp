#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
	int capacity;
	int front;
	int rear;
	int *Q;
	int size;

public:
	Queue(int capacity_)
	{
		capacity = capacity_;
		front = 0;
		rear = 0;
		Q = new int[capacity];
		size=0;
	}

	~Queue()
	{
		delete []Q;
	}

	void enqueue(int x);
	int dequeue();
	void display();
	int top();
	bool isFull();
	bool isEmpty();
};

bool Queue :: isEmpty(){
	if(rear == front){
		return true;
	}
	return false;
}

bool Queue :: isFull(){
	if((rear + 1)%capacity == front){
		return true;
	}
	return false;
}

void Queue::display() {
	cout<<"Queue :";
    int j = size, i = front + 1;
    while(j--)
    {
    	cout<<"  "<<Q[i%capacity];
    	i++;
    }
    cout<<endl;
}

int Queue :: top(){
	if(isEmpty())
		return -1;
	return Q[(front+1)%capacity];
}

void Queue :: enqueue(int x){
	if(isFull()){
		cout<<"Queue Overflow\n";
		return;
	}
	rear = (rear + 1)%capacity;
	Q[rear] = x;
	size++;
}

int Queue :: dequeue(){
	if(isEmpty()){
		cout<<"Queue Underflow\n";
		return -1;
	}

	front = (front+1)%capacity;
	size--;
	return Q[front];
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
 
    int A[] = {1, 3, 5, 7, 10};
 
    Queue q(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();

 
    // Overflow
    q.enqueue(20);
 
    // Dequeue
    for (int i=0; i<3; i++){
        q.dequeue();
    }

    q.enqueue(15);
    q.enqueue(19);

    q.display();
 
   
    q.dequeue();
    q.dequeue();

    cout<<"Queue front : "<<q.top()<<endl;

    q.display();
 
    return 0;
}
