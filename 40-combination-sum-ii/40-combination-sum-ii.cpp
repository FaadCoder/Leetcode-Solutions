class Solution {
    
    vector<vector<int>> combinations;
    void populateAllCombinations(vector<int>& candidates,int target,int idx,vector<int> &temp)
    {
        if(target<0)
            return;
        if(target == 0)
        {
            combinations.push_back(temp);
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx and candidates[i-1]==candidates[i])
                continue;
            temp.push_back(candidates[i]);
            populateAllCombinations(candidates,target-candidates[i],i+1,temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        populateAllCombinations(candidates,target,0,temp);
            
        return combinations;
    }
};