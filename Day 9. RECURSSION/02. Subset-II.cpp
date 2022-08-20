//BRUTE 

// Use set to store and generate all the subsets like Subset-I
//
// TC : O(2^N * k(log(x), 2^N for generating, k = average length of the subset log(x) inserting x sized vector into set
// SC : O(2^N * k) -> result vector + O(2^N * k) set

//OPTIMAL
class Solution {
  
    // TC : O(2^N)
    // SC : O(2^N * k)
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>currentSubset;
        sort(nums.begin(), nums.end());
        generateUniqueSubsets(nums, 0, currentSubset, result);
        return result;
    }
    
private:
    void generateUniqueSubsets(vector<int>& nums, int currentInd, vector<int>& currentSubset, vector<vector<int>>& result)
    {
        if(currentInd >= nums.size())
        {
            result.push_back(currentSubset);
            return;
        }
        
        int currentVal = nums[currentInd];
        int count = 0;
        
        for(int i = currentInd ; i < nums.size() ; i++)
        {
            if(nums[i] == currentVal)count++;
        }
        
        //Considering the elements
        
        for(int i = 1 ; i <= count ; i++){
            
            //Considering the duplicates elements
            for(int j = 1 ; j <= i ; j++)
            {
                currentSubset.push_back(currentVal);
            }
            
            generateUniqueSubsets(nums, currentInd + count, currentSubset, result);
            
            for(int j = 1 ; j <= i ; j++)
            {
                currentSubset.pop_back();
            }
            
        }
        
        //Not-Considering calls
        generateUniqueSubsets(nums, currentInd + count, currentSubset, result);
    }
};

// TC : O(2^N * k) : O(2^N) for generating and O(K) for inserting into result
// SC : O(2^N * k) , k = average length of each subset
void uniqueSubsets(vector<int> &nums, int currentIndex, vector<int>& currentSubset, vector<vector<int>>& result)
{
    result.push_back(currentSubset);
    for(int i = currentIndex ; i < nums.size() ; i++)
    {
        if(i != currentIndex && nums[i-1] == nums[i])
               continue;
        else{
            currentSubset.push_back(nums[i]);
            uniqueSubsets(nums, i+1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    return;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    vector<int>currentSubset;
    vector<vector<int>>result;
    sort(nums.begin(), nums.end());
    uniqueSubsets(nums, 0, currentSubset, result);
    return result;
}
