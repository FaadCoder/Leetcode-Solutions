class Solution {
    int rows,cols;
    
    int countElementsLessThanMid(int mid, vector<vector<int>> &matrix)
    {
        int count = 0;
        int col = cols-1;
        
        for(int row = 0; row<rows; row++)
        {
            while(col>=0 and matrix[row][col]>mid)
                col--;
            count += (col+1);
        }
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        rows = matrix.size();
        cols = matrix[0].size();
        
        int low = matrix[0].front();
        int high = matrix[rows-1].back();
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int count = countElementsLessThanMid(mid,matrix);
            if(count>=k)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};