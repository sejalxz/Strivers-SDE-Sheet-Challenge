//Negative Elements

void generateCombinations(vector<int>& nums, int currentIndex, int target, int currentSum,vector<int>& currentSubset, vector<vector<int>>& result)
{
    
    if(currentIndex >= nums.size())
    {
        if(target == currentSum)
    {
        result.push_back(currentSubset);
        return;
    }
        return;
    }
       
    
    int currentVal = nums[currentIndex];
    //Consider call
    currentSubset.push_back(currentVal);
    generateCombinations(nums, currentIndex+1, target,currentSum+currentVal,currentSubset, result);
    
    currentSubset.pop_back();
    generateCombinations(nums, currentIndex+1, target,currentSum,currentSubset, result);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> nums, int n, int target)
{
    vector<vector<int>>result;
    vector<int>currentSubset;
    generateCombinations(nums,0,target,0,currentSubset, result);
    return result;
}


//LeetCode 

class Solution {
    //TC : O(2^T * k)
    //SC : O(k*x)
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>currentSubset;
        generateCombinations(candidates, 0, target, currentSubset, result);
        return result;
    }
    
    void generateCombinations(vector<int>& candidates, int currentIndex, int target, vector<int>&currentSubset, vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(currentSubset);
            return;
        }
        
        if(currentIndex >= candidates.size())
        {
            return;
        }
        
        int currentVal = candidates[currentIndex];
        
        if(target >= currentVal)
        {
            currentSubset.push_back(currentVal);
            generateCombinations(candidates, currentIndex, target-currentVal, currentSubset,result);
            currentSubset.pop_back();
        }
        generateCombinations(candidates, currentIndex+1, target, currentSubset,result);
    }
};
