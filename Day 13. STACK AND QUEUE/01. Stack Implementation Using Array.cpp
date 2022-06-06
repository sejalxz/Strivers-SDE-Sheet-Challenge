// Stack Implementation Using Array
// https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?topList=striver-sde-sheet-problems&leftPanelTab=0

// Stack class.
class Stack {

private:
    int *st;
    int capacity;
    int stackTop;
public:
    
    Stack(int capacity_) {
        capacity = capacity_;
        stackTop = -1;
        st = new int[capacity];
    }

    void push(int num) {
        if(isFull())
            return;
        st[++stackTop] = num;
        return;
    }

    int pop() {
        if(isEmpty())
            return -1;
        int x = st[stackTop];
        stackTop--;
        return x;
    }
    
    int top() {
        if(isEmpty())
            return -1;
        return st[stackTop];
    }
    
    int isEmpty() {
        return (stackTop == -1) ? 1 : 0;
    }
    
    int isFull() {
        return (stackTop == capacity - 1) ? 1 : 0;
    }
    
};
