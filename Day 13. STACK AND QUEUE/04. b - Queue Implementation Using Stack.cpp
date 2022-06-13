#Push(x) TC -> O(1)
#include <stack>
class Queue {
    private:
    stack<int>*ip,*op;
    public:
    Queue() {
        ip = new stack<int>();
        op = new stack<int>();
    }

    void enQueue(int val) {
        ip->push(val);
        }

    int deQueue() {
        if(isEmpty())
            return -1;
        int x;
        if(!op->empty()){
            x = op->top();
        }
        else
        {
            while(!ip->empty())
            {
                op->push(ip->top());
                ip->pop();
            }
            x = op->top();
        }
        op->pop();     
        
        return x;
    }

    int peek() {
        if(isEmpty())
            return -1;
        
        if(!op->empty())
            return op->top();
        
        while(!ip->empty())
        {
            op->push(ip->top());
            ip->pop();
        }
        return op->top();
    }

    bool isEmpty() {
        return ip->empty() && op->empty();
    }
};
