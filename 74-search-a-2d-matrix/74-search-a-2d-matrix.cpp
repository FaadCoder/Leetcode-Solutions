class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int m=(int)matrix.size();
        int n=(int)matrix[0].size();
        int i,j;
        i=0;
        j=n-1;
        
        while(i<m and j>=0)
        {
            if(target==matrix[i][j])
                return true;
            else if(target>matrix[i][j])
            {
                i++;
            }
            else
                j--;
        }
        return false;
    }
};