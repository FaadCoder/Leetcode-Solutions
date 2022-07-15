class Solution
{
    int rows, cols;
    vector<vector < int>> dirs = {
		{ 1,
            0 },
        { 0,
            1 },
        { -1,
            0 },
        { 0,
            -1 }
    };

    bool isValidCell(int row, int col)
    {
        return (row >= 0 and row < rows and col >= 0 and col < cols);
    }

    int getMaxArea(int row,int col,vector<vector < int>> &grid)
    {
        if(!isValidCell(row,col) or grid[row][col]==0)
            return 0;
        grid[row][col] = 0;
        int totalArea = 0;
        for(auto &dir:dirs)
            totalArea += getMaxArea(row+dir[0],col+dir[1],grid);
        
        return totalArea + 1;
    }
    
    public:
        int maxAreaOfIsland(vector<vector < int>> &grid)
        {
            rows = grid.size();
            cols = grid[0].size();
            int maxArea = 0;

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    if (grid[row][col] == 1)
                    {
                        maxArea = max(maxArea,getMaxArea(row,col,grid));
                    }
                }
            }

            return maxArea;
        }
};