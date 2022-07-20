//BRUTE FORCE

    //TC : O(N^2)
    //SC : O(1)

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int>span(n,1);
       
       for(int i = 1 ; i < n ; i++)
       {
           span[i] = 1;
           for(int j = i-1 ; j >= 0 && (price[j] < price[i]) ; j--){
               span[i]++;
           }
       }
       
       return span;
    }
};


//OPTIMAL 
// When array of stock price is given
//TC : O(N)
//SC : O(N)
class Solution
{
    public:
    
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int>span(n);
       stack<int>st;
       st.push(0);
       span[0] = 1;
       for(int i = 1 ; i < n ; i++)
       {
            while(!st.empty() && (price[st.top()] <= price[i]))
                st.pop();
                
            span[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
       }
       
       return span;
    }
};

//optimal
//leetcode 
// method - II

class StockSpanner {
private:
    stack<pair<int,int>>* st; // < price, span >
    
    //TC : O(N)
    //SC : O(N)
    
public:
    StockSpanner() {
        st = new stack<pair<int,int>>();
    }
    
    int next(int price) {
        
        int span = 1;
        
        while(!st->empty() && (st->top().first <= price)){
            span += st->top().second;
            st->pop();
        }
        st->push({price,span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
