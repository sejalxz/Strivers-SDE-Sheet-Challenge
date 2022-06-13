class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>nge(n);
        stack<int>st;    
        for(int i = 2*n-1 ; i >=0 ; i--)
        {
            while(!st.empty() && st.top() <= arr[i%n])
                st.pop();
            
            
            if(!st.empty())
                nge[i%n] = st.top();
            else
                nge[i%n] = -1;
                        
            st.push(arr[i%n]);

        }
        return nge;
    }
};
