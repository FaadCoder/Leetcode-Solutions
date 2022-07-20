class Solution {
    int rows,cols;
    
    void takeTranspose(vector<vector<int>> &matrix)
    {
        for(int row=0;row<rows;row++)
        {
            for(int col=row;col<cols;col++)
            {
                swap(matrix[row][col],matrix[col][row]);
            }
        }
    }
    
    void reverseEachRow(vector<vector<int>> &matrix)
    {
        for(vector<int> &row:matrix)
            reverse(row.begin(),row.end());
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        takeTranspose(matrix);
        reverseEachRow(matrix);
    }
};