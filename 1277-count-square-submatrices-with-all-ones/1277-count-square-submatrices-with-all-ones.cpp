class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int squaresEndingAtCurrentCell[rows][cols];
       
        int squares = 0;
        
        for(int row=0;row<rows;row++)
        {
            for(int col = 0; col<cols;col++)
            {
                if(row==0 and col==0)
                {
                    squaresEndingAtCurrentCell[row][col] = matrix[row][col];
                }
                else if(row==0)
                {
                    squaresEndingAtCurrentCell[row][col] = matrix[row][col];
                }
                else if(col==0)
                {
                    squaresEndingAtCurrentCell[row][col] = matrix[row][col];   
                }
                else
                {
                    squaresEndingAtCurrentCell[row][col] = (matrix[row][col]==0) ? 0 :
                    1+min({squaresEndingAtCurrentCell[row-1][col],squaresEndingAtCurrentCell[row][col-1],
                          squaresEndingAtCurrentCell[row-1][col-1]});
                }
                squares+=squaresEndingAtCurrentCell[row][col];
            }
            
        }
        return squares;
    }
};