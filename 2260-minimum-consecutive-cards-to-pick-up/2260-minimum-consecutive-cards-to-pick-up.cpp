class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        unordered_map<int,vector<int>> posMap;
        
        for(int idx=0; idx<cards.size(); idx++)
        {
            posMap[cards[idx]].push_back(idx);
        }
        
        int minDis = INT_MAX;
        
        for(auto keyValue : posMap)
        {
            vector<int> value = keyValue.second;
            for(int idx = 0; idx<value.size()-1; idx++)
            {
                minDis = min(minDis,value[idx+1] - value[idx] + 1);
            }
        }
        
        return minDis==INT_MAX?-1:minDis;
    }
};