class Solution
{
    public:
        bool removeOnes(vector<vector < int>> &grid)
        {
            int rows = grid.size();
            int cols = grid[0].size();
            for (int row = 0; row < rows; row++)
            {
                bool isSame = true;
                bool isOpposite = true;
                for (int col = 0; col < cols; col++)
                {
                    isSame = isSame and(grid[0][col] == grid[row][col]);
                    isOpposite = isOpposite and(grid[0][col] != grid[row][col]);
                }
                if (!isSame and!isOpposite)
                    return false;
            }
            return true;
        }
};