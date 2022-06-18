// Brute Force
// TC : O(N*N*N)
// SC : O(N)

//Refer Sliding Window Brute Force

//Better 
// TC : O(N*N)
// SC : O(N)

#include <deque>
vector<int> maxMinWindow(vector<int> nums, int n) {
    vector<int>maxAns;
    for(int k = 1 ; k <= n ;k++)
    {
        vector<int>ans;
        deque<int>dq;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] >= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1)
                ans.push_back(nums[dq.front()]); 
        }
        maxAns.push_back(*max_element(ans.begin(), ans.end()));
    }
        
        return maxAns;
}

//optimal
//TC : O(N)
//SC : O(N)

#include <stack>
vector<int> maxMinWindow(vector<int> arr, int n) {
        vector<int>left(n,-1); // Initialise with -1
        vector<int>right(n,n); // Initialise with n 
        stack<int>st;
        
        for(int i = 0 ; i < n ; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if(!st.empty())
                left[i] = st.top();
                
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if(!st.empty())
                right[i] = st.top();
                
            st.push(i);
        }
        
        vector<int>ans(n, INT_MIN);
        
        for(int i = 0 ; i < n ; i++)
        {
            int len = right[i] - left[i] - 1;
            
            ans[len-1] = max(ans[len-1], arr[i]);
        }
        
        for(int i = n-2 ; i >= 0 ; i--)
        {
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        return ans;
}
