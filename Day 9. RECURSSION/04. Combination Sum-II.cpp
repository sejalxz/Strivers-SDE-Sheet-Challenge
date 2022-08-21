// 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>combinations;
        vector<int>currentComb;
        sort(candidates.begin(), candidates.end());
        generateAllCombinations(0, target, currentComb, combinations, candidates);
        return combinations; 
    }
private:
    private:
    void generateAllCombinations(int currentIndex, int target, vector<int> &currentComb, vector<vector<int>> &combinations, vector<int> &candidates)
    {
        if(target < 0 )
            return;
        
        else if(target == 0)
        {
            combinations.push_back(currentComb);
            return;
        }
        
        else
        {
            for(int i = currentIndex ; i < candidates.size() ; i++)
            {
                if(i != currentIndex && candidates[i] == candidates[i-1]) 
                    continue;
                currentComb.push_back(candidates[i]);
                generateAllCombinations(i+1, target-candidates[i], currentComb, combinations, candidates);
                currentComb.pop_back();
            }
        }
        
        return;        
    }
};

//M-II
class Solution {
public:
    
    //TC : O(2^T * k)
    //SC : O(k * x)
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>currentSubset;
        sort(candidates.begin(), candidates.end());
        generateCombinations(candidates, 0,target,currentSubset,result);
        return result;
    }
    
private:
    void generateCombinations(vector<int>& candidates, int currentIndex, int target, vector<int>&currentSubset, vector<vector<int>>& result)
    {
        if(target < 0 )
            return;
        
        else if(currentIndex >= candidates.size())
        {   
            if(target == 0)
            {
                result.push_back(currentSubset);
            }
            return;
        }
                
        int count = 0;        
        int currentVal = candidates[currentIndex];
        
        for(int i = currentIndex ; i < candidates.size() ;i++)
        {
            if(candidates[i] == currentVal)
                count++;
            else
                break;
        }
        
        for(int i = 1 ; i <= count ; i++)
        {
            for(int j = 1 ; j <= i ; j++)
            {
                    currentSubset.push_back(currentVal);               
            }
            
            generateCombinations(candidates, currentIndex+count, target-(i*currentVal), currentSubset,result);
            
            for(int j = 1 ; j <= i ; j++)
            {
                currentSubset.pop_back();
            }
        }
        
        generateCombinations(candidates, currentIndex+count, target, currentSubset,result);
    }
};
