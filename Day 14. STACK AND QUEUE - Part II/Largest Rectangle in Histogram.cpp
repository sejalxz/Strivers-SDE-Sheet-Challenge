#BRUTE FORCE --> TC : O(N^2)  SC : O(1)

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
