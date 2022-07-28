class Solution {
    int rows,cols;
    string currentIsland;
    unordered_set<string> uniqueIslands;
    
    bool isValid(int row,int col)
    {
        return row>=0 and row<rows and col>=0 and col<cols;
    }
    
    void dfs(int row,int col,char dir,vector<vector<int>>& grid)
    {
        if(!isValid(row,col) or grid[row][col]==0)
            return;
        grid[row][col] = 0;
        currentIsland.push_back(dir);
        
        dfs(row+1,col,'D',grid);
        dfs(row-1,col,'U',grid);
        dfs(row,col+1,'R',grid);
        dfs(row,col-1,'L',grid);
        
        currentIsland.push_back('0');
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        for(int row = 0; row<rows; row++)
        {
            for(int col = 0; col<cols; col++)
            {
                currentIsland = "";
                if(grid[row][col])
                {
                    dfs(row,col,'0',grid);
                    uniqueIslands.insert(currentIsland);
                }
            }
        }
        return uniqueIslands.size();
    }
};