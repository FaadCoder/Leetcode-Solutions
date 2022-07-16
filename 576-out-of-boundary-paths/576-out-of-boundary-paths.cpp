class Solution {
    const int MOD = 1e9+7;
    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int dp[51][51][51];
    
    bool isValid(int row,int col,int rows,int cols)
    {
        return (row>=0 and row<rows and col>=0 and col<cols);
    }
    
    int findPathsHelper(int m, int n, int maxMove, int r, int c) {
        if(r<0 or r>=m or c<0 or c>=n)
            return maxMove>=0;
        if(maxMove<0)
            return 0;
        if(dp[maxMove][r][c]!=-1)
            return dp[maxMove][r][c];
        
        int paths = 0;
        for(auto &dir:dirs)
        {
            paths = (paths % MOD + findPathsHelper(m,n,maxMove-1,r+dir.first,c+dir.second)%MOD)%MOD;
        }
        return dp[maxMove][r][c] = paths;
    }
    
    int bottomUp(int m, int n, int maxMove, int r, int c)
    {
        int cache[51][51][51];
        memset(cache,0,sizeof(cache));
        for(int move = 1; move<=maxMove; move++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(auto &dir:dirs)
                    {
                        if(!isValid(i+dir.first,j+dir.second,m,n))
                            cache[move][i][j]++;
                        else
                        {
                            cache[move][i][j] = (cache[move][i][j] + cache[move-1][i+dir.first][j+dir.second])%MOD;
                        }
                    }
                }
            }
        }
        return cache[maxMove][r][c];
    }
    
public:
    int findPaths(int m, int n, int maxMove, int r, int c) {
        memset(dp,-1,sizeof(dp));
        return bottomUp(m,n,maxMove,r,c);
    }
};