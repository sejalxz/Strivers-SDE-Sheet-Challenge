// Queue Implementation Using Array
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?topList=striver-sde-sheet-problems&leftPanelTab=0

class Queue {
private:
    int front1,rear;
    int *arr;
    int count;
public:
    Queue() {
        front1 = 0;
        rear = -1;
        arr = new int[5001];
        count = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(count == 0)
            return true;
        return false;
    }

    void enqueue(int data) {
        if(isFull())
            return;
        rear++;
        arr[rear] = data;
        count++;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        int x = arr[front1];
        front1++;
        count--;
        return x;
    }

    int front() {
        if(count == 0)
            return -1;
        return arr[front1];
    }
    
    bool isFull()
    {
        if(count == 5001)
            return true;
        return false;
    }
};
