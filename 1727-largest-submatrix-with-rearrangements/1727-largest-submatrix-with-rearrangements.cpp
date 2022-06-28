class Solution
{
    int rows = 0,cols = 0;
    
    void calculateConsecutiveOnesInColumns(vector<vector < int>> &matrix)
    {
        for (int rowIdx = 1; rowIdx < rows; rowIdx++)
        {
            for (int colIdx = 0; colIdx < cols; colIdx++) 
            {
                if(matrix[rowIdx][colIdx] == 1)
                {
                    matrix[rowIdx][colIdx] = matrix[rowIdx-1][colIdx] + 1;
                }
            }
        }
    }
    
    int getMaxArea(vector<vector < int>> &matrix)
    {
        int maxArea = 0;
        for(int rowIdx = 0; rowIdx < rows; rowIdx++)
        {
            sort(matrix[rowIdx].begin(),matrix[rowIdx].end());
            for(int colIdx = 0; colIdx < cols; colIdx++)
            {
                maxArea = max(maxArea,matrix[rowIdx][colIdx] * (cols-colIdx));
            }
        }
        
        return maxArea;
    }
    
    public:
        int largestSubmatrix(vector<vector < int>> &matrix)
        {
            rows = matrix.size();
            cols = matrix[0].size();
            calculateConsecutiveOnesInColumns(matrix);
            return getMaxArea(matrix);
        }
};