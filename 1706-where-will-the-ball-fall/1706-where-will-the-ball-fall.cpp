class Solution
{
    int rows, cols;

    bool isValidRightMove(int currentRow, int currentCol, vector<vector < int>> &grid)
    {
        int currentValue = grid[currentRow][currentCol];
        return (currentValue == 1 and(currentCol + 1) < cols and currentValue == grid[currentRow][currentCol + 1]);
    }

    bool isValidLeftMove(int currentRow, int currentCol, vector<vector < int>> &grid)
    {
        int currentValue = grid[currentRow][currentCol];
        return (currentValue == -1 and(currentCol - 1) >= 0 and currentValue == grid[currentRow][currentCol - 1]);
    }

    void moveRight(int &row, int &col)
    {
        row += 1;
        col += 1;
    }

    void moveLeft(int &row, int &col)
    {
        row += 1;
        col -= 1;
    }

    public:
        vector<int> findBall(vector<vector < int>> &grid)
        {
            rows = grid.size();
            cols = grid[0].size();

            vector<int> result(cols);

            for (int col = 0; col < cols; col++)
            {
                int currentCol = col, currentRow = 0;

                while (currentRow < rows)
                {
                    if (isValidRightMove(currentRow, currentCol, grid))
                        moveRight(currentRow, currentCol);
                    else if (isValidLeftMove(currentRow, currentCol, grid))
                        moveLeft(currentRow, currentCol);
                    else
                        break;
                }

                result[col] = (currentRow >= rows) ? currentCol : -1;
            }

            return result;
        }
};