class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = size(matrix);
        int cols = size(matrix[0]);
        
        for(int row = 1; row < rows; row++)
        {
            for(int col = 1; col < cols; col++)
            {
                if(matrix[row][col] != matrix[row-1][col-1])
                    return false;
            }
        }
        
        return true;
    }
};