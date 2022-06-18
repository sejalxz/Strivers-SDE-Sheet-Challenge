// BRUTE FORCE

class Solution {
public:
    //TC : O(N*K)
    //SC : O(1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>maxV;
        for(int i = 0 ; i <= nums.size()-k ; i++)
        {
            int maxi = INT_MIN;
            for(int j = i ; j <= i+k-1 ; j++)
            {
                maxi = max(maxi, nums[j]);
            }
            maxV.push_back(maxi);
        }
        return maxV;
    }
};

//OPTIMAL

class Solution {
public:
    //TC : O(N) + O(N) == O(N)
    //SC : O(K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
                
        }
        return ans;
    }
};
