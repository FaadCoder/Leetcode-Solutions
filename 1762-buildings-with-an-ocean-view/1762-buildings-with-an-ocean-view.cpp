class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        int numberOfBuildings = heights.size();
        vector<int> buildings;
        
        int maxHeight = 0;
        
        for(int idx = heights.size()-1; idx>=0; idx--)
        {
            if(heights[idx]>maxHeight)
            {
                buildings.push_back(idx);
                maxHeight = heights[idx];
            }
        }
        reverse(begin(buildings),end(buildings));
        return buildings;
    }
};