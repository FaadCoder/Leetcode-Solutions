class Solution
{

    int getRowHits(vector<vector < char>> &grid, int row, int col)
    {
        int cols = grid[0].size();
        int rowHits = 0;
        while (col < cols and grid[row][col] != 'W')
        {
            rowHits += grid[row][col] == 'E';
            col++;
        }
        return rowHits;
    }

    int getColHits(vector<vector < char>> &grid, int row, int col)
    {
        int rows = grid.size();
        int colHits = 0;
        while (row < rows and grid[row][col] != 'W')
        {
            colHits += grid[row][col] == 'E';
            row++;
        }
        return colHits;
    }

    public:
        int maxKilledEnemies(vector<vector < char>> &grid)
        {
            int rows = grid.size();
            int cols = grid[0].size();

            int rowHits = 0;
            vector<int> colHits(cols, 0);
            int maxHits = 0;
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    if (col == 0 or grid[row][col - 1] == 'W')
                    {
                        rowHits = getRowHits(grid, row, col);
                    }

                    if (row == 0 or grid[row - 1][col] == 'W')
                    {
                        colHits[col] = getColHits(grid, row, col);
                    }

                    if (grid[row][col] == '0')
                        maxHits = max(rowHits + colHits[col], maxHits);
                }
            }
            return maxHits;
        }
};