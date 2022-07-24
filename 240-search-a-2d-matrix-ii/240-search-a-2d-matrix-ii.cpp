class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0,col=cols-1;
        while(col>=0 and row<rows)
        {
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]>target)
                col--;
            else
                row++;
        }
        return false;
    }
};