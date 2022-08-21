class Solution
{
    //TC : O(2^N)
    //SC : O(2^N)
    
public:
    vector<int> subsetSums(vector<int> nums, int N)
    {
        vector<int>result;
        generateSubsetSum(nums,0,0,result);
        return result;
    }
    
private:
    void generateSubsetSum(vector<int> &nums, int currentIndex, int sum, vector<int>&result)
    {
        if(currentIndex >= nums.size()){
            result.push_back(sum);
            return;
        }
        generateSubsetSum(nums,currentIndex+1, sum + nums[currentIndex],result);
        
        generateSubsetSum(nums,currentIndex+1, sum,result);
    }
    
};

//TC : O(2^N * k ) + O(2^N * log(2^N) for sorting.
//SC : O(2^N)

#include <algorithm>
void generateSubsetSum(vector<int> &nums, int currentIndex, vector<int>&currentSubset, vector<int>&result)
{
    if(currentIndex >= nums.size()){
        int sum = accumulate(currentSubset.begin(), currentSubset.end(),0);
        result.push_back(sum);
        return;
    }
    currentSubset.push_back(nums[currentIndex]);
    generateSubsetSum(nums,currentIndex+1, currentSubset,result);
    currentSubset.pop_back();
    generateSubsetSum(nums,currentIndex+1, currentSubset,result);
}
vector<int> subsetSum(vector<int> &nums)
{
    vector<int>result, currentSubset;
    generateSubsetSum(nums, 0, currentSubset, result);
    sort(result.begin(), result.end());
    return result;
}
