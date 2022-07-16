class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int numberOfLaddersUsed = 0;
        int buildingsCovered = 0;
        
        // Height Difference where ladders are used.
        priority_queue<int,vector<int>,greater<int>> heightDiffQueue;
        
        for(int idx=0; idx<heights.size()-1; idx++)
        {
            int heightDiff = heights[idx+1]-heights[idx];  
            if(heightDiff <= 0)
                continue;
            heightDiffQueue.push(heightDiff);


            if(heightDiffQueue.size() > ladders)
            {
                int bricksRequired = heightDiffQueue.top();
                bricks -= bricksRequired;
                heightDiffQueue.pop();
            }
            if(bricks < 0)
                return idx;
        }
        
        return heights.size()-1;
        
    }
};