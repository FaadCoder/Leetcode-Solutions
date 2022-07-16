class Solution {
    const int MOD = 1e9+7;
    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int dp[51][51][51];
    
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
public:
    int findPaths(int m, int n, int maxMove, int r, int c) {
        memset(dp,-1,sizeof(dp));
        return findPathsHelper(m,n,maxMove,r,c);
    }
};