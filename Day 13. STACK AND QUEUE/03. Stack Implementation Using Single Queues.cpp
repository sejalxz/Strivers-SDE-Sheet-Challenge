//With Pointers

#include <queue>
class Stack {      
   private:
        queue<int> *Q;
    
   public:
    Stack() {
        Q = new queue<int>();
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return Q->size();
    }

    bool isEmpty() {
        return Q->empty();
    }

    void push(int x) {
        Q->push(x);
        for(int i = 0 ; i < getSize()-1 ; i++)
        {
            Q->push(Q->front());
            Q->pop();
        }
    }

    int pop() {
        if(Q->empty())
            return -1;
        
        int x = Q->front();
        Q->pop();
        return x;
    }

    int top() {
        if(Q->empty())
            return -1;
        
        return Q->front();
    }
};

