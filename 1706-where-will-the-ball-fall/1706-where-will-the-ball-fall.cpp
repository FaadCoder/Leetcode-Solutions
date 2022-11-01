class Solution {
    int rows, cols;
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        vector<int> result(cols);
        
        for(int col = 0; col<cols; col++)
        {
            int currentCol = col, currentRow = 0;
            
            while(currentRow < rows)
            {
                int currentValue = grid[currentRow][currentCol];
                
                if(currentValue == 1 and (currentCol + 1) < cols and currentValue == grid[currentRow][currentCol + 1] )
                    currentRow++, currentCol++;
                else if(currentValue == -1 and (currentCol - 1) >= 0 and currentValue == grid[currentRow][currentCol - 1] )
                    currentRow++, currentCol--;
                else
                    break;
            }
            
            result[col] = (currentRow >= rows) ? currentCol : -1;
        }
        
        return result;
    }
};