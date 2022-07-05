class Solution {
   
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        vector<long long> prev(cols);
        for(int col=0;col<cols;col++)
            prev[col]=points[0][col];
        
        for(int row=1;row<rows;row++)
        {
            vector<long long> curr(cols,0);
            vector<long long> leftMaxDP(cols,0),rightMaxDP(cols,0);
            
            leftMaxDP[0] = prev[0];
            
            for(int col = 1; col<cols; col++)
                leftMaxDP[col] = max(leftMaxDP[col-1]-1,prev[col]);
            
            rightMaxDP[cols-1] = prev[cols-1];
            for(int col = cols-2;col>=0; col--)
                rightMaxDP[col] = max(rightMaxDP[col+1]-1,prev[col]);
            
            for(int col = 0; col<cols; col++)
                curr[col] = points[row][col] + max({curr[col], leftMaxDP[col],rightMaxDP[col]});
            
            prev = curr;
        }
        return *max_element(begin(prev),end(prev));
    }
};