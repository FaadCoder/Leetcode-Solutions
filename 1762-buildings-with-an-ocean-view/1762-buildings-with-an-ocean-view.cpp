class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        int numberOfBuildings = heights.size();
        vector<int> buildings;
        
        stack<int> monoStack;
        
        for(int idx = heights.size()-1; idx>=0; idx--)
        {
            if(monoStack.empty() or heights[idx]>monoStack.top())
            {
                buildings.push_back(idx);
                monoStack.push(heights[idx]);
            }
        }
        reverse(begin(buildings),end(buildings));
        return buildings;
    }
};