class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = size(matrix);
        int cols = size(matrix[0]);
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(row == 0 or col == 0)
                    continue;
                
                if(matrix[row][col] != matrix[row-1][col-1])
                    return false;
            }
        }
        
        return true;
    }
};