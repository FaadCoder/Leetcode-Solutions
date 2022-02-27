class Solution {
    int dp[51][51];
    int mcm(vector<int>& values,int i,int j)
    {
        if(i+1==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res = INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            res = min(res,values[i]*values[k]*values[j] + mcm(values,i,k) + mcm(values,k,j));
        }
        return dp[i][j] = res;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return mcm(values,0,values.size()-1);
    }
};