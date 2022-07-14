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


// OPTIMAL
// TC : O(1)
// SC : O(N)

class MinStack {
private:
    stack<long long> st;
    long long minVal;
public:
    MinStack() {
        minVal = INT_MAX;
        while(!st.empty())
        {
            st.pop();
        }
    }
    
    void push(int val) {
        if(st.empty()) {
              minVal = val;
              st.push((long long)val);
        } 
        else {
            if(val < minVal){
                st.push(2 * (long long)val - minVal);
                minVal = val;
            } 
            else{
                st.push(val);
            }
        }
  }
    
    void pop() {
        if(st.empty())
            return;
        
        if(st.top() < minVal)
        {
            minVal = 2*minVal - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        
        if(st.top() < minVal){
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return minVal;
    }
};


