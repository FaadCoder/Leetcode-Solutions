class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int prefix[rows][cols];
        memset(prefix,0,sizeof(prefix));
        
        for(int row=0;row<rows;row++)
        {
            for(int col=1;col<cols;col++)
            {
                matrix[row][col] += matrix[row][col-1];
            }
        }
        
        int totalSubmatrices = 0;
        
        for(int leftCol=0;leftCol<cols;leftCol++)
        {
            for(int rightCol=leftCol;rightCol<cols;rightCol++)
            {
                int sum = 0;
                unordered_map<int,int> sumHashMap;
                sumHashMap[0]=1;
                for(int row=0;row<rows;row++)
                {
                    sum += (matrix[row][rightCol]-(leftCol>0 ? matrix[row][leftCol-1]:0));
                    totalSubmatrices += sumHashMap[sum-target];
                    sumHashMap[sum]++;
                }
            }
        }
        
        
        return totalSubmatrices;
    }
};