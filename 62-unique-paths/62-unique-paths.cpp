class Solution {
    unordered_map<int,unordered_map<int,int>> dp;
public:
    int uniquePaths(int m, int n) {
        if(m<=0 or n<=0)
            return 0;
        if(m==1 and n==1)
            return 1;
        if(dp.count(m) and dp[m].count(n))
            return dp[m][n];
        return dp[m][n] = uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};