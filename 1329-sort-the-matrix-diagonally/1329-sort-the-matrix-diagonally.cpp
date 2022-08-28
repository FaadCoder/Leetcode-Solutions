class Solution {
    int rows, cols;
    
    void countSort(vector<int> &temp)
    {
        int count[101] = {0};
        
        for(int num : temp)
            count[num] += 1;
        
        int idx = 0;
        
        for(int num = 1; num <= 100; num++)
        {
            while(count[num] > 0 )
            {
                temp[idx++] = num;
                count[num] -= 1;
            }
        }
    }
    
    void sortDiagonal(int row, int col, vector<vector<int>> &mat)
    {
        int startRow = row;
        int startCol = col;
        vector<int> temp;
      
        while(row<rows and col<cols)
            temp.push_back(mat[row++][col++]);
        
        countSort(temp);
        
        for(int num : temp)
        {
            mat[startRow][startCol] = num;
            startRow += 1;
            startCol += 1;
        }
    }
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        
        for(int row = 0; row < rows; row++)
           for(int col = 0; col < cols; col++)
                sortDiagonal(row, col, mat);
        
        return mat;
    }
};