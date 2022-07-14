// Brute Force
// TC : O(1)
// SC : O(2N)
//Using Pointers

class MinStack {
private:
    stack < pair < int, int >> *st;
public:
    MinStack() {
        st = new stack < pair < int, int >>();
    }
    
    void push(int val) {
        if(st->empty()){
            st->push({val,val});
            return;
        }          
        int minVal = min(val,st->top().second);
        st->push({val,minVal});
    }
    
    void pop() {
        if(st->empty())
            return;
        st->pop();
    }
    
    int top() {
        if(st->empty())
            return -1;
        return st->top().first;
    }
    
    int getMin() {
        return st->top().second;
    }
    
};

