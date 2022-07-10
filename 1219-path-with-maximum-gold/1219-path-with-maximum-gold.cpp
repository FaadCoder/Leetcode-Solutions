class Solution {
    int rows,cols;
    
    bool isValid(int row,int col)
    {
        return (row>=0 and row<rows and col>=0 and col<cols);
    }
    
    int getMaxGold(vector<vector<int>>& grid,int row,int col)
    {
        if(!isValid(row,col) or grid[row][col]==0)
            return 0;
        
        int currentGold = grid[row][col];
        grid[row][col] = 0;
        int res = currentGold + max({
            getMaxGold(grid,row+1,col),
            getMaxGold(grid,row-1,col),
            getMaxGold(grid,row,col+1),
            getMaxGold(grid,row,col-1),
        });
        grid[row][col] = currentGold;
        return res;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        for(int row = 0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                maxGold = max(maxGold,getMaxGold(grid,row,col));
            }
        }
        
        return maxGold;
    }
};