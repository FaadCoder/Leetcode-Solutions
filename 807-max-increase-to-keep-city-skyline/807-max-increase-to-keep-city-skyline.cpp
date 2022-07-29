class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax,colMax;
        for(auto row:grid)
            rowMax.push_back(*max_element(begin(row),end(row)));
        
        for(int col = 0; col<grid[0].size(); col++)
        {
            int mx = 0;
            for(int row =0 ; row<grid.size(); row++)
                mx = max(mx,grid[row][col]);
            colMax.push_back(mx);
        }
        
        int maxIncrease = 0;
        
        for(int row = 0; row<grid.size(); row++)
        {
            for(int col = 0; col<grid[0].size(); col++)
                maxIncrease += min(rowMax[row],colMax[col])-grid[row][col];
        }
        return maxIncrease;
    }
};