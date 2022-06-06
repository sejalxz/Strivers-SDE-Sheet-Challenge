// Queue Implementation Using Array
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
	int capacity;
	int front;
	int rear;
	int *Q;

public:
	Queue(int capacity_)
	{
		capacity = capacity_;
		front = -1;
		rear = -1;
		Q = new int[capacity];
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
	if(front == rear){
		return true;
	}
	return false;
}

bool Queue :: isFull(){
	if(capacity-1 == rear){
		return true;
	}
	return false;
}

void Queue :: display(){
	cout<<"Queue :";
	for(int i = front+1 ; i <= rear ; i++)
	{
		cout<<"  "<<Q[i];
	}
	cout<<endl;
}

int Queue :: top(){
	if(isEmpty()){
		cout<<"Queue Underflow\n";
		return -1;
	}
	return Q[front+1];
}

void Queue :: enqueue(int x){
	if(isFull()){		
		cout<<"Queue Overflow\n";
		return;
	}
	rear++;
	Q[rear] = x;
}

int Queue :: dequeue(){
	if(isEmpty()){
		cout<<"Queue Underflow\n";
		return -1;
	}
	front++;
	return Q[front];
	
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int A[] = {1, 3, 5, 7, 9};

 	int sizeA = sizeof(A)/sizeof(A[0]);
    Queue q(sizeA);
 
    // Enqueue
    for (int i=0; i<sizeA; i++){
        q.enqueue(A[i]);
    }
     
    q.enqueue(11);

    //Full
    (q.isFull()) ? cout<<"Queue is Full"<<endl : cout<<"Queue is not Full"<<endl;

    // Display
    q.display();
 
 	q.dequeue();
 	q.dequeue();

 	cout<<"Queue front : "<<q.top()<<endl;


 	q.dequeue();
 	q.dequeue();
 	q.dequeue();


    // Overflow
    cout<<"Enqueue(10) : ";q.enqueue(10);

    //Empty
    (q.isEmpty()) ? cout<<"Queue is Empty"<<endl : cout<<"Queue is not Empty"<<endl;

    	
	return 0;
}
