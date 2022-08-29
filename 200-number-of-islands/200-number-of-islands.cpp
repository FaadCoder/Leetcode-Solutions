class Solution {
    int rows = 0, cols = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    
    int get1DCoordinate(int row, int col)
    {
        return (row * cols + col);
    }
        
    void markNeighboursVisited(int row, int col, vector<vector<char>>& grid)
    {
        if(row<0 or row>=rows or col<0 or col>=cols or grid[row][col]=='0')
            return;
         
        grid[row][col] = '0';
        
        for(auto [rowDir, colDir] : dirs)
            markNeighboursVisited(row + rowDir, col + colDir, grid);
    }
        
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == '1')
                {
                    islands += 1;
                    markNeighboursVisited(row, col, grid);
                }
            }
        }
        
        return islands;
    }
};