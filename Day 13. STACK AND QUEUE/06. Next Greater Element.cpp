# Brute Force -> TC : O(N^2) SC : O(1)

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int>nge(n,-1);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[j] > arr[i])
            {
                nge[i] = arr[j];
                break;
            }
        }
    }
    return nge;

}

# Optimal TC : O(N) SC : O(N)  ONLY RIGHT SIDE NOT CIRCULAR.

#include <stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int>nge(n);
    stack<int>st;    
    for(int i = n-1 ; i >=0 ; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        
        if(!st.empty())
            nge[i] = st.top();
        else
            nge[i] = -1;
        st.push(arr[i]);
        
    }
    return nge;
}
