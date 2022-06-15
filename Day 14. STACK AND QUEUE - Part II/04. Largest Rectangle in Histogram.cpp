// BETTER APPROACH  --> TC : O(5N) = O(N)  SC : O(3N) = O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        int leftSmall[n], rightSmall[n];
        stack<int>st; 
        
        for(int i = 0 ; i < n ; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top()+1;
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();        
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                rightSmall[i] = n-1;
            else
                rightSmall[i] = st.top()-1;
            
            st.push(i);
        }
        
        for(int i = 0 ; i < n ; i++)
        {                               
            int area = (rightSmall[i]-leftSmall[i] + 1)*heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};

//BRUTE FORCE --> TC : O(N^2)  SC : O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0 ; i < n ; i++)
        {
            int rsmall = n-1, lsmall = 0;
            for(int r = i+1 ; r < n ; r++)
            {
                if(heights[r] < heights[i])
                {
                    rsmall = r-1;
                    break;
                }
            }
                    
            
            for(int l = i-1 ; l >=0 ; l--)
            {
                if(heights[l] < heights[i])
                {
                   
                    lsmall = l+1;
                    break;
                }
            }
                                  
            int area = (rsmall-lsmall+1)*heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
