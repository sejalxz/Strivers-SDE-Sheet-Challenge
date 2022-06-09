//Without pointers

#include <queue>
class Stack {      
   private:
        queue<int> Q1;
        queue<int> Q2;
    
   public:
    Stack() {
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return Q1.size();
    }

    bool isEmpty() {
        return Q1.empty();
    }

    void push(int x) {
        Q2.push(x);
        while(!Q1.empty())
        {
            Q2.push(Q1.front());
            Q1.pop();
        }
        Q1.swap(Q2);
    }

    int pop() {
        if(Q1.empty())
            return -1;
        
        int x = Q1.front();
        Q1.pop();
        return x;
    }

    int top() {
        if(Q1.empty())
            return -1;
        
        return Q1.front();
    }
};

// With pointers 

#include <queue>
class Stack {      
   private:
        queue<int> *Q1,*Q2;
    
   public:
    Stack() {
        Q1 = new queue<int>();
        Q2 = new queue<int>();
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return Q1->size();
    }

    bool isEmpty() {
        return Q1->empty();
    }

    void push(int x) {
        Q2->push(x);
        while(!Q1->empty())
        {
            Q2->push(Q1->front());
            Q1->pop();
        }
        queue<int> *temp = Q1;  
        Q1 = Q2;
        Q2 = temp;
    }

    int pop() {
        if(Q1->empty())
            return -1;
        
        int x = Q1->front();
        Q1->pop();
        return x;
    }

    int top() {
        if(Q1->empty())
            return -1;
        
        return Q1->front();
    }
};
