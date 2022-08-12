class Solution {
public:
    //just divide the rectangle after using nxn tile in shown 3 ways in ps description
    int dp[14][14];
    int sol(int n, int m){
        if(n>m)swap(n,m);
        if(n==0 || m==0)return 0;
        if(n==m)return 1;
        if(n==1)return m;
        if(m==1)return n;
        if(dp[n][m]!=-1)return dp[n][m];
        int ans=1e9;
        for(int k=1;k<=n;k++){
            //1st type of orientation
            int temp=1+sol(m-k,n)+sol(k,n-k);
            ans=min(ans,temp);
            //2nd type of orientation
            int temp2=1+sol(k,m-k)+sol(n-k,m);
            ans=min(ans,temp2);
            //3rd orientation where we place two sqaure simultaneously as in 3rd example
            //k+k2<m because if we take k+k2=m then such cases have been covered above
            for(int k2=n-k+1;k2<n && k2+k<m;k2++){
                int temp3=2+sol(n-k,m-k2)+sol(n-k2,m-k) + sol(k2-(n-k),(m-k)-k2);
                ans=min(ans,temp3);
            }
        }
        return dp[n][m]=ans;
    }
    int tilingRectangle(int n, int m) {
        memset(dp,-1,sizeof dp);
        return sol(n,m);
    }
};