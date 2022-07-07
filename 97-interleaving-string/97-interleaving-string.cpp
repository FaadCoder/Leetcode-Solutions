class Solution
{
    int dp[102][102];
    private:
        bool isInterleaveHelper(string &s1, string &s2, string &s3, int i = 0, int j = 0) 
        {
            if(i>=s1.length() and j>=s2.length() and i+j>=s3.length())
                return true;
            if(i+j>=s3.length())
                return false;
                
            if(dp[i][j]!=-1)
                return dp[i][j];
            
            bool first = (s1[i]==s3[i+j] and isInterleaveHelper(s1,s2,s3,i+1,j));
            bool second = (s2[j]==s3[i+j] and isInterleaveHelper(s1,s2,s3,i,j+1));
            
             return dp[i][j]=(first or second);
        }

    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            memset(dp,-1,sizeof(dp));
            return isInterleaveHelper(s1,s2,s3);
        }
};