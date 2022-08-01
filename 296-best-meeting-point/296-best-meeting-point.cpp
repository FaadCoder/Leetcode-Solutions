class Solution {
    int rows,cols;
    
    vector<int> getXCoordinates(vector<vector<int>>& grid)
    {
        vector<int> xCoord;
        
        for(int row = 0; row<rows; row++)
        {
            for(int col = 0; col<cols; col++)
            {
                if(grid[row][col]==1)
                    xCoord.push_back(row);
            }
        }
        
        return xCoord;
    }
    
    
    vector<int> getYCoordinates(vector<vector<int>>& grid)
    {
        vector<int> yCoord;
        
        for(int col = 0; col<cols; col++)
        {
            for(int row = 0; row<rows; row++)
            {
                if(grid[row][col]==1)
                    yCoord.push_back(col);
            }
        }
        
        return yCoord;
    }
    
    int minimumTravelDistance(int xBest,int yBest, vector<int> &xCoord,vector<int> &yCoord)
    {
        int dis = 0;
        
        for(int idx = 0; idx<xCoord.size(); idx++)
        {
            dis += abs(xBest - xCoord[idx]) + abs(yBest - yCoord[idx]);
        }
        
        return dis;
    }
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        //Step 1 : Get x coordinates
        vector<int> xCoord = getXCoordinates(grid);
        
        // Step 2: Get y coordinates
        vector<int> yCoord = getYCoordinates(grid);
        
        // Step 3: Calculate Best Meeting Point (Median of x and y coordinates)
        int xBest = xCoord[xCoord.size()/2];
        int yBest = yCoord[yCoord.size()/2];
        
        // Step 4: Calculate the minimum travel distance from Best Meeting Point
        return minimumTravelDistance(xBest,yBest,xCoord,yCoord);
    }
};